#include "composite.h"

Composite::Composite(Vector<shared_ptr<Component>> comps) : components(comps) {}

Composite &Composite::operator=(Vector<shared_ptr<Component>> comps)
{
    components = comps;
    return *this;
}

bool Composite::add(shared_ptr<Component> comp)
{
    try {
        components.push_back(comp);
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

void Composite::accept(const ComponentVisitorBase &visitor)
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
