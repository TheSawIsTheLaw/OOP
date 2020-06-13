#include "UploadManager.h"

#include <QDebug>

#include "string.h"

UploadManager::UploadManager(const UploadCommand &command)
{
    strcpy(fileName, command.fileName);
}

void UploadManager::setFileName(const UploadCommand &command)
{
    strcpy(fileName, command.fileName);
    qDebug("%s", fileName);
}
