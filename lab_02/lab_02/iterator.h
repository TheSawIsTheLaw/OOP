#ifndef ITERATOR_H
#define ITERATOR_H

#include "exceptions.h"

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template<typename Type>
class Iterator: public std::iterator<std::random_access_iterator_tag, int>
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

    Iterator<Type> &operator-=(size_t number);
    Iterator<Type> operator-(size_t number) const;
    Iterator<Type> &operator--();
    Iterator<Type> operator--(int);

    Iterator<Type> &operator+=(size_t number);
    Iterator<Type> operator+(size_t number) const;
    Iterator<Type> &operator++();
    Iterator<Type> operator++(int);

    bool operator<=(const Iterator<Type> &boolean) const;
    bool operator<(const Iterator<Type> &boolean) const;
    bool operator>=(const Iterator<Type> &boolean) const;
    bool operator>(const Iterator<Type> &boolean) const;
    bool operator==(const Iterator<Type> &boolean) const;
    bool operator!=(const Iterator<Type> &boolean) const;

    Type &operator[](const size_t index);
    const Type &operator[](const size_t index) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
    bool exceptionCheck(size_t lineError) const;
    size_t currentIndex = 0;
    size_t vectorSize = 0;
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
    vectorSize = iterator.vectorSize;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorSize = vector.size();
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
Iterator<Type> &Iterator<Type>::operator+=(size_t number) {
    exceptionCheck(__LINE__);
    currentIndex += number;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator+(size_t number) const {
    exceptionCheck(__LINE__);
    Iterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(size_t number) {
    exceptionCheck(__LINE__);
    currentIndex -= number;

    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(size_t number) const {
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

    if (currentIndex >= vectorSize || vectorSize == 0)
        return false;
    else
        return true;
}

template<typename Type>
Type &Iterator<Type>::operator[](const size_t index) {
    size_t curLine = __LINE__;
    exceptionCheck(curLine);

    time_t currentTime = time(NULL);
    if (index + this->currentIndex >= this->vectorLen)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  curLine, ctime(&currentTime));

    return *(this + index);
}


template<typename Type>
const Type &Iterator<Type>::operator[](const size_t index) const {
    size_t curLine = __LINE__;
    exceptionCheck(curLine);

    time_t currentTime = time(NULL);
    if (index + this->currentIndex >= this->vectorLen)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  curLine, ctime(&currentTime));

    return *(this + index);
}


template<typename Type>
bool Iterator<Type>::exceptionCheck(size_t lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                 lineError, ctime(&currentTime));
    return false;
}


#endif // ITERATOR_H
