cmake_minimum_required(VERSION 4.2)
project(AstralGraphics VERSION 1.0.0 LANGUAGES CXX)

# [C++23 표준 강제 활성화!]
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 헤더 파일 위치 알려주기
include_directories(include)

# 빌드할 소스 파일들 등록
add_executable(AstralGraphics
    src/main.cpp
    src/ag_buffer.cpp
    src/ag_pipeline.cpp
)