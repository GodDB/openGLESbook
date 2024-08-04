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
    // y축 시야각
    void setFovy(const float inFovy);
    // z축 카메라 시작점
    void setZNear(const float inNear);
    // z축 카메라 끝점
    void setZFar(const float inFar);
    // 가로 세로 비
    void setAspect(const float inAspect);

    void setYaw(float rotate);

    void setPitch(float rotate);

    void setRoll(float rotate);

    glm::vec3& getEye() {
        return eye;
    }

    glm::vec3& getUp() {
        return up;
    }

    float getPitch() {
        return pitch;
    }

    float getYaw() {
        return yaw;
    }

    float getRoll() {
        return roll;
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
    void calculateRotate();

    // https://sidvind.com/wiki/Yaw,_pitch,_roll_camera
    float pitch = glm::radians(0.0f) ; // rotate x (radian)
    float yaw = glm::radians(-90.0f); // rotate y (radian)
    float roll = glm::radians(0.0f) ; // rotate z (radian)

    glm::vec3 eye{0.0f};
    glm::vec3 up{0.0f, 0.0f, 0.0f};
    glm::vec3 front = glm::normalize(glm::vec3(0.0, 0.0, 0.0));
    glm::vec3 right = glm::normalize(glm::cross(front, up));
    float fovy{glm::radians(60.0f)};
    float aspect{1.0f};
    float zNear{5.0f};
    float zFar{300.0f};
    glm::mat4 viewMatrix{1.0f};
    glm::mat4 projMatrix{1.0f};
};

#endif //OPENGLESBOOK_CAMERA2_H
