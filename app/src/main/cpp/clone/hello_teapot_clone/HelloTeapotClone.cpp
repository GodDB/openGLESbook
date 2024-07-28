//
// Created by beom.93 on 7/28/24.
//

#include "clone/hello_teapot_clone/HelloTeapotClone.h"


void HelloTeapotClone::start() {
    const ObjData &obj = AssetManager::readBinaryObject("teapot");

    const std::string vertex_source = AssetManager::readShader("hello_teapot_vs");
    BaseScene::setupShader(GL_VERTEX_SHADER, vertex_source);

    const std::string fragment_source = AssetManager::readShader("hello_teapot_fs");
    BaseScene::setupShader(GL_FRAGMENT_SHADER, fragment_source);

    BaseScene::setupProgram();

    BaseScene::setupVertexBuffer(obj);

    BaseScene::setupUniform();

    camera2->setAspect(
            (float) Screen::getWidth() / Screen::getHeight()
    );

    camera2->setEye(glm::vec3(30.0f));
}

void HelloTeapotClone::update(const float deltaTime) {
    BaseScene::draw();
    // rotate camera
    camera2->setEye(
            glm::rotate(deltaTime * glm::radians(60.0f), camera2->getUp()) * glm::vec4(camera2->getEye(), 1.0)
    );


    const glm::mat4 worldMatrix{1.0f};
    const glm::mat4 &viewMatrix = camera2->getViewMatrix();
    const glm::mat4 &projMatrix = camera2->getProjMatrix();

    // update world matrix
    glUniformMatrix4fv(
            worldUniformId,
            1,
            GL_FALSE,
            glm::value_ptr(worldMatrix)
    );

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

    glDrawElements(
            GL_TRIANGLES,
            count,
            GL_UNSIGNED_SHORT,
            0
    );
}




