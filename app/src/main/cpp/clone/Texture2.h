//
// Created by beom.93 on 7/31/24.
//

#ifndef OPENGLESBOOK_TEXTURE2_H
#define OPENGLESBOOK_TEXTURE2_H

#include "global.h"

class Texture2 {

public:
    Texture2(std::string uniformName);
    void update(const TexData& tex);
    void active(const GLuint programId);


private:
    GLuint texId {0};
    std::string uniformName;

    void setupTexture();
    void updateTexture(const TexData& tex);
    void updateMipmap();
};

#endif //OPENGLESBOOK_TEXTURE2_H
