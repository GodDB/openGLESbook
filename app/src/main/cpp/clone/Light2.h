//
// Created by beom.93 on 7/31/24.
//

#ifndef OPENGLESBOOK_LIGHT2_H
#define OPENGLESBOOK_LIGHT2_H

#include "global.h"
#include "Camera2.h"

class Light2 {

public:
    void update(GLuint programId, Camera2& camera);

private:

    // light
    glm::vec3 light_diffuse{ 0.9f };
    glm::vec3 light_specular { 1.0f};
    glm::vec3 light_ambient { 0.2f };
    // emit은 light가 없음

    glm::vec3 light_direction { 1.0f };

    // material
    // diffuse는 텍스쳐에서 가져옴
    glm::vec3 material_specular { 1.0f };
    glm::vec3 material_ambient { 0.2f };
    glm::vec3 materail_emit { 0.0f };

    float shininess { 3.0f };
};

#endif //OPENGLESBOOK_LIGHT2_H
