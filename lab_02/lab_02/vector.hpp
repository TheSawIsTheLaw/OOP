#include "vector.h"

#include <limits>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <exception>

//! Distr
template<typename Type>
Vector<Type>::~Vector() {
    if (values)
        values.reset();
}
//< End

//! Iterator
template<typename Type>
Iterator<Type> Vector<Type>::begin() {
    Iterator<Type> iterator(*this);
    return iterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::end() {
    Iterator<Type> iterator(*this);
    return iterator + this->vectorSize;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::begin() const {
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::end() const {
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->vectorSize;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cBegin() const {
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cEnd() const {
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->vectorSize;
}
//< End

//! Methods
template<typename Type>
void Vector<Type>::vecSum(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const {
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> firstIterator = firstV.begin();
    ConstIterator<Type> secondIterator = secondV.begin();

    for (size_t i = 0; resultIterator; i++, resultIterator++, firstIterator++,
                                         secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator + *secondIterator;
        else if (i >= firstV.vectorSize)
            *resultIterator = *firstIterator;
        else
            *resultIterator = *secondIterator;
    }
}

template<typename Type>
Vector<Type> Vector<Type>:: sumEl(const Type element) const {
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom + element;

    return result;
}

template<typename Type>
void Vector<Type>::vecDif(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const {
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> firstIterator = firstV.begin();
    ConstIterator<Type> secondIterator = secondV.begin();

    for (size_t i = 0; resultIterator; i++, resultIterator++, firstIterator++,
                                         secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator - *secondIterator;
        else if (i >= firstV.vectorSize)
            *resultIterator = *firstIterator;
        else
            *resultIterator = -*secondIterator;
    }
}

template<typename Type>
Vector<Type> Vector<Type>:: difEl(const Type element) const {
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom - element;

    return result;
}

template<typename Type>
void Vector<Type>::vecMul(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const{
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> firstIterator = firstV.begin();
    ConstIterator<Type> secondIterator = secondV.begin();

    for (size_t i = 0; resultIterator; i++, resultIterator++, firstIterator++,
                                         secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator * *secondIterator;
        else 
            *resultIterator = 0;
    }
}

template<typename Type>
Vector<Type> Vector<Type>:: mulEl(const Type element) const {
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom * element;

    return result;
}

template<typename Type>
void Vector<Type>::vecDiv(Vector<Type> &result, const Vector<Type> &firstV,
                          const Vector<Type> &secondV) const{
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> firstIterator = firstV.begin();
    ConstIterator<Type> secondIterator = secondV.begin();

    for (size_t i = 0; resultIterator; i++, resultIterator++, firstIterator++,
                                         secondIterator++) {
        if (i < firstV.vectorSize && i < secondV.vectorSize)
            *resultIterator = *firstIterator / *secondIterator;
        else
            *resultIterator = 0;
    }
}
//< End

//! Additive
template<typename Type>
double Vector<Type>::vectorsAngle(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
//    std::cout<< std::endl<< this->length()<< std::endl<< vector.length()<< std::endl;
    if (!this->length() || !vector.length())
        throw ZeroDivisionException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    double angle = (*this * vector) * (1 / (this->length() * vector.length()));
    if (angle > 1)
        angle--;
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool Vector<Type>::areCollinear(const Vector<Type> &vector) const {
//    std::cout<< this->vectorsAngle(vector)<< std::endl;
    if (this->vectorsAngle(vector) < __DBL_EPSILON__)
        return true;
    return false;
}

template<typename Type>
bool Vector<Type>::areOrthgonal(const Vector<Type> &vector) const {
    if (this->vectorsAngle(vector) - 90 < __DBL_EPSILON__)
        return true;
    return false;
}

template<typename Type>
Vector<Type> Vector<Type>::getUnitV() const {
    Vector<Type> unitVector(*this);
    Type len = this->length;

    Iterator<Type> iterator = unitVector.begin();
    for (; iterator; iterator++)
        *iterator /= len;

    return unitVector;
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
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    vectorSize = len;

    Iterator<Type> iterator = this->begin();
    for (; iterator; iterator++)
        *iterator = 0;
}

template<typename Type>
Vector<Type>::Vector(int len, Type element) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    vectorSize = len;

    Iterator<Type> iterator = this->begin();
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

    Iterator<Type> iterator = this->begin();
    for (int i = 0; iterator; iterator++, i++)
        *iterator = arrayFrom[i];
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> arguments) {
    vectorSize = int(arguments.size());
    allocNewVectorMem(vectorSize);

    Iterator<Type> iterator = this->begin();
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }
}

template<typename Type>
Vector<Type>:: Vector(Vector<Type> &&vector): VectorBase(vector.vectorSize) {
    values = vector.values;
    vector.values = nullptr;
}

template<typename Type>
Vector<Type>:: Vector(const Vector<Type> &vector): VectorBase(vector.vectorSize) {
    *this = vector;
}
//< End

//! Get item func
template<typename Type>
Type &Vector<Type>::at(int index) {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorSize)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    for (int i = 0; i < index; i++, iterator++) { }

    return *iterator;
}
//< End

//! Get item const
template<typename Type>
const Type &Vector<Type>::at(int index) const {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorSize)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    ConstIterator<Type> iterator = this->begin();
    for (int i = 0; i < index; i++, iterator++) { }

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
    ConstIterator<Type> firstIterator = this->begin();
    for (ConstIterator<Type> secondIterator = vector.begin(); firstIterator && areEqual;
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
    ConstIterator<float> firstIterator = this->begin();
    for (ConstIterator<float> secondIterator = vector.begin(); firstIterator && areEqual;
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
    ConstIterator<double> firstIterator = this->begin();
    for (ConstIterator<double> secondIterator = vector.begin(); firstIterator && areEqual;
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
    ConstIterator<long double> firstIterator = this->begin();
    for (ConstIterator<long double> secondIterator = vector.begin(); firstIterator && areEqual;
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
    ConstIterator<Type> firstIterator = this->begin();
    for (ConstIterator<Type> secondIterator = vector.begin(); firstIterator && !areNotEqual;
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
    ConstIterator<float> firstIterator = this->begin();
    for (ConstIterator<float> secondIterator = vector.begin(); firstIterator && !areNotEqual;
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
    ConstIterator<double> firstIterator = this->begin();
    for (ConstIterator<double> secondIterator = vector.begin(); firstIterator && !areNotEqual;
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
    ConstIterator<long double> firstIterator = this->begin();
    for (ConstIterator<long double> secondIterator = vector.begin(); firstIterator && !areNotEqual;
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
Vector<Type> &Vector<Type>::operator*=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecMul(*this, *this, vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    vecDiv(*this, *this, vector);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime));

    int maxLength = std::max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecSum(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (vectorSize < 0 || vector.vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                         __LINE__, ctime(&currentTime));

    int maxLength = std::max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecDif(newVector, *this, vector);

    return newVector;
}

template<typename Type>
double Vector<Type>::operator*(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (vectorSize <= 0 || vector.vectorSize <= 0)
        EmptyVectorException(__FILE__, typeid(*this).name(),
                             __LINE__, ctime(&currentTime));

    int maxLength = std::max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecMul(newVector, *this, vector);

    return newVector.summaryValue();
}

template<typename Type>
double Vector<Type>::operator/(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (vectorSize <= 0 || vector.vectorSize <= 0)
        EmptyVectorException(__FILE__, typeid(*this).name(),
                             __LINE__, ctime(&currentTime));

    int maxLength = std::max(vectorSize, vector.vectorSize);
    Vector<Type> newVector(maxLength);
    vecDiv(newVector, *this, vector);

    return newVector.summaryValue();
}
//< End

template<typename Type>
Type &Vector<Type>::operator[](int index) {
    return at(index);
}

template<typename Type>
const Type &Vector<Type>::operator[](int index) const {
    return at(index);
}

template<typename Type>
Vector<Type> Vector<Type>::operator-() {
    Vector<Type> newVector(*this);
    Iterator<Type> iterator = newVector.begin();
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

    Iterator<Type> iterator = this->begin();
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
    time_t currentTime = time(NULL);
    try {
        values.reset();
    } catch (std::bad_alloc &exception) {
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));
    }
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}
//< End

// Smth
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
    return retOut;
}

template<typename Type>
Type Vector<Type>::summaryValue() {
    time_t currentTime = time(NULL);
    if (vectorSize <= 0) throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    Type summary = 0;
    for (; iterator; iterator++)
        summary += *iterator;

    return summary;
}

template<typename Type>
double Vector<Type>::length(void) const {
    time_t currentTime = time(NULL);
    if (vectorSize < 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    ConstIterator<Type> iterator = this->begin();
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    sum = sqrt(sum);
    return sum;
}

template<typename Type>
void Vector<Type>::pushBack(const Type value) {
    Vector<Type> tempVector(*this);
    values.reset();

    allocNewVectorMem(vectorSize + 1);
    vectorSize++;
    ConstIterator<Type> iterFrom = tempVector.cBegin();
    Iterator<Type> iterTo = this->begin();
    for (; iterFrom; iterTo++, iterFrom++)
        *iterTo = *iterFrom;
    *iterTo = value;
}

template<typename Type>
Type Vector<Type>::popBack() {
    //!!! Добавить проверку на размер вектора
    Vector<Type> tempVector(*this);
    values.reset();

    allocNewVectorMem(vectorSize - 1);
    vectorSize--;
    ConstIterator<Type> iterFrom = tempVector.cBegin();
    Iterator<Type> iterTo = this->begin();
    for (; iterTo; iterTo++, iterFrom++) // Кажется, тут лучше всё периписать на поверку currentIndex'a
        *iterTo = *iterFrom;
    return *iterFrom;
}
//! End

//! Set item func
template<typename Type>
bool Vector<Type>::setItemByIndex(int index, const Type item)
{
    if (index < 0 || index >= vectorSize)
        return false;

    at(index) = item;
    return true;
}
//< End
