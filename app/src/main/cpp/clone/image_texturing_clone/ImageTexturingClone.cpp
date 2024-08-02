//
// Created by beom.93 on 7/31/24.
//

#include "ImageTexturingClone.h"


void ImageTexturingClone::start() {
    const ObjData &obj = AssetManager::readBinaryObject("teapot");

    const std::string vertex_source = AssetManager::readShader("image_texturing_vs");
    BaseScene::setupShader(GL_VERTEX_SHADER, vertex_source);

    const std::string fragment_source = AssetManager::readShader("image_texturing_fs");
    BaseScene::setupShader(GL_FRAGMENT_SHADER, fragment_source);

    BaseScene::setupProgram();

    BaseScene::setupVertexBuffer(obj);

    BaseScene::setupUniform();

    const TexData& tex = AssetManager::readTexture("brick_color");
    texture.update(tex);

    camera2->setAspect(
            (float) Screen::getWidth() / Screen::getHeight()
    );

    camera2->setEye(glm::vec3(30.0f));
}

void ImageTexturingClone::update(const float deltaTime) {
    BaseScene::draw();
    // rotate camera
    glm::quat quat = glm::angleAxis(deltaTime * glm::radians(60.0f), camera2->getUp());
    glm::mat4 mat = glm::mat4_cast(quat);

    camera2->setEye(
            mat * glm::vec4(camera2->getEye(), 1.0)
    );


    const glm::mat4 worldMatrix{1.0f};
    const glm::mat4 &viewMatrix = camera2->getViewMatrix();
    const glm::mat4 &projMatrix = camera2->getProjMatrix();

    texture.active(programId);

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
