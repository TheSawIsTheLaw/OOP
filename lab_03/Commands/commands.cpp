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

void TransformCommand::setDX(double set) { dx = set; }

double TransformCommand::getDX() { return dx; }

void TransformCommand::setDY(double set) { dy = set; }

double TransformCommand::getDY() { return dy; }

void TransformCommand::setDZ(double set) { dz = set; }

double TransformCommand::getDZ() { return dz; }

void TransformCommand::setAxis(axis newAx) { ax = newAx; }

axis TransformCommand::getAxis() { return ax; }

void TransformCommand::setCoef(double set) { coefficient = set; }

double TransformCommand::getCoef() { return coefficient; }

void TransformCommand::setAngle(double set) { angle = set; }

double TransformCommand::getAngle() { return angle; }
