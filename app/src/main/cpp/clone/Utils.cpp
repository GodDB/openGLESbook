//
// Created by beom.93 on 8/2/24.
//
#include "Utils.h"

vec3 Utils::getNormalDeviceCoord(float x, float y, float width, float height) {
    // compute vector
    glm::vec3 vector(
            2.0f * x / width - 1.0f,
            2.0f *y /height- 1.0f,
            0.0f);

    // flip y-axis
    vector.y = -vector.y;

    // compute z-coordinate
    const float square = vector.x * vector.x + vector.y * vector.y;
    if (square < 1.0f) vector.z = sqrtf(1.0f - square);
    else vector = glm::normalize(vector);

    // return vector
    return vector;
}

void Utils::printVec3(vec3 vec) {
    string a = to_string(vec.x) + " " + to_string(vec.y) + " " + to_string(vec.z);
    LOG_PRINT_ERROR(a.c_str());
}

void Utils::printVec4(vec4 vec) {
    string a = to_string(vec.x) + " " + to_string(vec.y) + " " + to_string(vec.z) + " " + to_string(vec.w);
    LOG_PRINT_ERROR(a.c_str());
}

void Utils::printMat3(glm::mat3 mat) {
    string a = "";

    // 행렬 요소 출력
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            a += to_string(mat[i][j])  + "  ";
        }
        a += "\n";
    }
    LOG_PRINT_ERROR(a.c_str());
}

void Utils::printMat4(glm::mat4 mat) {
    string a = "";

    // 행렬 요소 출력
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            LOG_PRINT_ERROR("%s  %s",to_string(i).c_str(), to_string(j).c_str());
            a += to_string(mat[i][j]) + "  ";
        }
        a += "\n";
    }
    LOG_PRINT_ERROR(a.c_str());
}

