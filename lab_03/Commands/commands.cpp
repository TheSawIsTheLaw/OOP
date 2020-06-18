#include "commands.hpp"

#include <string.h>

#include "QFileDialog"
#include "defines.hpp"

UploadCommand::UploadCommand(const char *nameOfFile)
{
    if (strlen(nameOfFile) < FILE_NAME_LEN)
        strcpy(this->fileName, nameOfFile);
}

char *UploadCommand::getFileName()
{
    return fileName;
}

void UploadCommand::setFileName(char *nameOfFile)
{
    if (strlen(nameOfFile) < FILE_NAME_LEN)
        strcpy(this->fileName, nameOfFile);
}

DrawCommand::DrawCommand(std::shared_ptr<DrawingFactoryBase> fac)
    : factory(fac)
{
}

std::shared_ptr<DrawingFactoryBase> DrawCommand::getFactory()
{
    return factory;
}

void DrawCommand::setFactory(std::shared_ptr<DrawingFactoryBase> fac)
{
    factory = fac;
}

void TransformMoveCommand::setDX(double set) { dx = set; }

double TransformMoveCommand::getDX() { return dx; }

void TransformMoveCommand::setDY(double set) { dy = set; }

double TransformMoveCommand::getDY() { return dy; }

void TransformMoveCommand::setDZ(double set) { dz = set; }

double TransformMoveCommand::getDZ() { return dz; }

void TransformRotateCommand::setAxis(axis newAx) { ax = newAx; }

axis TransformRotateCommand::getAxis() { return ax; }

void TransformRotateCommand::setAngle(double set) { angle = set; }

double TransformRotateCommand::getAngle() { return angle; }

void TransformScaleCommand::setCoef(double set) { coefficient = set; }

double TransformScaleCommand::getCoef() { return coefficient; }

void ChangeCurComponentCommand::setDirection(Dir dir) { direction = dir; }

ChangeCurComponentCommand::Dir ChangeCurComponentCommand::getDirection() { return direction; }
