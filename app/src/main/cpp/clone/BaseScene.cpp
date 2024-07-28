//
// Created by beom.93 on 7/28/24.
//

#include "clone/BaseScene.h"

void BaseScene::run(const float deltaTime) {
    if (!isStarted) {
        // initial setting
        glEnable(GL_DEPTH_TEST);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        glViewport(0, 0, Screen::getWidth(), Screen::getHeight());

        start();
        isStarted = true;
    }
    update(deltaTime);
}

void BaseScene::setupProgram() {
    LOG_D("createProgram");

    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glUseProgram(programId);
}

void BaseScene::setupShader(const GLenum shaderType, const std::string &source) {
    LOG_D("create shader");
    const GLchar *glSource = source.c_str();

    switch (shaderType) {
        case GL_VERTEX_SHADER:
            LOG_D("create shader - GL_VERTEX_SHADER");
            vertexShaderId = glCreateShader(shaderType);
            glShaderSource(vertexShaderId, 1, &glSource, NULL);
            glCompileShader(vertexShaderId);
            break;
        case GL_FRAGMENT_SHADER:
            LOG_D("create shader - GL_FRAGMENT_SHADER");
            fragmentShaderId = glCreateShader(shaderType);
            glShaderSource(fragmentShaderId, 1, &glSource, NULL);
            glCompileShader(fragmentShaderId);
            break;
        default:
            LOG_D("create shader - else");
            break;
    }
}

void BaseScene::setupVertexBuffer(const ObjData &objData) {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
            GL_ARRAY_BUFFER,
            objData.vertices.size() * sizeof(Vertex),
            objData.vertices.data(),
            GL_STATIC_DRAW
    );

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            objData.indices.size() * sizeof(Index),
            objData.indices.data(),
            GL_STATIC_DRAW
    );

    // set element count
    count = (GLsizei) objData.indices.size();

    // setup position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex),
            (const GLvoid *) offsetof(Vertex, pos)
    );

    // setup normal vector
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex),
            (const GLvoid *) offsetof(Vertex, nor)
    );

    // setup texture coord
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(
            2,
            2,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex),
            (const GLvoid *) offsetof(Vertex, tex)
    );
}

void BaseScene::setupUniform() {
    worldUniformId = glGetUniformLocation(programId, "worldMat");
    viewUniformId = glGetUniformLocation(programId, "viewMat");
    projUniformId = glGetUniformLocation(programId, "projMat");
}

void BaseScene::draw() {
    // clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void BaseScene::enableZBuffering() const {
    // enable depth test (z-buffering)
    glEnable(GL_DEPTH_TEST);
}

void BaseScene::setColorMaskOn() const {
    // set color mask on
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
}

void BaseScene::setColorMaskOff() const {
    // set color mask off
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
}

void BaseScene::setViewportToScreen() const {
    // set viewport to fit screen size
    glViewport(0, 0, Screen::getWidth(), Screen::getHeight());
}

void BaseScene::setViewportToTexture() const {
    // set viewport to fit default map size
    glViewport(0, 0, SHADOW_MAP_SIZE, SHADOW_MAP_SIZE);
}

void BaseScene::clearScreenAll() const {
    // clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void BaseScene::clearScreenColor() const {
    // clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);
}

void BaseScene::clearScreenDepth() const {
    // clear depth buffer
    glClear(GL_DEPTH_BUFFER_BIT);
}

void BaseScene::setPatchVertices(int vertices) const {
    // set patch vertices
    glPatchParameteri(GL_PATCH_VERTICES, vertices);
}
