#ifndef AG_BUFFER_HPP
#define AG_BUFFER_HPP

#include <cstddef> // size_t를 쓰기 위해 필요함!

// 우리가 정의한 새로운 구조체 자료형 'AGBuffer'
struct AGBuffer {
    void* raw_data       = nullptr; // 쌩 메모리 주소판 (& 기호로 채워질 녀석)
    std::size_t total_size   = 0;       // 이 버퍼의 총 크기 (바이트 단위)
    std::size_t allocated_ptr = 0;       // 현재 메모리를 어디까지 썼는지 가리키는 주소 오프셋

    // 하드웨어 메모리를 처음 방 분배(할당)하는 함수
    bool init(std::size_t bytes);

    // 버퍼에 데이터를 복사해서 밀어넣는 함수
    bool write(const void* src_data, std::size_t bytes);

    // 다 쓰고 메모리 OS에 반납하는 함수
    void release();
};

#endif