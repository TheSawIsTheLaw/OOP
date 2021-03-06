#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "managerbase.hpp"
#include <memory>

class TransformManager : public ManagerBase
{
public:
    void transformComponent(std::shared_ptr<Component> component,
                            std::shared_ptr<ComponentVisitorBase> visitor);
};

#endif // TRANSFORMMANAGER_H
