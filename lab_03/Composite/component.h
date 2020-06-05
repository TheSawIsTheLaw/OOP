#ifndef COMPONENT_H
#define COMPONENT_H

#include "composite.h"

class Component : public Composite {
public:
    Component();
    ~Component() = default;

    void accept() override;
    void add() override;
    void del() override;
    bool isComposite() override;

    bool isVisible();
};

#endif // COMPONENT_H
