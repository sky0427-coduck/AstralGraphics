#ifndef MINECRAFT_HPP
#define MINECRAFT_HPP

#include "../ag_buffer.hpp"
#include <vector>

namespace Astral::Profiles {
    struct PooledChunk {
        ChunkSoABuffer buffer;
        bool is_active = false;
        int chunk_x = 0;
        int chunk_z = 0;
    };

    class MinecraftOptimizer {
    private:
        std::vector<PooledChunk> chunk_pool;
        const size_t MAX_POOL_SIZE = 256;

    public:
        MinecraftOptimizer();
        PooledChunk* acquire_chunk(int x, int z);
        void release_chunk(PooledChunk* chunk);
        void optimize_chunk_mesh(ChunkSoABuffer& chunk);
    };
}

#endif