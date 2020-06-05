#ifndef CAMERA_H
#define CAMERA_H

#include "camerabase.h"

class Camera: public CameraBase {
public:
    Camera();
    Camera(int xPosition, int yPosition, int zPosition,
           int xIncline, int yIncline, int zIncline);

    virtual ~Camera() = default;
};

#endif // CAMERA_H
