#ifndef AG_RENDERER_HPP
#define AG_RENDERER_HPP

#include "ag_buffer.hpp"
#include "ag_pipeline.hpp"
#include <chrono>

struct AGRenderer {
    const AGPipeline* current_pipeline = nullptr;
    const AGBuffer* current_buffer   = nullptr;

    std::chrono::high_resolution_clock::time_point frame_start_time;
    double last_frame_time_ms = 0.0;

    void bind_pipeline(const AGPipeline* pipeline);
    void bind_buffer(const AGBuffer* buffer);
    void optimize_vertex_transformation(float* vertex_array, int count);

    void begin_frame();
    void draw();
    void end_frame();
};

#endif