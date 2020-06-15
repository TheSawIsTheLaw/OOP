#include "transformmanager.h"

void TransformManager::transformComponent(std::shared_ptr<Component> component,
                                          std::shared_ptr<ComponentVisitorBase> visitor)
{
    component->accept(*visitor);
}
