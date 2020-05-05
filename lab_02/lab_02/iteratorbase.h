#ifndef ITERATORBASE_H
#define ITERATORBASE_H


class IteratorBase
{
public:
    IteratorBase();
    IteratorBase(const IteratorBase &);
    ~IteratorBase();

protected:
    int currentIndex = 0;
    int vectorLen = 0;
};

#endif // ITERATORBASE_H
