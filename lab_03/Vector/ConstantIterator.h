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
    ConstIterator(const ConstIterator<Type> &iterator) noexcept;
    ConstIterator(const Vector<Type> &vector) noexcept;

    const Type &operator*() const;
    const Type *operator->() const;
    operator bool() const;

    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator) noexcept;

    ConstIterator<Type> &operator-=(size_t number);
    ConstIterator<Type> operator-(size_t number) const;
    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int);

    ConstIterator<Type> &operator+=(size_t number);
    ConstIterator<Type> operator+(size_t number) const;
    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int);

    bool operator<=(const ConstIterator<Type> &compareTo) const;
    bool operator<(const ConstIterator<Type> &compareTo) const;
    bool operator>=(const ConstIterator<Type> &compareTo) const;
    bool operator>(const ConstIterator<Type> &compareTo) const;
    bool operator==(const ConstIterator<Type> &compareTo) const;
    bool operator!=(const ConstIterator<Type> &compareTo) const;

    const Type &operator[](const size_t index) const;

private:
    std::weak_ptr<Type[]> wPointer;

protected:
    Type *getCurrentPointer() const;
    void exceptionCheck(int currentLine) const;
    void validityCheck(int currentLine) const;
    size_t currentIndex = 0;
    size_t vectorSize = 0;
};

#include "ConstIterator.hpp"


#endif // CONSTITERATOR_H
