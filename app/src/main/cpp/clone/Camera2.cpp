//
// Created by beom.93 on 7/28/24.

#include "Camera2.h"

void Camera2::setEye(const glm::vec3 &inEye) {
    this->eye = inEye;
    calculateRotate();
    calculateViewMatrix();
}

void Camera2::setPitch(float rotate) {
    this->pitch = glm::radians(rotate);
    calculateRotate();
    calculateViewMatrix();
}

void Camera2::setYaw(float rotate) {
    this->yaw = glm::radians(rotate);
    calculateRotate();
    calculateViewMatrix();
}

void Camera2::setRoll(float rotate) {
    this->roll = glm::radians(rotate);
    calculateRotate();
    calculateViewMatrix();
}

void Camera2::setFovy(const float inFovy) {
    this->fovy = inFovy;
    calculateProjMatrix();
}

void Camera2::setZFar(const float inFar) {
    this->zFar = inFar;
    calculateProjMatrix();
}

void Camera2::setZNear(const float inNear) {
    this->zNear = inNear;
    calculateProjMatrix();
}

void Camera2::setAspect(const float inAspect) {
    this->aspect = inAspect;
    calculateProjMatrix();
}

void Camera2::calculateRotate() {

    // 카메라의 방향 벡터 (Forward)
    front.x = cos(yaw) * cos(pitch);
    front.y = sin(pitch);
    front.z = sin(yaw) * cos(pitch);

    // 카메라의 오른쪽 벡터 (Right)
    right.x = cos(yaw) * sin(pitch) * sin(roll) - sin(yaw) * cos(roll);
    right.y = cos(pitch) * sin(roll);
    right.z = sin(yaw) * sin(pitch) * sin(roll) + cos(yaw) * cos(roll);

    // 카메라의 위쪽 벡터 (Up)
    up.x = cos(yaw) * sin(pitch) * cos(roll) + sin(yaw) * sin(roll);
    up.y = cos(pitch) * cos(roll);
    up.z = sin(yaw) * sin(pitch) * cos(roll) - cos(yaw) * sin(roll);

}

void Camera2::calculateViewMatrix() {
    viewMatrix = glm::lookAt(eye, eye + front, up);
}

void Camera2::calculateProjMatrix() {
    projMatrix = glm::perspective(fovy, aspect, zNear, zFar);
}


//
