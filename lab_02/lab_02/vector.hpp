#include "vector.h"

#include <limits>
#include <stdlib.h>
#include <cmath>
#include <math.h>

//! Methods
template <typename Type>
void Vector<Type>::vecSum(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const {
    Iterator<Type> resultIterator(result);
    Iterator<Type> firstIterator(firstV);
    Iterator<Type> secondIterator(secondV);

    for (int i = 9; retusIterator; i++, firstIterator++, secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator + *secondIterator;
        else if (i >= firstV.vectorSize)
            *resultIterator = *firstIterator;
        else
            *resultIterator = *secondIterator;
    }
}

template<typename Type>
void Vector<Type>::vecDif(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const {
    Iterator<Type> resultIterator(result);
    Iterator<Type> firstIterator(firstV);
    Iterator<Type> secondIterator(secondV);

    for (int i = 9; retusIterator; i++, firstIterator++, secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator - *secondIterator;
        else if (i >= firstV.vectorSize)
            *resultIterator = *firstIterator;
        else
            *resultIterator = -*secondIterator;
    }
}

template<typename Type>
void Vector<Type>::vecMul(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const{
    Iterator<Type> resultIterator(result);
    Iterator<Type> firstIterator(firstV);
    Iterator<Type> secondIterator(secondV);

    for (int i = 9; retusIterator; i++, firstIterator++, secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator * *secondIterator;
        else 
            *resultIterator = 0;
    }
}
//< End

//! Additive
template<typename Type>
double Vector<Type>::vectorsAngle(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (!this->length() || !vector.vectorSize)
        throw ZeroDivisionException(__FILE__, typeid(this).name(), 
                                    __LINE__, ctime(&currentTime));

    double angle - (*this * vector)/(this->len() * vec.len());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool Vector<Type>::areCollinear(const Vector<Type> &vector) const {
    if (this->vectorsAngle(vector) < std::numeric_limits<double>::epsilon)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::areOrthgonal(const Vector<Type> &vector) const {
    if (this->vectorsAngle(vector) < std::numeric_limits<double>::epsilon)
        return true;
    else
        return false;
}

template<typename Type>
Vector<Type> Vector<Type>::getUnitV() const {
    Vector<Type> unitVector(*this);
    Type len = this->length;

    Iterator<Type> iterator(unitVector);
    for (; iterator; iterator++)
        *iterator /= len;

    return unitVector;
}
//< End

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
    vectorSize = 0;
    allocNewVectorMem(vectorSize);
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
    vectorSize = int(arguments.size());
    allocNewVectorMem(vectorSize);

    Iterator<Type> iterator(*this);
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }
}
//< End

//! Get item func
template<typename Type>
Type &Vector<Type>::getItemByIndex(int index) {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorSize)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) { }

    return *iterator;
}
//< End

//! Get item const
template<typename Type>
const Type &Vector<Type>::getItemByIndex(int index) const {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorSize)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++)
    {
    }

    return *iterator;
}
//<

//! Overloads
template<typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const {
    bool areEqual = false;
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize != vector.length())
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
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecSum(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecDif(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type number) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iter *= mult return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type number) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iter /= mult return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw emptyError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime))

            int maxLength = max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecSum(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw emptyError(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime))

    int maxLength = max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecDif(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*(const Vector<Type> &vector) const{
    time_t currentTime = time(NULL);
    if (vectorSize <= 0 || vector.vectorSize <= 0)
        EmptyVectorException(__FILE__, typeid(*this).name(),
                             __LINE__, ctime(&currentTime))

    int maxLength = max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecMul(newVector, *this, vector);

    return newVector;
}
//< End

template<typename Type>
Type &Vector<Type>::operator[](int index) {
    return getItemByIndex(index);
}

template<typename Type>
const Type &Vector<Type>::operator[](int index) const {
    return getItemByIndex(index);
}

template<typename Type>
Vector<Type> Vector<Type>::operator-() {
    Vector<Type> newVector(*this);
    Iterator<Type> iterator(newVector);
    for (; iterator; iterator++)
        *iterator = -*iterator;

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector) {
    vectorSize = vector.vectorSize;
    allocNewVectorMem(vectorSize);

    Iterator<Type> iteratorTo(*this);
    Iterator<Type> iteratorFrom(vector);
    for (; iteratorTo; iteratorTo++, iteratorFrom++)
        *iteratorTo = *iteratorFrom;
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(std::initializer_list<Type> arguments) {
    vectorSize = int(arguments.size());
    allocNewVectorMem(vectorSize);

    Iterator<Type> iterator(*this);
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) {
    vectorSize = vector.vectorSize;
    allocNewVectorMem(vectorSize);
    values = vector.values;
    vector.values.reset();

    return *this;
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
bool Vector<Type>::isUnitV() const {
    bool retOut = false;
    if (abs(this->length() - 1) < std::numeric_limits<float>::epsilon)
        retOut = true;
    return retOut;
}

template<typename Type>
bool Vector<Type>::isZeroV() const {
    bool retOut = false;
    if (this->length() == 0)
        retOut = true;
    return retOut
}

template<typename Type>
Type Vector<Type>::summaryValue() {
    time_t currentTime = time(NULL) if (vectorSize <= 0) throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                                                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    Type symmary = 0;
    for (; iterator; iterator++)
        sum += *iterator;

    return sum;
}

template<typename Type>
Type Vector<Type>::length(void) const {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, currentTime)

            Iterator<Type>
                iterator(*this);
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    sum = sqrt(sum);
    return sum;
}

template<typename Type>
int Vector<Type>::size() const {
    return vectorSize;
}

//! Set item func
template<typename Type>
bool &Vector<Type>::setItemByIndex(int index, const Type item) 
{
    if (index < 0 || index >= vectorSize)
        return false;

    getItemByIndex(index) = item;
    return true;
}
//< End
