#ifndef CAMERA_H
#define CAMERA_H

#include "camerabase.h"

class Camera : public CameraBase
{
public:
    Camera();
    // clang-format off
    Camera(int xPosition, int yPosition,
           int zPosition, int xIncline,
           int yIncline, int zIncline);
    // clang-format on

    virtual ~Camera() = default;

    void movement() override;
    void rotation() override;
    void getCurrentIncline() override;
    void getCurrentPosition() override;
};

#endif // CAMERA_H
