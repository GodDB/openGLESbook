//
// Created by beom.93 on 7/31/24.
//

#include "Texture2.h"

Texture2::Texture2(std::string uniformName) {
    this->uniformName = uniformName;
}
void Texture2::update(const TexData &tex) {
    setupTexture();
    updateTexture(tex);
    updateMipmap();
}

void Texture2::active(const GLuint programId) {
    glActiveTexture(GL_TEXTURE0); // 텍스처 유닛 0 활성화
    glBindTexture(GL_TEXTURE_2D, texId);

    GLuint uniformId = glGetUniformLocation(programId, uniformName.c_str());

    // 텍스처 유니폼 설정
    glUniform1i(uniformId, 0);
}

void Texture2::setupTexture() {
    glGenTextures(1, &texId);
}

void Texture2::updateTexture(const TexData &tex) {
    glBindTexture(
            GL_TEXTURE_2D,
            texId
            );


    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            tex.width,
            tex.height,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            tex.texels.data()
    );
}

void Texture2::updateMipmap() {
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

