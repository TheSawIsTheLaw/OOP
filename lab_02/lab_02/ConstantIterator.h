#ifndef CONSTANTITERATOR_H
#define CONSTANTITERATOR_H

#include "vector.h"
#include "iterator.h"

#include <memory>
#include <time.h>

template<typename Type>
class ConstantIterator: public IteratorBase
{
public:
    ConstantIterator(const ConstantIterator<Type> &iter);
    ConstantIterator(const Vector<Type> &vect);

    const Type &operator *() const;
    const Type *operator->() const;
    operator bool() const;

    ConstantIterator<Type> &operator=(const ConstantIterator<Type> &iter);

    ConstantIterator<Type> &operator-=(int number);
    ConstantIterator<Type> operator-(int number) const;
    ConstantIterator<Type> &operator--();
    ConstantIterator<Type> operator--(int number);

    ConstantIterator<Type> &operator+=(int number);
    ConstantIterator<Type> operator+(int number) const;
    ConstantIterator<Type> &operator++();
    ConstantIterator<Type> operator++(int number);

    bool operator<=(const ConstantIterator<Type> &boolean) const;
    bool operator<(const ConstantIterator<Type> &boolean) const;
    bool operator>=(const ConstantIterator<Type> &boolean) const;
    bool operator>(const ConstantIterator<Type> &boolean) const;
    bool operator==(const ConstantIterator<Type> &boolean) const;
    bool operator!=(const ConstantIterator<Type> &boolean) const;

    bool exceptionCheck(int line) const;

private:
    std::weak_ptr<Type> wPointer;

protected:
    Type *getCurrentPointer() const;
};

template<typename Type>
Type *ConstantIterator<Type>::getCurrentPointer() const {
    std::shared_ptr<Type> copied = wPointer.lock();
    return copied.get() + currentIndex;
}

template<typename Type>
ConstantIterator<Type>::ConstantIterator(const Vector<Type> &vector) {
    currentIndex = 0;
    vectorLen = vector.length;
    wPointer = vector.values;
}

template<typename Type>
ConstantIterator<Type>::ConstantIterator(const ConstantIterator<Type> &iterator) {
    wPointer = iterator.wPointer;
    currentIndex = iterator.currentIndex;
    vectorLen = iterator.vectorLen;
}

template<typename Type>
const Type &ConstantIterator<Type>::operator*() const {
    exceptionCheck(__LINE__);

    std::shared_ptr<Type> copiedPointer = wPointer.lock();
    return *getCurrentPointer();
}

template<typename Type>
const Type *ConstantIterator<Type>::operator->() const {
    exceptionCheck(__LINE__);

    return getCurrentPointer();
}

template<typename Type>
ConstantIterator<Type> &ConstantIterator<Type>::operator=(const ConstantIterator<Type>& iterator) {
    exceptionCheck(__LINE__);

    wPointer = iterator.wPointer;
    return *this;
}

template<typename Type>
ConstantIterator<Type> &ConstantIterator<Type>::operator+=(int number) {
    exceptionCheck(__LINE__);
    currentIndex += number;

    return *this;
}

template<typename Type>
ConstantIterator<Type> ConstantIterator<Type>::operator+(int number) const {
    exceptionCheck(__LINE__);
    ConstantIterator<Type> iterator(*this);
    iterator += number;

    return iterator;
}

template <typename Type>
ConstantIterator<Type> &ConstantIterator<Type>::operator-=(int number) {
    exceptionCheck(__LINE__);
    currentIndex -= number;

    return *this;
}

template <typename Type>
ConstantIterator<Type> ConstantIterator<Type>::operator-(int number) const {
    exceptionCheck(__LINE__);
    ConstantIterator<Type> iterator(*this);
    iterator -= number;

    return iterator;
}

template<typename Type>
ConstantIterator<Type> ConstantIterator<Type>::operator++(int) {
    exceptionCheck(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
ConstantIterator<Type> &ConstantIterator<Type>::operator++() {
    exceptionCheck(__LINE__);
    ++currentIndex;

    return *this;
}

template<typename Type>
ConstantIterator<Type> ConstantIterator<Type>::operator--(int) {
    exceptionCheck(__LINE__);
    --(*this);

    return *this;
}

template<typename Type>
ConstantIterator<Type> &ConstantIterator<Type>::operator--() {
    exceptionCheck(__LINE__);
    --currentIndex;

    return *this;
}

template<typename Type>
bool ConstantIterator<Type>::operator<(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer < compareTo.wPointer;
}

template<typename Type>
bool ConstantIterator<Type>::operator<=(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer <= compareTo.wPointer;
}

template<typename Type>
bool ConstantIterator<Type>::operator>(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer > compareTo.wPointer;
}

template<typename Type>
bool ConstantIterator<Type>::operator>=(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer >= compareTo.wPointer;
}

template<typename Type>
bool ConstantIterator<Type>::operator==(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer == compareTo.wPointer;
}

template<typename Type>
bool ConstantIterator<Type>::operator!=(const ConstantIterator<Type> &compareTo) const {
    exceptionCheck();

    return wPointer != compareTo.wPointer;
}

template<typename Type>
ConstantIterator<Type>::operator bool() const {
    exceptionCheck();

    if (currentIndex >= vectorLen || vectorLen == 0 || currentIndex < 0)
        return false;
    else
        return true;
}


template<typename Type>
bool ConstantIterator<Type>::exceptionCheck(int lineError) const {
    if (!wPointer.expired())
        return true;

    time_t currentTime = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(),
                                 lineError, ctime(&currentTime));
    return false;
}

#endif // CONSTANTITERATOR_H
