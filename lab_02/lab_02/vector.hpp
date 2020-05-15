#include "vector.h"

#include <limits>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <exception>


//! Iterator
template<typename Type>
Iterator<Type> Vector<Type>::begin() noexcept {
    Iterator<Type> iterator(*this);
    return iterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::end() noexcept {
    Iterator<Type> iterator(*this);
    return iterator + this->vectorSize;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept {
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept {
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->vectorSize;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cBegin() const noexcept {
    ConstIterator<Type> cIterator(*this);
    return cIterator;
}

template<typename Type>
ConstIterator<Type> Vector<Type>::cEnd() const noexcept {
    ConstIterator<Type> cIterator(*this);
    return cIterator + this->vectorSize;
}
//< End

//! Methods
template<typename Type>
Vector<Type> Vector<Type>::vecSum(const Vector<Type> &vector) const {
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator + *iterFrom;
    return result;
}

template<typename Type>
Vector<Type> Vector<Type>:: sumEl(const Type &element) const {
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom + element;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::vecDif(const Vector<Type> &vector) const {
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator - *iterFrom;
    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::difEl(const Type &element) const {
    Vector<Type> result(*this);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom - element;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::vecMul(const Vector<Type> &vector) const {
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator * *iterFrom;
    return result;
}

template<typename Type>
Vector<Type> Vector<Type>:: mulEl(const Type &element) const {
    Vector<Type> result(*this);
    ConstIterator<Type> iterFrom = this->begin();
    Iterator<Type> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = *iterFrom * element;

    return result;
}

template<typename Type>
Vector<Type> Vector<Type>::vecDiv(const Vector<Type> &vector) const {
    Vector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator / *iterFrom;

    return result;
}

template<typename Type>
Vector<float> Vector<Type>::divEl(const Type &element) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    if (!element)
        throw ZeroDivisionException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Vector<float> result(this->vectorSize);

    ConstIterator<Type> iterFrom = this->begin();
    Iterator<float> iterTo = result.begin();

    for (; iterFrom; iterFrom++, iterTo++)
        *iterTo = static_cast<float>(*iterFrom) / element;

    return result;
}
//< End

//! Additive
template<typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
//    std::cout<< std::endl<< this->length()<< std::endl<< vector.length()<< std::endl;
    if (!this->length<Type>() || !vector.length<Type>())
        throw ZeroDivisionException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    double angle = (*this * vector) / (this->length<Type>() * vector.length<Type>());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool Vector<Type>::collinear(const Vector<Type> &vector) const {
//    std::cout<< this->vectorsAngle(vector)<< std::endl;
    if (this->angle(vector) < __FLT_EPSILON__)
        return true;
    return false;
}

template<typename Type>
bool Vector<Type>::orthgonal(const Vector<Type> &vector) const {
    if (this->angle(vector) - 90 < __DBL_EPSILON__)
        return true;
    return false;
}

template<typename Type>
template<typename TypeOut>
Vector<TypeOut> Vector<Type>::getUnitV() const {
    Vector<TypeOut> unitVector(this->vectorSize);
    Type len = this->length<Type>();

    Iterator<TypeOut> iteratorTo = unitVector.begin();
    ConstIterator<Type> iteratorFrom = this->begin();
    for (; iteratorFrom; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom / len;

    return unitVector;
}

template<>
template<>
Vector<double> Vector<int>::getUnitV() const {
    Vector<double> unitVector(this->vectorSize);
    float len = this->length<float>();

    Iterator<double> iteratorTo = unitVector.begin();
    ConstIterator<int> iteratorFrom = this->begin();
    for (; iteratorFrom; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom / len;

    return unitVector;
}
//< End

//! Constructors
template<typename Type>
Vector<Type>::Vector() {
    this->vectorSize = 0;
    this->allocNewVectorMem(vectorSize);
}

template<typename Type>
Vector<Type>::Vector(size_t size) {
    time_t currentTime = time(NULL);

    this->allocNewVectorMem(size);
    if (!this->values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    this->vectorSize = size;

    Iterator<Type> iterator = this->begin();
    for (; iterator; iterator++)
        *iterator = 0;
}

template<typename Type>
Vector<Type>::Vector(size_t size, Type element) {
    time_t currentTime = time(NULL);
    if (size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    this->allocNewVectorMem(size);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    this->vectorSize = size;

    Iterator<Type> iterator = this->begin();
    for (; iterator; iterator++)
        *iterator = element;
}

template<typename Type>
Vector<Type>::Vector(size_t size, const Type *arrayFrom) {
    if (size == 0) {
        time_t currentTime = time(NULL);
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    }
    if (!arrayFrom) {
        time_t currentTime = time(NULL);
        throw InvalidCopyArrayPointer(__FILE__, typeid(*this).name(),
                                      __LINE__, ctime(&currentTime));
    }
    this->allocNewVectorMem(size);
    this->vectorSize = size;

    Iterator<Type> iterator = this->begin();
    for (size_t i = 0; iterator; iterator++, i++)
        *iterator = arrayFrom[i];
}

template<typename Type>
Vector<Type>::Vector(const std::initializer_list<Type> &arguments) {
    this->vectorSize = arguments.size();
    this->allocNewVectorMem(vectorSize);

    Iterator<Type> iterator = this->begin();
    for (auto &currentItem : arguments)
    {
        *iterator = currentItem;
        iterator++;
    }
}

template<typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept: VectorBase(vector.vectorSize) {
    this->values = vector.values;
    vector.values = nullptr;
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vector): VectorBase(vector.vectorSize) {
    *this = vector;
}
//< End

//! Get item func
template<typename Type>
Type &Vector<Type>::at(size_t index) {
    time_t currentTime = time(NULL);
    if (index >= vectorSize)
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++, iterator++) { }

    return *iterator;
}
//< End

//! Get item const
template<typename Type>
const Type &Vector<Type>::at(size_t index) const {
    if (index >= this->vectorSize) {
        time_t currentTime = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(),
                                  __LINE__, ctime(&currentTime));
    }

    ConstIterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++, iterator++) { }

    return *iterator;
}
//<

//! Overloads
template<typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const {
    bool areEqual = false;
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize != vector.vectorSize)
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
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    *this = this->vecSum(vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &element) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    *this = this->sumEl(element);

    return *this;
}

template<typename Type>
void Vector<Type>::sumEq(const Vector<Type> &vector) {
    *this += vector;
}

template<typename Type>
void Vector<Type>::sumEq(const Type &element) {
    *this += element;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    *this = this->vecDif(vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &element) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    *this = this->difEl(element);

    return *this;
}

template<typename Type>
void Vector<Type>::difEq(const Vector<Type> &vector) {
    *this -= vector;
}

template<typename Type>
void Vector<Type>::difEq(const Type &element) {
    *this -= element;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    *this = this->vecMul(vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &element) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    *this = this->mulEl(element);

    return *this;
}

template<typename Type>
void Vector<Type>::mulEq(const Vector<Type> &vector) {
    *this *= vector;
}

template<typename Type>
void Vector<Type>::mulEq(const Type &element) {
    *this *= element;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    vecDiv(*this, *this, vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &element) {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    *this = this->divEl(element);

    return *this;
}

template<typename Type>
void Vector<Type>::divEq(const Vector<Type> &vector) {
    *this /= vector;
}

template<typename Type>
void Vector<Type>::divEq(const Type &element) {
    *this /= element;
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    return this->vecSum(vector);
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Type &element) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    return this->sumEl(element);
}

template<typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    return this->vecDif(vector);
}

template<typename Type>
Vector<Type> Vector<Type>::operator-(const Type &element) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    return this->difEl(element);
}

template<typename Type>
double Vector<Type>::operator*(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        EmptyVectorException(__FILE__, typeid(*this).name(),
                             __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    return this->vecMul(vector).summaryValue();
}

template<typename Type>
Vector<Type> Vector<Type>::operator*(const Type &element) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    return this->mulEl(element);
}

template<typename Type>
double Vector<Type>::vecMultip(const Vector<Type> &vector) const {
    return *this * vector;
}

template<typename Type>
double Vector<Type>::operator/(const Vector<Type> &vector) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0 || vector.vectorSize == 0)
        EmptyVectorException(__FILE__, typeid(*this).name(),
                             __LINE__, ctime(&currentTime));
    this->checkSizes(vector, __LINE__);

    return this->vecDif(vector).summaryValue();
}

template<typename Type>
Vector<float> Vector<Type>::operator/(const Type &element) const {
    return this->divEl(element);
}

template<typename Type>
double Vector<Type>::vecDivid(const Vector<Type> &vector) const {
    return *this / vector;
}
//< End

template<typename Type>
Type &Vector<Type>::operator[](size_t index) {
    return at(index);
}

template<typename Type>
const Type &Vector<Type>::operator[](size_t index) const {
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
    this->vectorSize = vector.vectorSize;
    this->allocNewVectorMem(vectorSize);

    Iterator<Type> iteratorTo(*this);
    Iterator<Type> iteratorFrom(vector);
    for (; iteratorTo; iteratorTo++, iteratorFrom++)
        *iteratorTo = *iteratorFrom;
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator=(const std::initializer_list<Type> &arguments) {
    this->vectorSize = arguments.size();
    this->allocNewVectorMem(vectorSize);

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
    this->vectorSize = vector.vectorSize;
    this->allocNewVectorMem(vectorSize);
    this->values = vector.values;
    vector.values.reset();

    return *this;
}
//< End

//! Allocation for Vector
template<typename Type>
void Vector<Type>::allocNewVectorMem(size_t amount) {
    time_t currentTime = time(NULL);
    try {
        this->values.reset(new Type[amount]);
    } catch (std::bad_alloc &exception) {
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));
    }
}
//< End

//! Smth
template<typename Type>
bool Vector<Type>::isSingleV() const noexcept{
    bool retOut = false;
    if (fabs(this->length<Type>() - 1) < __FLT_EPSILON__)
        retOut = true;
    return retOut;
}

template<>
bool Vector<long double>::isSingleV() const noexcept{
    bool retOut = false;
    if (fabs(this->length<long double>() - 1) < __DBL_EPSILON__)
        retOut = true;
    return retOut;
}

template<typename Type>
bool Vector<Type>::isZeroV() const noexcept{
    bool retOut = false;
    if (this->length<Type>() < __FLT_EPSILON__)
        retOut = true;
    return retOut;
}

template<typename Type>
Type Vector<Type>::summaryValue() {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    Type summary = 0;
    for (; iterator; iterator++)
        summary += *iterator;

    return summary;
}

template<typename Type>
template<typename TypeOut>
TypeOut Vector<Type>::length(void) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    ConstIterator<Type> iterator = this->begin();
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    return sqrt(sum);
}

template<>
template<>
double Vector<int>::length(void) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(),
                                   __LINE__, ctime(&currentTime));

    ConstIterator<int> iterator = this->begin();
    int sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    return sqrt(sum);
}

template<typename Type>
Vector<Type> Vector<Type>::negative() {
    return -*this;
}
//! End

//! Check
template<typename Type>
void Vector<Type>::checkSizes(const Vector<Type> &vector, int lineError) const {
    time_t currentTime = time(NULL);
    if (this->vectorSize != vector.vectorSize)
        throw InvalidVectorsSizes(__FILE__, typeid(*this).name(),
                                  lineError, ctime(&currentTime));
}
//< End
