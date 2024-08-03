//
// Created by beom.93 on 8/2/24.
//

#ifndef OPENGLESBOOK_UTILS_H
#define OPENGLESBOOK_UTILS_H

#include "global.h"

using namespace std;
using namespace glm;

class Utils {

public:
    static vec3 getNormalDeviceCoord(float x, float y, float width, float height);

    static void printVec3(vec3 vec);
    static void printVec4(vec4 vec);
};

#endif //OPENGLESBOOK_UTILS_H
