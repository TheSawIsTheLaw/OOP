#ifndef ITERATOR_H
#define ITERATOR_H

#include "iteratorbase.h"
#include <memory>

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

    bool errCheck(int line) const;

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
bool Iterator<Type>::errCheck(int line) const {

}



#endif // ITERATOR_H
