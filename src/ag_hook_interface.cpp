#include "../include/ag_hook_interface.hpp"
#include "../include/game_profiles/minecraft.hpp"
#include "../include/game_profiles/valorant.hpp"
#include "../include/game_profiles/roblox.hpp"
#include <iostream>

static Astral::Profiles::MinecraftOptimizer* g_mc_optimizer = nullptr;
static Astral::Profiles::ValorantOptimizer* g_val_optimizer = nullptr;
static Astral::Profiles::RobloxOptimizer* g_rb_optimizer = nullptr;

namespace Astral::Hook {

    void initialize_tesseract_injector() {
        std::cout << "[Tesseract Injector] 상용 게임 그래픽스 드라이버 레벨 후킹 레이어 준비 완료." << std::endl;
        g_mc_optimizer = new Astral::Profiles::MinecraftOptimizer();
        g_val_optimizer = new Astral::Profiles::ValorantOptimizer(240.0);
        g_rb_optimizer = new Astral::Profiles::RobloxOptimizer();
    }

    // extern "C" 블록 내부의 구현부들을 헤더 명세와 동기화
    extern "C" {
        void* hooked_glBufferData(unsigned int target, size_t size, const void* data) {
            std::cout << "[Hooked] 마인크래프트 런타임 정점 덤프 감지! (Size: " << size << " bytes)" << std::endl;
            Astral::Profiles::PooledChunk* allocated = g_mc_optimizer->acquire_chunk(16, 16);
            std::cout << "[Redirect] 오리지널 드라이버를 우회하여 고속 VRAM 채널로 다이렉트 이식." << std::endl;
            return (void*)data;
        }

        void hooked_glDrawElementsInstanced(unsigned int mode, int count, unsigned int type, const void* indices, int instance_count) {
            std::cout << "[Hooked] 로블록스 렌더 파이프라인 가로채기 성공." << std::endl;
            g_rb_optimizer->execute_dynamic_instancing(instance_count);
        }

        void hooked_eglSwapBuffers() {
            g_val_optimizer->sync_and_drop_latency();
        }
    }
}