#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include "../Commands/uploadcommand.h"
#include "../SceneUploader/sceneuploader.h"
#include "managerbase.h"

class UploadManager : public ManagerBase
{
public:
    UploadManager(const UploadCommand &);

    virtual ~UploadManager() = default;

    void setFileName(const UploadCommand &);

private:
    SceneUploader &sceneUpl;
    char fileName[FILE_NAME_LEN];
};

#endif // UPLOADMANAGER_H
