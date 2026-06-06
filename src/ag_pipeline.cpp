#include <iostream>
#include "../include/ag_pipeline.hpp"

bool AGPipeline::bake_pipeline() {
    std::cout << "🏭 [" << pipeline_name << "] 그래픽 파이프라인(공장) 굽기 시작..." << std::endl;
    if (pipeline_name.empty()) return false;

    std::cout << " 하드웨어 토폴로지 및 뎁스 테스트 세팅 완료!" << std::endl;
    return true;
}

void AGPipeline::dump_states() const {
    std::cout << "\n--- Pipeline 상태 리포트 ---" << std::endl;
    std::cout << "이름: " << pipeline_name << std::endl;

    if (is_topology_triangle) {
        std::cout << "조립 방식: 삼각형 (Triangle)" << std::endl;
    } else {
        std::cout << "조립 방식: 선 (Line)" << std::endl;
    }

    std::cout << "뎁스 테스트(앞뒤 가리기): " << (enable_depth_test ? "ON" : "OFF") << std::endl;
    std::cout << "--------------------------------\n" << std::endl;
}