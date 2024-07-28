//
// Created by beom.93 on 7/28/24.
//

#ifndef OPENGLESBOOK_HELLOTEAPOTCLONE_H
#define OPENGLESBOOK_HELLOTEAPOTCLONE_H

#include "clone/BaseScene.h"

class HelloTeapotClone : public BaseScene {
protected:
    void start() override;
    void update(const float deltaTime) override;
};

#endif //OPENGLESBOOK_HELLOTEAPOTCLONE_H
