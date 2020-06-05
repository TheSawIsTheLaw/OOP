#ifndef CAMERABASE_H
#define CAMERABASE_H


class CameraBase
{
public:
    CameraBase();

    virtual ~CameraBase() = 0;

    virtual void movement() = 0;
    virtual void rotation() = 0;
    virtual void getCurrentPosition() = 0;
    virtual void getCurrentIncline() = 0;
};

#endif // CAMERABASE_H
