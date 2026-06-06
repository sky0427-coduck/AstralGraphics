#ifndef AG_HOOK_INTERFACE_HPP
#define AG_HOOK_INTERFACE_HPP

#include <cstddef>

namespace Astral::Hook {
    // Tesseract 인젝터 및 가속기 메모리 풀 초기화
    void initialize_tesseract_injector();

    // C++ 컴파일러의 이름 꼬임(Mangling)을 방지하고 상용 게임 API와 다이렉트 링크하기 위한 규격
    extern "C" {
        void* hooked_glBufferData(unsigned int target, size_t size, const void* data);
        void hooked_glDrawElementsInstanced(unsigned int mode, int count, unsigned int type, const void* indices, int instance_count);
        void hooked_eglSwapBuffers();
    }
}

#endif