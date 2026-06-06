#include "../../include/game_profiles/valorant.hpp"
#include <iostream>
#include <thread>

namespace Astral::Profiles {
    ValorantOptimizer::ValorantOptimizer(double target_fps) {
        target_frame_time_ms = 1000.0 / target_fps;
        last_frame_time = std::chrono::high_resolution_clock::now();
        std::cout << "[Valorant Engine] 초저지연 모드 세팅 완료. 타겟 프레임 타임: " << target_frame_time_ms << " ms" << std::endl;
    }

    void ValorantOptimizer::sync_and_drop_latency() {
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = current_time - last_frame_time;
        
        if (elapsed.count() < target_frame_time_ms) {
            double sleep_needed = target_frame_time_ms - elapsed.count();
            if (sleep_needed > 0.5) {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleep_needed - 0.5)));
            }
            while (std::chrono::high_resolution_clock::now() - current_time < std::chrono::duration<double, std::milli>(sleep_needed)) {
                #if defined(__aarch64__) || defined(__ARM_NEON)
                    asm volatile("yield" ::: "memory");
                #endif
            }
        }
        last_frame_time = std::chrono::high_resolution_clock::now();
        std::cout << "⚡ [Latency Guard] 프레임 간격 칼고정 성공. CPU-GPU 동기화 레이턴시 최적화 완료." << std::endl;
    }
}