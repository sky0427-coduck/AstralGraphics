#ifndef TESSERACT_CORE_HPP
#define TESSERACT_CORE_HPP

#include <iostream>
#include <string>
#include <cstddef>

namespace Astra {
    namespace Tesseract {
        enum class EngineMode {
            Developer_SDK,
            Player_Runtime
        };

        inline void print_engine_status(EngineMode mode) {
#if defined(__aarch64__) || defined(__ARM_NEON)
            std::string arch = "ARM 64-bit NEON (라즈베리파이 극한 최적화)";
#elif defined(__AVX2__)
            std::string arch = "x86-64 AVX2 (PC 하드웨어 가속)";
#else
            std::string arch = "Generic CPU";
#endif

            if (mode == EngineMode::Developer_SDK) {
                std::cout << "🛠️ [Astra SDK] 개발자 모드 활성화 | 가속 아키텍처: " << arch << std::endl;
            } else {
                std::cout << "🎮 [Tesseract] 플레이어 런타임 구동 | 최적화 아키텍처: " << arch << std::endl;
            }
        }
    }
}

// =================================================================
// [Astra 고유 규격] 외부 언어(Java, Python) 및 C++ 개발자 통합 연동 포트
// =================================================================
extern "C" {
    // 1. Developer_SDK 모드용: 가속 버퍼 풀 및 행렬 압축 파이프라인 API
    void* astra_tesseract_create_buffer(size_t element_count);
    void astra_tesseract_release_buffer(void* buffer_ptr);
    void astra_tesseract_compress_pipeline(float* matrix_array, size_t count);

    // 2. 공통 커널: 초저지연 프레임 제어 및 타이머 동기화 API
    void astra_tesseract_lock_latency(double target_fps);
}

#endif