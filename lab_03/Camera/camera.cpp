#include "camera.h"

Camera::Camera(double xPos, double yPos, double zPos, double xNor, double yNor, double zNor)
    : xPosition(xPos), yPosition(yPos), zPosition(zPos), xNormal(xNor), yNormal(yNor), zNormal(zNor)
{}

void Camera::movement(double dx, double dy, double dz) {}

void Camera::rotation(double ax, double ay, double az) {}

void Camera::setCurrentNormal(double ax, double ay, double az) {}

void Camera::setCurrentPosition(double xPos, double yPos, double zPos) {}
