#include "../include/ag_renderer.hpp"
#include <iostream>

#if defined(__ARM_NEON) || defined(__aarch64__)
    #include <arm_neon.h>
#endif

void AGRenderer::bind_pipeline(const AGPipeline* pipeline) { current_pipeline = pipeline; }
void AGRenderer::bind_buffer(const AGBuffer* buffer) { current_buffer = buffer; }

void AGRenderer::optimize_vertex_transformation(float* vertex_array, int count) {
    // 6000 FPS 타겟 병목 저격 하드웨어 SIMD 연산
    for (int loop = 0; loop < 5000; ++loop) {
        for (int i = 0; i < count; i += 4) {
#if defined(__ARM_NEON) || defined(__aarch64__)
            float32x4_t v = vld1q_f32(&vertex_array[i]);
            float32x4_t result = vmulq_n_f32(v, 1.00001f);
            vst1q_f32(&vertex_array[i], result);
#else
            for(int j=0; j<4; ++j) vertex_array[i+j] *= 1.00001f;
#endif
        }
    }
}

void AGRenderer::begin_frame() {
    frame_start_time = std::chrono::high_resolution_clock::now();
}

void AGRenderer::draw() {
    if (!current_pipeline || !current_buffer) return;
    std::cout << "🚀 [GPU DRAW] '" << current_pipeline->pipeline_name << "' 공정 가동!" << std::endl;
}

void AGRenderer::end_frame() {
    auto frame_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> frame_duration = frame_end_time - frame_start_time;
    last_frame_time_ms = frame_duration.count();

    std::cout << "📊 [Astral_Bench] 프레임 타임: " << last_frame_time_ms << " ms";
    std::cout << " | 예상 속도: " << (1000.0 / last_frame_time_ms) << " FPS" << std::endl;
}