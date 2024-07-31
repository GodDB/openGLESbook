//
// Created by beom.93 on 7/31/24.
//

#ifndef OPENGLESBOOK_PHONGLIGHTINGCLONE_H
#define OPENGLESBOOK_PHONGLIGHTINGCLONE_H

#include "clone/BaseScene.h"
#include "clone/Texture2.h"
#include "clone/Light2.h"

class PhongLightingClone : public BaseScene {

public:
    void start() override;
    void update(const float deltaTime) override;

private:
    Texture2 texture{"colorMap"};
    Light2 light{};
};

#endif //OPENGLESBOOK_PHONGLIGHTINGCLONE_H
