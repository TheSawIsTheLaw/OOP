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
    Iterator(const Iterator<Type> &iterator) noexcept;
    Iterator(const Vector<Type> &vector) noexcept;

    Type &operator*();
    const Type &operator*() const;
    Type *operator->();
    const Type *operator->() const;
    operator bool() const;

    Iterator<Type> &operator=(const Iterator<Type> &iterator) noexcept;

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
    std::weak_ptr<Type[]> wPointer;

protected:
    Type *getCurrentPointer() const;
    void exceptionCheck(int currentLine) const;
    void validityCheck(int currentLine) const;
    size_t currentIndex = 0;
    size_t vectorSize = 0;
};

#include "Iterator.hpp"

#endif // ITERATOR_H
