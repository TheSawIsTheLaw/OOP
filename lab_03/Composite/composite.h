#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "../Vector/vector.h"

class Composite {
public:
    Composite();
    ~Composite() = default;

    void accept();
    bool isComposite();
    void add();
    void del();
//    CompIterator *makeIter();
};

#endif // COMPOSITE_H
