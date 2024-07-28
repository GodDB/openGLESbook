//
// Created by beom.93 on 7/28/24.
//

#ifndef OPENGLESBOOK_CAMERA2_H
#define OPENGLESBOOK_CAMERA2_H

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

class Camera2 {
public:
    // 카메라 위치
    void setEye(const glm::vec3 &inEye);
    // 카메라 초점
    void setAt(const glm::vec3 &inAt);
    // 카메라 상단 벡터
    void setUp(const glm::vec3 &inUp);
    // y축 시야각
    void setFovy(const float inFovy);
    // z축 카메라 시작점
    void setZNear(const float inNear);
    // z축 카메라 끝점
    void setZFar(const float inFar);
    // 가로 세로 비
    void setAspect(const float inAspect);

    glm::vec3& getEye() {
        return eye;
    }
    glm::vec3& getAt() {
        return at;
    }

    glm::vec3& getUp() {
        return up;
    }

    glm::mat4 &getViewMatrix() {
        return viewMatrix;
    }
    glm::mat4 &getProjMatrix() {
        return projMatrix;
    }

private:
    void calculateViewMatrix();
    void calculateProjMatrix();

    glm::vec3 eye{0.0f};
    glm::vec3 at{0.0f};
    glm::vec3 up{0.0f, 1.0f, 0.0f};
    float fovy{glm::radians(60.0f)};
    float aspect{1.0f};
    float zNear{5.0f};
    float zFar{300.0f};
    glm::mat4 viewMatrix{1.0f};
    glm::mat4 projMatrix{1.0f};
};

#endif //OPENGLESBOOK_CAMERA2_H
