#ifndef CAMERABASE_H
#define CAMERABASE_H


class CameraBase
{
public:
    CameraBase(int xPosition = 0, int yPosition = 0,
               int zPosition = 0, int xIncline = 0,
               int yIncline = 0, int zIncline = 0):
        xPosition(xPosition), yPosition(yPosition),
        zPosition(zPosition), xIncline(xIncline),
        yIncline(yIncline), zIncline(zIncline) { }

    virtual ~CameraBase() = 0;

    virtual void movement() = 0;
    virtual void rotation() = 0;
    virtual void getCurrentPosition() = 0;
    virtual void getCurrentIncline() = 0;
protected:
    int xPosition = 0, yPosition = 0, zPosition = 0;
    int xIncline = 0, yIncline = 0, zIncline = 0;
};

#endif // CAMERABASE_H
