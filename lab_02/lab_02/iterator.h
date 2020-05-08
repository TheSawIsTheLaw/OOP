#ifndef ITERATOR_H
#define ITERATOR_H

#include "Exceptions.h"

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template<typename Type>
class Iterator: public std::iterator<std::input_iterator_tag, int>
{
public:
    Iterator(const Iterator<Type> &iterator);
    Iterator(const Vector<Type> &vector);

    Type &operator *();
    const Type &operator *() const;
    Type *operator->();
    const Type *operator->() const;
    operator bool() const;

    Iterator<Type> &operator=(const Iterator<Type> &iterator);

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

    bool exceptionCheck(int lineError) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
    int currentIndex = 0;
    int vectorLen = 0;
};

template<typename Type>
Type *Iterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type> copied = wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) {
    wPointer = iterator.wPointer;
    currentIndex = iterator.currentIndex;
    vectorLen = iterator.vectorLen;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorLen = vector.size();
    wPointer = vector.values;
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

    return wPointer < compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer <= compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer > compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer >= compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer == compareTo.wPointer;
}

template<typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer != compareTo.wPointer;
}

template<typename Type>
Iterator<Type>::operator bool() const {
    exceptionCheck(__LINE__);

    if (currentIndex >= vectorLen || vectorLen == 0 || currentIndex < 0)
        return false;
    else
        return true;
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
