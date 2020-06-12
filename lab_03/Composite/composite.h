#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>

#include "component.h"

class Composite : public Component
{
public:
    Composite() = default;
    ~Composite() = default;

    void accept() override;
    void add() override;
    void del() override;
    bool isComposite() override;
    //    CompIterator *makeIter();

private:
    std::vector<Component> components;
};

#endif // COMPOSITE_H
