#ifndef AG_PIPELINE_HPP
#define AG_PIPELINE_HPP

#include <string>

struct AGPipeline {
    std::string pipeline_name;
    bool is_topology_triangle = true;
    bool enable_depth_test = true;

    bool bake_pipeline();
    void dump_states() const;
};

#endif