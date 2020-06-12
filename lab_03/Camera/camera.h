#ifndef CAMERA_H
#define CAMERA_H

#include "camerabase.h"

class Camera : public CameraBase
{
public:
    Camera() = default;
    // clang-format off
    Camera(double xPos, double yPos, double zPos,
           double xNor = 0, double yNor = 0, double zNor = 1);
    // clang-format on
    Camera(Camera &) = default;

    virtual ~Camera() = default;

    void movement(double dx, double dy, double dz) override;
    void rotation(double ax, double ay, double az) override;
    void setCurrentNormal(double ax, double ay, double az) override;
    void setCurrentPosition(double xPos, double yPos, double zPos) override;

protected:
    double xPosition, yPosition, zPosition;
    double xNormal, yNormal, zNormal;
};

#endif // CAMERA_H
