#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include "exceptions.h"

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template<typename Type>
class ConstIterator: public std::iterator<std::random_access_iterator_tag, int>
{
public:
    ConstIterator(const ConstIterator<Type> &iterator);
    ConstIterator(const Vector<Type> &vector);

    const Type &operator *() const;
    const Type *operator->() const;
    operator bool() const;

    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator);

    ConstIterator<Type> &operator-=(size_t number);
    ConstIterator<Type> operator-(size_t number) const;
    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int);

    ConstIterator<Type> &operator+=(size_t number);
    ConstIterator<Type> operator+(size_t number) const;
    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int);

    bool operator<=(const ConstIterator<Type> &boolean) const;
    bool operator<(const ConstIterator<Type> &boolean) const;
    bool operator>=(const ConstIterator<Type> &boolean) const;
    bool operator>(const ConstIterator<Type> &boolean) const;
    bool operator==(const ConstIterator<Type> &boolean) const;
    bool operator!=(const ConstIterator<Type> &boolean) const;

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
Type *ConstIterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type> copied = wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type> &iterator) {
    wPointer = iterator.wPointer;
    currentIndex = iterator.currentIndex;
    vectorSize = iterator.vectorSize;
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorSize = vector.size();
    wPointer = vector.values;
};

template<typename Type>
const Type &ConstIterator<Type>::operator*() const {
    exceptionCheck(__LINE__);

    std::shared_ptr<Type> copiedPointer = wPointer.lock();
    return *getCurrentPointer();
}

template<typename Type>
const Type *ConstIterator<Type>::operator->() const {
    exceptionCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator=(const ConstIterator<Type>& iterator) {
    exceptionCheck(__LINE__);

    wPointer = iterator.wPointer;
    return *this;
}

template<typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator+=(size_t number) {
    exceptionCheck(__LINE__);
    currentIndex += number;

    return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator+(size_t number) const {
    exceptionCheck(__LINE__);
    ConstIterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator-=(size_t number) {
    exceptionCheck(__LINE__);
    currentIndex -= number;

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator-(size_t number) const {
    exceptionCheck(__LINE__);
    ConstIterator<Type> iterator(*this);
    iterator -= number;

    return iterator;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int) {
    exceptionCheck(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator++() {
    exceptionCheck(__LINE__);
    ++currentIndex;

    return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator--(int) {
    exceptionCheck(__LINE__);
    --(*this);

    return *this;
}

template<typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator--() {
    exceptionCheck(__LINE__);
    --currentIndex;

    return *this;
}

template<typename Type>
bool ConstIterator<Type>::operator<(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer < compareTo.wPointer;
}

template<typename Type>
bool ConstIterator<Type>::operator<=(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer <= compareTo.wPointer;
}

template<typename Type>
bool ConstIterator<Type>::operator>(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer > compareTo.wPointer;
}

template<typename Type>
bool ConstIterator<Type>::operator>=(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer >= compareTo.wPointer;
}

template<typename Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer == compareTo.wPointer;
}

template<typename Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer != compareTo.wPointer;
}

template<typename Type>
ConstIterator<Type>::operator bool() const {
    exceptionCheck(__LINE__);

    if (currentIndex >= vectorSize || vectorSize == 0)
        return false;
    else
        return true;
}

template<typename Type>
const Type &ConstIterator<Type>::operator[](size_t index) const {
    size_t curLine = __LINE__;
    exceptionCheck(curLine);

    time_t currentTime = time(NULL);
    if (index + this->currentIndex >= this->vectorLen)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  curLine, ctime(&currentTime));

    return *(this + index);
}

template<typename Type>
bool ConstIterator<Type>::exceptionCheck(size_t lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                 lineError, ctime(&currentTime));
    return false;
}


#endif // CONSTITERATOR_H
