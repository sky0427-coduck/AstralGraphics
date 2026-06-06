#ifndef VALORANT_HPP
#define VALORANT_HPP

#include <chrono>

namespace Astral::Profiles {
    class ValorantOptimizer {
    private:
        std::chrono::high_resolution_clock::time_point last_frame_time;
        double target_frame_time_ms;

    public:
        ValorantOptimizer(double target_fps = 240.0);
        void sync_and_drop_latency();
    };
}

#endif