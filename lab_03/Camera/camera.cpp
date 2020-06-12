#include "camera.h"
#include "../Model/dot.h"

Camera::Camera(double xPos, double yPos, double zPos, double xNor, double yNor, double zNor)
    : xPosition(xPos), yPosition(yPos), zPosition(zPos), xNormal(xNor), yNormal(yNor), zNormal(zNor)
{}

void Camera::movement(double dx, double dy, double dz)
{
    xPosition += dx;
    yPosition += dy;
    zPosition += dz;
}

void Camera::rotation(double angle, axis axRot)
{
    Dot dot(xNormal, yNormal, zNormal);
    dot.rotate(angle, axRot);

    xNormal = dot.getXPos();
    yNormal = dot.getYPos();
    zNormal = dot.getZPos();
}

void Camera::setCurrentNormal(double ax, double ay, double az)
{
    xNormal = ax;
    yNormal = ay;
    zNormal = az;
}

void Camera::setCurrentPosition(double xPos, double yPos, double zPos)
{
    xPosition = xPos;
    yPosition = yPos;
    zPosition = zPos;
}
