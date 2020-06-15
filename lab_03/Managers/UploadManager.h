#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include "../Commands/uploadcommand.h"
#include "managerbase.h"

class UploadManager : public ManagerBase
{
public:
    UploadManager();
    UploadManager(UploadCommand &);

    void setFileName(const UploadCommand &);

private:
    char fileName[FILE_NAME_LEN];
};

#endif // UPLOADMANAGER_H
