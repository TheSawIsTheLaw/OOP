#ifndef ITERATOR_H
#define ITERATOR_H

#include "iteratorbase.h"
#include "exceptions.h"

#include <memory>
#include <time.h>

template<typename Type>
class Iterator: public IteratorBase
{
public:
    Iterator(const Iterator<Type> &iter);
    Iterator(const Vector<Type> &vect);

    Type &operator *();
    const Type &operator *() const;
    Type *operator->() const;
    operator bool() const;

    Iterator<Type> &operator=(const Iterator<Type> &iter);

    Iterator<Type> &operator-=(int number);
    Iterator<Type> operator-(int number) const;
    Iterator<Type> &operator--();
    Iterator<Type> operator--(int);

    Iterator<Type> &operator+=(int number);
    Iterator<Type> operator+(int number) const;
    Iterator<Type> &operator++();
    Iterator<Type> operator++(int);

    bool operator<=(const Iterator<Type> &boolean) const;
    bool operator<(const Iterator<Type> &boolean) const;
    bool operator>=(const Iterator<Type> &boolean) const;
    bool operator>(const Iterator<Type> &boolean) const;
    bool operator==(const Iterator<Type> &boolean) const;
    bool operator!=(const Iterator<Type> &boolean) const;

    bool exceptionCheck(int line) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
};

template<typename Type>
Type *Iterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type> copied = wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
bool Iterator<Type>::exceptionCheck(int lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw
}



#endif // ITERATOR_H
