#ifndef CAMERA_H
#define CAMERA_H

#include "camerabase.h"

class Camera: public CameraBase {
public:
    Camera();
    Camera(int xPosition, int yPosition, int zPosition,
           int xIncline, int yIncline, int zIncline);

    virtual ~Camera() = default;

    void movement() override;
    void rotation() override;
    void getCurrentIncline() override;
    void getCurrentPosition() override;
};

#endif // CAMERA_H
