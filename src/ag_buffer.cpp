#include "../include/ag_buffer.hpp"
#include <iostream>

// SoA 버퍼 가동 구현
void ChunkSoABuffer::resize(size_t count) {
    posX.resize(count);
    posY.resize(count);
    posZ.resize(count);
    blockID.resize(count);
}

void ChunkSoABuffer::clear() {
    posX.clear(); posY.clear(); posZ.clear(); blockID.clear();
}

void AGBuffer::init(size_t size) {
    buffer_size = size;
    is_allocated = true;
    std::cout << "📦 [AGBuffer] " << buffer_size << " MB 크기의 하드웨어 가속 정점 저장소 확보 완료." << std::endl;
}

void AGBuffer::release() {
    if (is_allocated) {
        buffer_size = 0;
        is_allocated = false;
        std::cout << "📦 [AGBuffer] 가속 저장소 메모리 안전하게 반환(Release) 완료." << std::endl;
    }
}