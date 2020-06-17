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

void TransformModelCommand::setDX(double set) { dx = set; }

double TransformModelCommand::getDX() { return dx; }

void TransformModelCommand::setDY(double set) { dy = set; }

double TransformModelCommand::getDY() { return dy; }

void TransformModelCommand::setDZ(double set) { dz = set; }

double TransformModelCommand::getDZ() { return dz; }

void TransformModelCommand::setAxis(axis newAx) { ax = newAx; }

axis TransformModelCommand::getAxis() { return ax; }

void TransformModelCommand::setCoef(double set) { coefficient = set; }

double TransformModelCommand::getCoef() { return coefficient; }

void TransformModelCommand::setAngle(double set) { angle = set; }

double TransformModelCommand::getAngle() { return angle; }
