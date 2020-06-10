#include "camera.h"

Camera::Camera()
{
    this->xPosition = 0;
    this->yPosition = 0;
    this->zPosition = 0;
    this->xIncline = 0;
    this->yIncline = 0;
    this->zIncline = 0;
}

Camera::Camera(int xPosition, int yPosition, int zPosition, int xIncline, int yIncline, int zIncline)
{
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->zPosition = zPosition;
    this->xIncline = xIncline;
    this->yIncline = yIncline;
    this->zIncline = zIncline;
}

void Camera::movement() {}

void Camera::rotation() {}

void Camera::getCurrentIncline() {}

void Camera::getCurrentPosition() {}
