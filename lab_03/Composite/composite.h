#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>

class Composite {
public:
    Composite();
    ~Composite() = default;

    virtual void accept() = 0;
    virtual bool isComposite() = 0;
    virtual void add() = 0;
    virtual void del() = 0;
//    CompIterator *makeIter();
};

#endif // COMPOSITE_H
