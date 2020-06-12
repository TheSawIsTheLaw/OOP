#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "Vector/Vector.h"

#include "component.h"

class Composite : public Component
{
public:
    Composite() = default;
    Composite(const Composite &) = default;
    Composite(Vector<shared_ptr<Component>> components);
    Composite &operator=(Vector<shared_ptr<Component>> components);
    //    virtual void accept(const BaseComponentVisitor &visitor) override;
    virtual bool isComposite() const override;
    virtual void add(shared_ptr<Component> element) override;
    virtual void del(ComponentIterator &it) override;
    virtual ComponentIterator begin() override;
    virtual ComponentIterator end() override;

private:
    Vector<Component> components;
};

#endif // COMPOSITE_H
