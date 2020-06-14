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

Composite::Composite(Vector<std::shared_ptr<Component>> comps) : components(comps) {}

Composite &Composite::operator=(Vector<shared_ptr<Component>> comps)
{
    components = comps;
    return *this;
}

bool Composite::add(shared_ptr<Component> comp)
{
    try {
        components.pushBack(comp);
    } catch (std::exception &error) {
        return false;
    }
    return true;
}

bool Composite::del(ComponentIterator &iter)
{
    try {
        components.erase(iter);
    } catch (std::exception &error) {
        return false;
    }
    return true;
}

void Composite::accept(ComponentVisitorBase &visitor)
{
    visitor.visit(*this);
}

bool Composite::isComposite() const noexcept
{
    return true;
}

ComponentIterator Composite::begin()
{
    return components.begin();
}

ComponentIterator Composite::end()
{
    return components.end();
}

ModelComponent::ModelComponent(shared_ptr<Model> mod) : model(mod) {}

bool ModelComponent::isVisible() const noexcept
{
    return true;
}

void ModelComponent::accept(ComponentVisitorBase &visitor)
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

void CameraComponent::accept(ComponentVisitorBase &visitor)
{
    visitor.visit(*this);
}
