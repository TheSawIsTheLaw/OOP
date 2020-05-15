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

    Type &operator*();
    const Type &operator*() const;
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

    bool operator<=(const Iterator<Type> &compareTo) const;
    bool operator<(const Iterator<Type> &compareTo) const;
    bool operator>=(const Iterator<Type> &compareTo) const;
    bool operator>(const Iterator<Type> &compareTo) const;
    bool operator==(const Iterator<Type> &compareTo) const;
    bool operator!=(const Iterator<Type> &compareTo) const;

    Type &operator[](const size_t index);
    const Type &operator[](const size_t index) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
    void exceptionCheck(int currentLine) const;
    void indexCheck(int currentLine) const;
    size_t currentIndex = 0;
    size_t vectorSize = 0;
};

template<typename Type>
Type *Iterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type> copied = this->wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) {
    this->wPointer = iterator.wPointer;
    this->currentIndex = iterator.currentIndex;
    this->vectorSize = iterator.vectorSize;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) {
    this->currentIndex = 0;
    this->vectorSize = vector.size();
    this->wPointer = vector.values;
}

template<typename Type>
Type &Iterator<Type>::operator*() {
    exceptionCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurrentPointer();
}

template<typename Type>
const Type &Iterator<Type>::operator*() const {
    exceptionCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurrentPointer();
}

template<typename Type>
Type *Iterator<Type>::operator->() {
    exceptionCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
const Type *Iterator<Type>::operator->() const {
    exceptionCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type>& iterator) {
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
    exceptionCheck(__LINE__);

    return this->currentIndex < compareTo.currentIndex;
}

template<typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &compareTo) const {
    exceptionCheck(__LINE__);

    return this->currentIndex <= compareTo.currentIndex;
}

template<typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &compareTo) const {
    exceptionCheck(__LINE__);

    return this->currentIndex > compareTo.currentIndex;
}

template<typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &compareTo) const {
    exceptionCheck();

    return this->currentIndex >= compareTo.currentIndex;
}

template<typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &compareTo) const {
    exceptionCheck(__LINE__);

    return this->currentIndex == compareTo.currentIndex;
}

template<typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &compareTo) const {
    exceptionCheck(__LINE__);

    return this->currentIndex != compareTo.currentIndex;
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
Type &Iterator<Type>::operator[](size_t index) {
    size_t curLine = __LINE__;
    exceptionCheck(curLine);

    time_t currentTime = time(NULL);
    if (index + this->currentIndex >= this->vectorLen)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  curLine, ctime(&currentTime));

    return *(this + index);
}


template<typename Type>
const Type &Iterator<Type>::operator[](size_t index) const {
    size_t curLine = __LINE__;
    exceptionCheck(curLine);

    time_t currentTime = time(NULL);
    if (index + this->currentIndex >= this->vectorLen)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  curLine, ctime(&currentTime));

    return *(this + index);
}


template<typename Type>
void Iterator<Type>::indexCheck(int currentLine) const {
    if (this->currentIndex >= this->vectorSize) {
        time_t currentTime = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  currentLine, ctime(&currentTime));
    }
}


template<typename Type>
void Iterator<Type>::exceptionCheck(int currentLine) const {
    if (wPointer.expired()) {
        time_t currentTime = time(NULL);
        throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                     currentLine, ctime(&currentTime));
    }
}


#endif // ITERATOR_H
