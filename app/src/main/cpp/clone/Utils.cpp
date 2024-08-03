//
// Created by beom.93 on 8/2/24.
//
#include "Utils.h"

vec3 Utils::getNormalDeviceCoord(float x, float y, float width, float height) {
    float ndcX = (2.0f * x) / width - 1.0f;
    float ndcY = 1.0f - (2.0f * y) / height;
    return vec3(ndcX, ndcY, -1.0);
}

void Utils::printVec3(vec3 vec) {
    string a = to_string(vec.x) + " " + to_string(vec.y) + " " + to_string(vec.z);
    LOG_PRINT_ERROR(a.c_str());
}

void Utils::printVec4(vec4 vec) {
    string a = to_string(vec.x) + " " + to_string(vec.y) + " " + to_string(vec.z) + " " + to_string(vec.w);
    LOG_PRINT_ERROR(a.c_str());
}
