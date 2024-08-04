//
// Created by beom.93 on 7/31/24.
//

#include "PhongLightingClone.h"

glm::mat4 worldMatrix{1};

void PhongLightingClone::start() {
    const ObjData &obj = AssetManager::readBinaryObject("teapot");

    const std::string vertex_source = AssetManager::readShader("phong_lighting_vs");
    BaseScene::setupShader(GL_VERTEX_SHADER, vertex_source);

    const std::string fragment_source = AssetManager::readShader("phong_lighting_fs");
    BaseScene::setupShader(GL_FRAGMENT_SHADER, fragment_source);

    BaseScene::setupProgram();

    BaseScene::setupVertexBuffer(obj);

    BaseScene::setupUniform();

    const TexData &tex = AssetManager::readTexture("brick_color");
    texture.update(tex);

    camera2->setAspect(
            (float) Screen::getWidth() / Screen::getHeight()
    );
    camera2->setEye(glm::vec3(0.0, 0.0f, 50.0f));
}

float temp_prev_x = 0.0f;
float temp_prev_y = 0.0f;

void PhongLightingClone::update(const float deltaTime) {

    if (Touch::getMotion() != Touch::Motion::UP && temp_prev_x != 0.0f && temp_prev_y != 0.0f) {
        if (temp_prev_x == Touch::getX() && temp_prev_y == Touch::getY()) return;
        /*      float deltaX = Touch::getNdcX();
              float deltaY = Touch::getNdcY();

              mat4 moveT = glm::translate(vec3(deltaX, -deltaY, 0.0));
              camera2->setEye(moveT * vec4(camera2->getEye(), 1.0));
              vec3 cameraAt = vec3(0.0, 0.0, -1.0);
              camera2->setAt(vec3(camera2->getEye().x, camera2->getEye().y, 0.0) + cameraAt);

              string msg = "delta x = " + to_string(deltaX) + "  delta y = " + to_string(deltaY);
              Utils::printVec3(camera2->getAt());
              Utils::printVec3(camera2->getEye());
              Utils::printVec3(camera2->getUp());
              LOG_E(msg.c_str());*/

        // arcball rotation

    /*    vec3 prev_ndc = Utils::getNormalDeviceCoord(temp_prev_x, temp_prev_y, Screen::getWidth(), Screen::getHeight());
        vec3 cur_ndc = Utils::getNormalDeviceCoord(Touch::getX(), Touch::getY(), Screen::getWidth(), Screen::getHeight());

        const float angle = glm::acos(glm::clamp(glm::dot(prev_ndc, cur_ndc), -1.0f, 1.0f));
        const vec3 rotateAxis = glm::inverse(mat3(camera2->getViewMatrix() * worldMatrix))
                                * glm::cross(prev_ndc, cur_ndc);

        mat4 rotateM = glm::rotate(angle, rotateAxis);
        worldMatrix = worldMatrix * rotateM;
        Utils::printMat4(camera2->getViewMatrix());

        Utils::printMat4(camera2->getViewMatrix());*/
        float xDelta = Touch::getNdcDeltaX();
        float yDelta = Touch::getNdcDeltaY();

        camera2->setYaw(glm::degrees(camera2->getYaw() + xDelta));
        camera2->setPitch(glm::degrees(camera2->getPitch() + yDelta));

    }

    temp_prev_x = Touch::getX();
    temp_prev_y = Touch::getY();

    if (Touch::getMotion() == Touch::Motion::UP) {
        temp_prev_x = 0.0f;
        temp_prev_y = 0.0f;
    }


    BaseScene::draw();

    const glm::mat4 &viewMatrix = camera2->getViewMatrix();
    const glm::mat4 &projMatrix = camera2->getProjMatrix();

    texture.active(programId);
    light.update(programId, *camera2);

    // update view matrix
    glUniformMatrix4fv(
            viewUniformId,
            1,
            GL_FALSE,
            glm::value_ptr(viewMatrix)
    );

    // update projection matrix
    glUniformMatrix4fv(
            projUniformId,
            1,
            GL_FALSE,
            glm::value_ptr(projMatrix)
    );

    glUniformMatrix4fv(
            worldUniformId,
            1,
            GL_FALSE,
            glm::value_ptr(worldMatrix)
    );

    glDrawElements(
            GL_TRIANGLES,
            count,
            GL_UNSIGNED_SHORT,
            0
    );
}
