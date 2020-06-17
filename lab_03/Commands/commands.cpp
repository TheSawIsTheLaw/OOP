#include "commands.h"

#include <string.h>

#include "QFileDialog"
#include "defines.h"

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

void TransformModelMoveCommand::setDX(double set) { dx = set; }

double TransformModelMoveCommand::getDX() { return dx; }

void TransformModelMoveCommand::setDY(double set) { dy = set; }

double TransformModelMoveCommand::getDY() { return dy; }

void TransformModelMoveCommand::setDZ(double set) { dz = set; }

double TransformModelMoveCommand::getDZ() { return dz; }

void TransformModelRotateCommand::setAxis(axis newAx) { ax = newAx; }

axis TransformModelRotateCommand::getAxis() { return ax; }

void TransformModelRotateCommand::setAngle(double set) { angle = set; }

double TransformModelRotateCommand::getAngle() { return angle; }

void TransformModelScaleCommand::setCoef(double set) { coefficient = set; }

double TransformModelScaleCommand::getCoef() { return coefficient; }
