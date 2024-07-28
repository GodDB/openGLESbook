//
// Created by beom.93 on 7/28/24.

#include "Camera2.h"

void Camera2::setEye(const glm::vec3 &inEye) {
    this->eye = inEye;
    calculateViewMatrix();
}

void Camera2::setAt(const glm::vec3 &inAt) {
    this->at = inAt;
    calculateViewMatrix();
}

void Camera2::setUp(const glm::vec3 &inUp) {
    this->up = inUp;
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

void Camera2::calculateViewMatrix() {
    viewMatrix = glm::lookAt(eye, at, up);
}

void Camera2::calculateProjMatrix() {
    projMatrix = glm::perspective(fovy, aspect, zNear, zFar);
}
//
