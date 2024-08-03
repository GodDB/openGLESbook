//
// Created by beom.93 on 7/28/24.
//

#ifndef OPENGLESBOOK_BASESCENE_H
#define OPENGLESBOOK_BASESCENE_H


#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/log.h>
#include <GLES3/gl32.h>
#include <GLES3/gl3ext.h>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <regex>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

#include "utility/asset.h"
#include "utility/input.h"
#include "Camera2.h"
#include "Texture2.h"
#include "Utils.h"

#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, "godgod", __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, "godgod", __VA_ARGS__)

class BaseScene {
public:
    void run(const float deltaTime);
    virtual ~BaseScene() {
        delete camera2;
    }
protected:
    virtual void start() = 0;

    virtual void update(const float deltaTime) = 0;

    void setupShader(const GLenum shaderType, const std::string &source);

    void setupProgram();

    void setupVertexBuffer(const ObjData &objData);

    void setupUniform();

    void draw();

    Camera2 *camera2 = new Camera2();

    GLuint vertexShaderId{0};
    GLuint fragmentShaderId{0};
    GLuint programId{0};
    GLsizei count{0};
    GLuint vbo{0};
    GLuint ibo{0};

    GLuint worldUniformId{0};
    GLuint viewUniformId{0};
    GLuint projUniformId{0};

private:
    void enableZBuffering() const;

    void setColorMaskOn() const;

    void setColorMaskOff() const;

    void setViewportToScreen() const;

    void setViewportToTexture() const;

    void clearScreenAll() const;

    void clearScreenColor() const;

    void clearScreenDepth() const;

    void setPatchVertices(int vertices) const;

    bool isStarted{false};
};

#endif //OPENGLESBOOK_BASESCENE_H
