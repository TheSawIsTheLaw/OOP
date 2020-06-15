#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include "../Commands/uploadcommand.h"
#include "managerbase.h"
#include <memory>

class UploadManager : public ManagerBase
{
public:
    std::shared_ptr<Component> uploadScene(const UploadCommand &command);
};

#endif // UPLOADMANAGER_H
