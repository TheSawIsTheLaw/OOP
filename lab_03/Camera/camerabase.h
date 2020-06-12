#ifndef CAMERABASE_H
#define CAMERABASE_H

class CameraBase
{
public:
    virtual void movement(double dx, double dy, double dz) = 0;
    virtual void rotation(double ax, double ay, double az) = 0;
    virtual void setCurrentPosition(double xPosition, double yPosition, double zPosition) = 0;
    virtual void setCurrentNormal(double ax, double ay, double az) = 0;
};

#endif // CAMERABASE_H
