#ifndef AG_PIPELINE_HPP
#define AG_PIPELINE_HPP

#include <string>

// 그래픽 공장의 상태를 정의하는 구조체
struct AGPipeline {
    std::string pipeline_name = "DefaultPipeline";
    bool is_topology_triangle = true; // true면 삼각형으로 조립, false면 선으로 조립!
    bool enable_depth_test    = true; // 앞뒤 가리기(가려진 곳은 안 그리기) 기능 켤지 여부

    // 공장 가동 준비 (초기화 함수)
    bool bake_pipeline();

    // 이 공장의 현재 세팅 상태를 콘솔에 쫙 찍어주는 함수
    void dump_states() const;
};

#endif