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
    Type *operator->();
    const Type *operator->() const;
    operator bool() const;

    Iterator<Type> &operator=(const Iterator<Type> &iter);

    Iterator<Type> &operator-=(int number);
    Iterator<Type> operator-(int number) const;
    Iterator<Type> &operator--();
    Iterator<Type> operator--(int number);

    Iterator<Type> &operator+=(int number);
    Iterator<Type> operator+(int number) const;
    Iterator<Type> &operator++();
    Iterator<Type> operator++(int number);

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
Iterator<Type>::Iterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorLen = vector.length;
    wPointer = vector.values;
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) {
    wPointer = iterator.wPointer;
    currentIndex = iterator.currentIndex;
    vectorLen = iterator.vectorLen;
}

template<typename Type>
Type &Iterator<Type>::operator*() {
    exceptionCheck(__LINE__);

    std::shared_ptr<Type> copiedPointer = wPointer.lock();
    return *getCurrentPointer();
}

template<typename Type>
const Type &Iterator<Type>::operator*() const {
    exceptionCheck(__LINE__);

    std::shared_ptr<Type> copiedPointer = wPointer.lock();
    return *getCurrentPointer();
}

template<typename Type>
Type *Iterator<Type>::operator->() {
    exceptionCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
const Type *Iterator<Type>::operator->() const {
    exceptionCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type>& iterator) {
    exceptionCheck(__LINE__);

    wPointer = iterator.wPointer;
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator+=(int number) {
    exceptionCheck(__LINE__);
    currentIndex += number;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator+(int number) const {
    exceptionCheck(__LINE__);
    Iterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(int number) {
    exceptionCheck(__LINE__);
    currentIndex -= number;

    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(int number) const {
    exceptionCheck(__LINE__);
    Iterator<Type> iterator(*this);
    iterator -= number;

    return iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int) {
    exceptionCheck(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator++() {
    exceptionCheck(__LINE__);
    ++currentIndex;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator--(int) {
    exceptionCheck(__LINE__);
    --(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator--() {
    exceptionCheck(__LINE__);
    --currentIndex;

    return *this;
}

template<typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer <= compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::exceptionCheck(int lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                 lineError, ctime(&currentTime));
    return false;
}

#endif // ITERATOR_H
