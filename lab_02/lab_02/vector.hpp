#include "vector.h"

#include <limits>
#include <stdlib.h>
#include <cmath>

//! Distr
template<typename Type>
Vector<Type>::~Vector<Type>() {
    if (values)
        values.reset();
}
//< End

//! Constructors
template<typename Type>
Vector<Type>::Vector() {
    vectorLen = 0;
    allocNewVectorMem(vectorLen);
}

template<typename Type>
Vector<Type>::Vector(int len) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = 0;
}

template<typename Type>
Vector<Type>::Vector(int len, Type element) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = element;
}

template<typename Type>
Vector<Type>::Vector(int len, Type *arrayFrom) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));
    if (!arrayFrom)
        throw InvalidCopyArrayPointer(__FILE__, typeid(*this).name(),
                                      __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; iterator; iterator++, i++)
        *iterator = arrayFrom[i];
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> arguments) {
    vectorLen = int(arguments.size());
    allocNewVectorMem(vectorLen);

    Iterator<Type> iterator(*this);
    for (auto &currentItem: arguments) {
        *iterator = currentItem;
        iterator++;
    }
}
//< End

//! Get item func
template<typename Type>
Type &Vector<Type>::getItemByIndex(int index) {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorLen)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) {}

    return *iterator;
}
//< End

//! Get item const
template<typename Type>
const Type &Vector<Type>::getItemByIndex(int index) const {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorLen)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) {}

    return *iterator;
}
//<

//! Overloads
template<typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const {
    bool areEqual = false;
    if (vectorLen != vector.length())
        return areEqual;

    areEqual = true;
    Iterator<Type> firstIterator(*this);
    for (Iterator<Type> secondIterator(vector); firstIterator && areEqual;
         secondIterator++)
        if (*firstIterator != *secondIterator)
            areEqual = false;
    return areEqual;
}

template<>
bool Vector<float>::operator==(const Vector<float> &vector) const {
    bool areEqual = false;
    if (vectorLen != vector.length())
        return areEqual;

    areEqual = true;
    Iterator<float> firstIterator(*this);
    for (Iterator<float> secondIterator(vector); firstIterator && areEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<float>::epsilon())
            areEqual = false;
    return areEqual;
}

template<>
bool Vector<double>::operator==(const Vector<double> &vector) const {
    bool areEqual = false;
    if (vectorLen != vector.length())
        return areEqual;

    areEqual = true;
    Iterator<double> firstIterator(*this);
    for (Iterator<double> secondIterator(vector); firstIterator && areEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<double>::epsilon())
            areEqual = false;
    return areEqual;
}

template<>
bool Vector<long double>::operator==(const Vector<long double> &vector) const {
    bool areEqual = false;
    if (vectorLen != vector.length())
        return areEqual;

    areEqual = true;
    Iterator<long double> firstIterator(*this);
    for (Iterator<long double> secondIterator(vector); firstIterator && areEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<long double>::epsilon())
            areEqual = false;
    return areEqual;
}

template<typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vector) const {
    bool areNotEqual = true;
    if (vectorLen != vector.length())
        return areNotEqual;

    areNotEqual = false;
    Iterator<Type> firstIterator(*this);
    for (Iterator<Type> secondIterator(vector); firstIterator && !areNotEqual;
         secondIterator++)
        if (*firstIterator != *secondIterator)
            areNotEqual = true;
    return areNotEqual;
}

template<>
bool Vector<float>::operator!=(const Vector<float> &vector) const {
    bool areNotEqual = true;
    if (vectorLen != vector.length())
        return areNotEqual;

    areNotEqual = false;
    Iterator<float> firstIterator(*this);
    for (Iterator<float> secondIterator(vector); firstIterator && !areNotEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<float>::epsilon())
            areNotEqual = true;
    return areNotEqual;
}

template<>
bool Vector<double>::operator!=(const Vector<double> &vector) const {
    bool areNotEqual = true;
    if (vectorLen != vector.length())
        return areNotEqual;

    areNotEqual = false;
    Iterator<double> firstIterator(*this);
    for (Iterator<double> secondIterator(vector); firstIterator && !areNotEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<double>::epsilon())
            areNotEqual = true;
    return areNotEqual;
}

template<>
bool Vector<long double>::operator!=(const Vector<long double> &vector) const {
    bool areNotEqual = true;
    if (vectorLen != vector.length())
        return areNotEqual;

    areNotEqual = false;
    Iterator<long double> firstIterator(*this);
    for (Iterator<long double> secondIterator(vector); firstIterator && !areNotEqual;
         secondIterator++)
        if (std::abs(*firstIterator - *secondIterator) < std::numeric_limits<long double>::epsilon())
            areNotEqual = true;
    return areNotEqual;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0 || vector.vectorLen < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecSum(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0 || vector.vectorLen < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecDif(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type number) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iter *= mult
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type number) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iter /= mult
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0 || vector.vectorLen < 0)
        throw emptyError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime))

    int maxLength = max(vectorLen, vector.vectorLen);
    Vector<Type> newVector(maxLength);
    vecSum(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorLen < 0 || vector.vectorLen < 0)
        throw emptyError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime))

    int maxLength = max(vectorLen, vector.vectorLen);
    Vector<Type> newVector(maxLength);
    vecDif(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Type &Vector<Type>::operator[](int index) {
    return getItemByIndex(index);
}

//< End

//! Allocation for Vector
template<typename Type>
void Vector<Type>::allocNewVectorMem(int amount) {
    values.reset();
    // Добавить bad alloc
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}
//< End

template<typename Type>
Type Vector<Type>::length(void) const {
    time_t currentTime = time(NULL);
    if (vectorLen < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
            __LINE__, currentTime)

    Iterator<Type> iterator(*this);
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    sum = sqrt(sum);
    return sum;
}
