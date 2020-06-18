#ifndef CAMERA_H
#define CAMERA_H

#include "../Matrix/matrix.hpp"
#include "camerabase.hpp"

class Camera : public CameraBase
{
public:
    Camera() = default;
    Camera(double xPos, double yPos, double zPos, double xNor = 0, double yNor = 0, double zNor = 1);
    Camera(Camera &) = default;

    virtual ~Camera() = default;

    void movement(double dx, double dy, double dz) override;
    void rotation(double angle, axis axRot) override;
    void setCurrentNormal(double ax, double ay, double az) override;
    void setCurrentPosition(double xPos, double yPos, double zPos) override;
    DotXY getProjection(Dot &dot) override;

private:
    double xPosition, yPosition, zPosition;
    double xNormal, yNormal, zNormal;
};

#endif // CAMERA_H
