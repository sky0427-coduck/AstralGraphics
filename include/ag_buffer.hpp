#ifndef AG_BUFFER_HPP
#define AG_BUFFER_HPP

#include <cstddef>
#include <vector>

// 💥 마인크래프트/로블록스 대량 보셀 및 오브젝트 처리를 위한 SoA 버퍼
struct alignas(32) ChunkSoABuffer {
    std::vector<float> posX;
    std::vector<float> posY;
    std::vector<float> posZ;
    std::vector<int> blockID;

    void resize(size_t count);
    void clear();
};

// 🛠️ 원래 작업하던 오리지널 AGBuffer 클래스 (링크 에러 방어)
struct AGBuffer {
    size_t buffer_size = 0;
    bool is_allocated = false;

    void init(size_t size);
    void release();
};

#endif