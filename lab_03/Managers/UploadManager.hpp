#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include "../Commands/commands.hpp"
#include "managerbase.hpp"
#include <memory>

class UploadManager : public ManagerBase
{
public:
    std::shared_ptr<Component> uploadScene(UploadCommand &command);
};

#endif // UPLOADMANAGER_H
