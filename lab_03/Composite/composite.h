#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>

#include "component.h"

class Composite : public Component {
   public:
    Composite();
    ~Composite() = default;

    void accept();
    void add();
    void del();
    bool isComposite() override;
    //    CompIterator *makeIter();

   private:
    std::vector<Component> components;
};

#endif // COMPOSITE_H
