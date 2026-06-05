#include "../include/ag_buffer.hpp"
#include <cstdlib>
#include <cstring>

// 윈도우, 맥, 리눅스(라즈비안) 컴파일러 억까를 완전히 부수는 무적 호환 매크로
#if defined(_MSC_VER) // 1. 윈도우 환경일 때
    #define portable_aligned_alloc(alignment, size) _aligned_malloc(size, alignment)
    #define portable_aligned_free(ptr) _aligned_free(ptr)
#else // 2. 리눅스(라즈비안), 맥 환경일 때
    // std::aligned_alloc 대신 컴파일러 버전을 안 타는 posix_memalign을 활용하는 래퍼 함수 생성
    inline void* portable_aligned_alloc(std::size_t alignment, std::size_t size) {
        void* ptr = nullptr;
        // 성공하면 0을 반환하고 ptr에 정렬된 메모리 주소를 채워줌
        if (posix_memalign(&ptr, alignment, size) != 0) {
            return nullptr;
        }
        return ptr;
    }
    #define portable_aligned_free(ptr) std::free(ptr)
#endif

// 1. 메모리 방을 나누는 배달 준비 단계
bool AGBuffer::init(std::size_t bytes) {
    total_size = bytes;
    allocated_ptr = 0;

    // 무적 호환 함수로 16바이트 정렬 할당!
    raw_data = portable_aligned_alloc(16, bytes);

    return (raw_data != nullptr);
}

// 2. 진짜 데이터를 버퍼 상자에 밀어 넣는 단계
bool AGBuffer::write(const void* src_data, std::size_t bytes) {
    if (allocated_ptr + bytes > total_size) return false;

    // 목적지 주소판 계산
    char* dest_address = (char*)raw_data + allocated_ptr;

    // 주소판에 데이터 복사
    std::memcpy(dest_address, src_data, bytes);

    allocated_ptr += bytes;
    return true;
}

// 3. 다 쓴 상자 OS에 반납하기
void AGBuffer::release() {
    if (raw_data != nullptr) {
        portable_aligned_free(raw_data);
        raw_data = nullptr;
    }
}