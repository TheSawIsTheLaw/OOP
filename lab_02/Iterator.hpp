#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "iterator.h"

template<typename Type>
Type *Iterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type[]> copied = this->wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept {
    this->wPointer = iterator.wPointer;
    this->currentIndex = iterator.currentIndex;
    this->vectorSize = iterator.vectorSize;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) noexcept {
    this->currentIndex = 0;
    this->vectorSize = vector.size();
    this->wPointer = vector.values;
}

template<typename Type>
Type &Iterator<Type>::operator*() {
    exceptionCheck(__LINE__);
    validityCheck(__LINE__);

    return *getCurrentPointer();
}

template<typename Type>
const Type &Iterator<Type>::operator*() const {
    exceptionCheck(__LINE__);
    validityCheck(__LINE__);

    return *getCurrentPointer();
}

template<typename Type>
Type *Iterator<Type>::operator->() {
    exceptionCheck(__LINE__);
    validityCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
const Type *Iterator<Type>::operator->() const {
    exceptionCheck(__LINE__);
    validityCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type>& iterator) noexcept {
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
void Iterator<Type>::exceptionCheck(int currentLine) const {
    if (wPointer.expired()) {
        time_t currentTime = time(NULL);
        throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                     currentLine, ctime(&currentTime));
    }
}

template<typename Type>
void Iterator<Type>::validityCheck(int currentLine) const {
    if (this->currentIndex >= this->vectorSize) {
        time_t currentTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(),
                                     currentLine, ctime(&currentTime));
    }
}

#endif // ITERATOR_HPP
