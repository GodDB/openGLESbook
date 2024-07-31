//
// Created by beom.93 on 7/31/24.
//

#include "Light2.h"

void Light2::update(GLuint programId, Camera2& camera) {
    //to vs
    GLuint eye = glGetUniformLocation(programId, "eyePos");
    glUniform3fv(eye, 1, (const GLfloat*) &camera.getEye());

    // to fs
    GLuint matSpec = glGetUniformLocation(programId, "matSpec");
    GLuint matAmbi = glGetUniformLocation(programId, "matAmbi");
    GLuint matEmit = glGetUniformLocation(programId, "matEmit");
    GLuint shin = glGetUniformLocation(programId, "matSh");
    GLuint direction = glGetUniformLocation(programId, "lightDir");

    GLuint srcDiff = glGetUniformLocation(programId, "srcDiff");
    GLuint srcSpec = glGetUniformLocation(programId, "srcSpec");
    GLuint srcAmbi = glGetUniformLocation(programId, "srcAmbi");

    glUniform3fv(matSpec, 1, (const GLfloat*) &material_specular);
    glUniform3fv(matAmbi, 1, (const GLfloat*) &material_ambient);
    glUniform3fv(matEmit, 1, (const GLfloat*) &materail_emit);

    glUniform1fv(shin, 1, &shininess);
    glUniform3fv(direction, 1,(const GLfloat*) &light_direction);

    glUniform3fv(srcDiff, 1, (const GLfloat*) &light_diffuse);
    glUniform3fv(srcSpec, 1, (const GLfloat*) &light_specular);
    glUniform3fv(srcAmbi, 1, (const GLfloat*) &light_ambient);


}
