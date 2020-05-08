#ifndef ITERATORBASE_H
#define ITERATORBASE_H

template<typename Type>
class Vector;

class IteratorBase
{
public:
    IteratorBase();
    IteratorBase(const IteratorBase &iterator);
    ~IteratorBase();

protected:
    int currentIndex = 0;
    int vectorLen = 0;
};

#endif // ITERATORBASE_H
