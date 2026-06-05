#include "../include/ag_pipeline.hpp"
#include <iostream>

bool AGPipeline::bake_pipeline() {
    std::cout << " [" << pipeline_name << "] 그래픽 파이프라인(공장) 굽기 시작..." << std::endl;
    
    // 세팅이 올바른지 체크하는 척(?)하는 로직
    if (pipeline_name.empty()) {
        return false;
    }

    std::cout << "하드웨어 토폴로지 및 뎁스 테스트 세팅 완료!" << std::endl;
    return true;
}

void AGPipeline::dump_states() const {
    std::cout << "\n--- Pipeline 상태 리포트 ---" << std::endl;
    std::cout << "이름: " << pipeline_name << std::endl;

    // [빈칸 1] is_topology_triangle이 true면 "삼각형(Triangle)", false면 "선(Line)"이라고 출력하게 만들어봐!
    if ( is_topology_triangle == true ) {
        std::cout << "조립 방식: 삼각형 (Triangle)" << std::endl;
    } else {
        std::cout << "조립 방식: 선 (Line)" << std::endl;
    }

    // [빈칸 2] enable_depth_test가 true면 "ON", false면 "OFF"를 출력하게 3항 연산자나 if문으로 채워봐!
    // 힌트: (조건문) ? "참일때" : "거짓일때" 구조를 써도 좋고, 그냥 if-else로 짜도 돼!
    std::cout << "뎁스 테스트(앞뒤 가리기): " << ( enable_depth_test == true ? "ON" : "OFF" ) << std::endl;
    std::cout << "--------------------------------\n" << std::endl;
}