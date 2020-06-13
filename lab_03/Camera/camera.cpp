#include "camera.h"
#include "../Model/dot.h"
#include <cmath>
#include <limits>

Camera::Camera(double xPos, double yPos, double zPos, double xNor, double yNor, double zNor)
    : xPosition(xPos), yPosition(yPos), zPosition(zPos), xNormal(xNor), yNormal(yNor), zNormal(zNor)
{}

DotXY Camera::getProjection(Dot &dot)
{
    double length = xNormal * xNormal + yNormal * yNormal + zNormal * zNormal;
    double projection = xNormal * xNormal + yNormal * yNormal;

    dot.move(-xNormal, -yNormal, -zNormal);

    if (std::fabs(xNormal) > std::numeric_limits<double>::epsilon()) {
        double zAngle = std::acos(sqrt(xNormal * xNormal) / sqrt(projection));
        dot.rotate(zAngle, Z);
    }

    if (std::fabs(yNormal) > std::numeric_limits<double>::epsilon()) {
        double yAngle = std::acos(sqrt(length - zNormal * zNormal) / sqrt(length));
        dot.rotate(yAngle, Y);
    }

    return DotXY(dot.getXPos(), dot.getYPos());
}

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
