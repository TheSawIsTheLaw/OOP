#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    Component();
    virtual ~Component() = 0;

    virtual void accept() = 0;
    virtual void add() = 0;
    virtual void del() = 0;
    virtual bool isComposite() = 0;

    virtual bool isVisible() = 0;
};

#endif // COMPONENT_H
