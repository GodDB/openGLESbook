//
// Created by beom.93 on 7/31/24.
//

#ifndef OPENGLESBOOK_IMAGETEXTURINGCLONE_H
#define OPENGLESBOOK_IMAGETEXTURINGCLONE_H

#include "clone/BaseScene.h"
#include "clone/Texture2.h"

class ImageTexturingClone : public BaseScene {

public:
    void start() override;
    void update(const float deltaTime) override;

private:
    Texture2 texture { Texture2("colorMap") };

};

#endif //OPENGLESBOOK_IMAGETEXTURINGCLONE_H
