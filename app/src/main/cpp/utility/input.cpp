#include "input.h"

int Screen::width = 1;
int Screen::height = 1;

void Screen::setWidth(const int width) {
    Screen::width = width;
}

void Screen::setHeight(const int height) {
    Screen::height = height;
}

int Screen::getWidth() {
    return width;
}

int Screen::getHeight() {
    return height;
}

Touch::Motion Touch::motion = Touch::Motion::UP;
float Touch::x = 0.0f;
float Touch::y = 0.0f;

float prev_x = 0.0f;
float prev_y = 0.0f;

void Touch::setMotion(const Touch::Motion motion) {
    Touch::motion = motion;
}

void Touch::setX(const float x) {
    prev_x = Touch::x;
    Touch::x = x;
}

void Touch::setY(const float y) {
    prev_y = Touch::y;
    Touch::y = y;
}

Touch::Motion Touch::getMotion() {
    return motion;
}

float Touch::getX() {
    return x;
}

float Touch::getY() {
    return y;
}

float Touch::getDeltaX() {
    return x - prev_x;
}

float Touch::getDeltaY() {
    return y - prev_y;
}

float Touch::getNdcX() {
    vec3 ndc = Utils::getNormalDeviceCoord(x, y, Screen::getWidth(), Screen::getHeight());
    return ndc.x;
}

float Touch::getNdcY() {
    vec3 ndc = Utils::getNormalDeviceCoord(x, y, Screen::getWidth(), Screen::getHeight());
    return ndc.y;
}

float Touch::getNdcDeltaX() {
    vec3 prev_ndc = Utils::getNormalDeviceCoord(prev_x, prev_y, Screen::getWidth(), Screen::getHeight());
    return getNdcX() - prev_ndc.x;
}

float Touch::getNdcDeltaY() {
    vec3 prev_ndc = Utils::getNormalDeviceCoord(prev_x, prev_y, Screen::getWidth(), Screen::getHeight());
    return getNdcY() - prev_ndc.y;
}
