cmake_minimum_required(VERSION 4.2)
project(AstralGraphics VERSION 1.0.0 LANGUAGES CXX)

# [C++23 표준 강제 활성화!]
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    message(STATUS "[Astra Detect] ARM 64-bit (aarch64) 감지! NEON이 기본 탑재된 하드웨어입니다.")
    # 64비트는 이미 NEON이 켜져 있으므로 -mfpu=neon을 쓰면 에러가 남! 아무것도 안 해도 됨!
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
    message(STATUS "[Astra Detect] ARM 32-bit 감지! 구형 NEON 가속을 명시적으로 켭니다.")
    add_compile_options(-mfpu=neon)
else()
    message(STATUS "[Astra Detect] x86-64 아키텍처 감지! AVX2 가속을 활성화합니다.")
    add_compile_options(-mavx2 -msse4.2)
endif()

include_directories(include)
file(GLOB SOURCES "src/*.cpp", "src/game_profiles/*.cpp")
add_executable(AstralGraphics ${SOURCES})

