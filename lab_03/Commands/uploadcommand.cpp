#include "uploadcommand.h"

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
