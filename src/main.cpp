#include <iostream>
#include "../include/ag_buffer.hpp"
#include "../include/ag_pipeline.hpp" // 새 부품 추가!

struct Vertex {
    float x, y, z;
};

int main() {
    std::cout << "AstralGraphics Engine 가동 시작! (C++23)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // 1. [부품 1] 데이터 버퍼 박스 준비
    AGBuffer my_buffer;
    std::size_t required_size = sizeof(Vertex) * 2;
    if (my_buffer.init(required_size)) {
        std::cout << "[성공] 16바이트 정렬 메모리 버퍼 할당 완료!" << std::endl;
    }

    Vertex v1{1.0f, 2.0f, 3.0f};
    Vertex v2{4.0f, 5.0f, 6.0f};
    my_buffer.write(&v1, sizeof(Vertex));
    my_buffer.write(&v2, sizeof(Vertex));

    // 2. [부품 2] 그래픽 파이프라인(공장) 세팅 시작!
    AGPipeline my_pipeline;
    my_pipeline.pipeline_name = "Astral_Core_Pipeline";
    my_pipeline.is_topology_triangle = true; // 삼각형 모드로 조립!
    my_pipeline.enable_depth_test = true;    // 앞뒤 가리기 켜기!

    // 공장 가동 상태 검사 및 굽기(Bake)
    if (my_pipeline.bake_pipeline()) {
        // 네가 완성한 빈칸 함수 호출! 현재 공장 세팅 리포트 출력
        my_pipeline.dump_states();
    }

    // 3. 렌더링 가상 시뮬레이션
    std::cout << "[가상 렌더링] " << my_pipeline.pipeline_name 
              << " 공장이 버퍼의 데이터를 가져와 화면에 그리는 중..." << std::endl;
    
    Vertex* buffer_data_ptr = (Vertex*)my_buffer.raw_data;
    std::cout << ">> 그리는 중인 정점 1: (" << buffer_data_ptr[0].x << ", " << buffer_data_ptr[0].y << ")" << std::endl;

    // 4. 자원 반납
    my_buffer.release();
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "모든 컴포넌트 정상 작동 완료!" << std::endl;

    return 0;
}