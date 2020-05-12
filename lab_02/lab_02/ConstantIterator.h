#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H


#include "exceptions.h"

#include <memory>
#include <time.h>
#include <vector>


template<typename Type>
class Vector;

template<typename Type>
class ConstIterator: public std::iterator<std::input_iterator_tag, int>
{
public:
    ConstIterator(const ConstIterator<Type> &iterator);
    ConstIterator(const Vector<Type> &vector);

    const Type &operator *() const;
    const Type *operator->() const;
    operator bool() const;

    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator);

    ConstIterator<Type> &operator-=(int number);
    ConstIterator<Type> operator-(int number) const;
    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int number);

    ConstIterator<Type> &operator+=(int number);
    ConstIterator<Type> operator+(int number) const;
    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int number);

    bool operator<=(const ConstIterator<Type> &boolean) const;
    bool operator<(const ConstIterator<Type> &boolean) const;
    bool operator>=(const ConstIterator<Type> &boolean) const;
    bool operator>(const ConstIterator<Type> &boolean) const;
    bool operator==(const ConstIterator<Type> &boolean) const;
    bool operator!=(const ConstIterator<Type> &boolean) const;

    bool exceptionCheck(int lineError) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
    int currentIndex = 0;
    int vectorLen = 0;
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
    vectorLen = iterator.vectorLen;
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorLen = vector.size();
    wPointer = vector.values;
}

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
ConstIterator<Type> &ConstIterator<Type>::operator+=(int number) {
    exceptionCheck(__LINE__);
    currentIndex += number;

    return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator+(int number) const {
    exceptionCheck(__LINE__);
    ConstIterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator-=(int number) {
    exceptionCheck(__LINE__);
    currentIndex -= number;

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator-(int number) const {
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

    if (currentIndex >= vectorLen || vectorLen == 0 || currentIndex < 0)
        return false;
    else
        return true;
}


template<typename Type>
bool ConstIterator<Type>::exceptionCheck(int lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                 lineError, ctime(&currentTime));
    return false;
}


#endif // CONST_ITERATOR_H
