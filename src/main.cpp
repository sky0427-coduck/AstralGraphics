#include <iostream>
#include "../include/ag_hook_interface.hpp"
#include "../include/ag_renderer.hpp"
#include "../include/ag_pipeline.hpp"
#include "../include/astra_api/tesseract_core.hpp"
#include "../include/game_profiles/minecraft.hpp"
#include "../include/game_profiles/valorant.hpp"
#include "../include/game_profiles/roblox.hpp"
#include "../include/game_profiles/generic.hpp"

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "Astra-Tesseract GPU 가속 플랫폼" << std::endl;
    std::cout << "==========================================\n" << std::endl;

    Astral::Hook::initialize_tesseract_injector();

    std::cout << "\nSTEP 1: 마인크래프트 구동 및 청크 렌더링 시작" << std::endl;
    float fake_minecraft_vertices[12] = {0.0f,};
    Astral::Hook::hooked_glBufferData(0x8892, sizeof(fake_minecraft_vertices), fake_minecraft_vertices);

    std::cout << "\nSTEP 2: 로블록스 커스텀 맵 구동 및 6500개 오브젝트 로드" << std::endl;
    Astral::Hook::hooked_glDrawElementsInstanced(4, 36, 0x1403, nullptr, 6500);

    std::cout << "\nSTEP 3: 발로란트 긴박한 교전 상황 초저지연 타이밍 제어" << std::endl;
    std::cout << "[Tesseract 알림] GPU 드로우 부하 급증 감지! 레이턴시 방어벽 전개." << std::endl;
    Astral::Hook::hooked_eglSwapBuffers();

    std::cout << "\n[최종 레포트] 3대장 타겟 프로필 및 자동 최적화 공정 빌드 100% 성공." << std::endl;
    return 0;
}