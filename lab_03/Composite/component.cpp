#include "component.h"

bool Component::isVisible() const noexcept
{
    return false;
}

bool Component::isComposite() const noexcept
{
    return false;
}

bool Component::add(shared_ptr<Component>)
{
    return false;
}

bool Component::del(ComponentIterator &)
{
    return false;
}

ComponentIterator Component::begin()
{
    return ComponentIterator();
}

ComponentIterator Component::end()
{
    return ComponentIterator();
}

ModelComponent::ModelComponent(shared_ptr<Model> mod) : model(mod) {}

bool ModelComponent::isVisible() const noexcept
{
    return true;
}

void ModelComponent::accept(const ComponentVisitorBase &visitor)
{
    visitor.visit(*this);
}

shared_ptr<Model> ModelComponent::getModel()
{
    return shared_ptr<Model>(this->model.get());
}

void ModelComponent::setModel(const shared_ptr<Model> mod)
{
    model = mod;
}

CameraComponent::CameraComponent(shared_ptr<CameraBase> cam) : camera(cam) {}

bool CameraComponent::isVisible() const noexcept
{
    return false;
}

void CameraComponent::accept(const ComponentVisitorBase &visitor)
{
    visitor.visit(*this);
}
