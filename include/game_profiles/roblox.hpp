#ifndef ROBLOX_HPP
#define ROBLOX_HPP

#include <vector>
#include <cstddef>

namespace Astral::Profiles {
    struct InstanceTransform {
        float matrix[16]; 
    };

    class RobloxOptimizer {
    private:
        std::vector<InstanceTransform> instancing_buffer;
        const size_t MAX_INSTANCE_BATCH = 8192;

    public:
        RobloxOptimizer();
        void execute_dynamic_instancing(size_t object_count);
    };
}

#endif