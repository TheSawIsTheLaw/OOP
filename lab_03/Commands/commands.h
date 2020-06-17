#ifndef UPLOADCOMMAND_H
#define UPLOADCOMMAND_H

#include "Composite/component.h"
#include "Drawer/drawingfactorybase.h"
#include "commandbase.h"
#include "defines.h"
#include <memory>

class UploadCommand : CommandBase
{
public:
    UploadCommand(const char *nameOfFile);

    char *getFileName();
    void setFileName(char nameOfFile[FILE_NAME_LEN]);

private:
    char fileName[FILE_NAME_LEN] = { 0 };
};

class DrawCommand : CommandBase
{
public:
    DrawCommand(std::shared_ptr<DrawingFactoryBase> fac);

    void setFactory(std::shared_ptr<DrawingFactoryBase> fac);
    std::shared_ptr<DrawingFactoryBase> getFactory();

private:
    std::shared_ptr<DrawingFactoryBase> factory;
};

class TransformMoveCommand : CommandBase
{
public:
    void setDX(double set);
    double getDX();

    void setDY(double set);
    double getDY();

    void setDZ(double set);
    double getDZ();

private:
    double dx, dy, dz;
};

class TransformRotateCommand : CommandBase
{
public:
    void setAxis(axis newAx);
    axis getAxis();

    void setAngle(double set);
    double getAngle();

private:
    axis ax;
    double angle;
};

class TransformScaleCommand : CommandBase
{
public:
    void setCoef(double set);
    double getCoef();

private:
    double coefficient;
};

class ChangeCurComponentCommand : CommandBase
{
public:
    enum Dir
    {
        PREV = -1,
        NEXT = 1
    };

    void setDirection(Dir dir);
    Dir getDirection();

private:
    Dir direction;
};

#endif // UPLOADCOMMAND_H
