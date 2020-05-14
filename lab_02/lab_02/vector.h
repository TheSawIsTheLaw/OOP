#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

#include "iterator.h"
#include "ConstantIterator.h"
#include "vectorbase.h"

// class
template<typename Type>
class Vector: public VectorBase{
public:
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

    //! Constructors
    Vector();

    explicit Vector(size_t size);
    Vector(size_t size, Type *arrayFrom);
    Vector(size_t size, Type element);

    Vector(std::initializer_list<Type> elements);

    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector);
    //< End

    // Destructor
    virtual ~Vector();


    //! Vector bool funcs
    bool isZeroV() const;
    bool isUnitV() const;
    //< End

    //! One vector methods
    double length() const;
    void pushBack(const Type value);
    Type popBack();

    Type &at(size_t index);
    const Type &at(size_t index) const;

    Vector<double> getUnitV() const;
    //< End


    //! Two vectors methods
    double vectorsAngle(const Vector<Type> &vector) const;
    bool areCollinear(const Vector<Type> &vector) const;
    bool areOrthgonal(const Vector<Type> &vector) const;
    //< End

    //! Iterator
    ConstIterator<Type> begin() const;
    ConstIterator<Type> end() const;
    Iterator<Type> begin();
    Iterator<Type> end();
    ConstIterator<Type> cBegin() const;
    ConstIterator<Type> cEnd() const;
    //< End

    //! Operators overloads
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(std::initializer_list<Type> arguments);
    Vector<Type> &operator=(Vector<Type> &&vector);

    Vector<Type> &operator+=(const Vector<Type> &vector);
    Vector<Type> &operator+=(const Type &element);
    Vector<Type> sumEq(const Vector<Type> &vector);
    Vector<Type> sumEq(const Type &element);

    Vector<Type> &operator-=(const Vector<Type> &vector);
    Vector<Type> &operator-=(const Type &element);
    Vector<Type> difEq(const Vector<Type> &vector);
    Vector<Type> difEq(const Type &element);

    Vector<Type> &operator*=(const Vector<Type> &vector);
    Vector<Type> &operator*=(const Type &element);
    Vector<Type> mulEq(const Vector<Type> &vector);
    Vector<Type> mulEq(const Type &element);

    Vector<Type> &operator/=(const Vector<Type> &vector);
    Vector<Type> &operator/=(const Type &element); // R
    Vector<Type> divEq(const Vector<Type> &vector); // R
    Vector<Type> divEq(const Type &element); // R

    Vector<Type> operator+(const Vector<Type> &vector); // R
    Vector<Type> operator+(const Type &element); // R
    Vector<Type> sumVec(const Vector<Type> &vector); // R
    Vector<Type> sumEl(const Type &element) const; // R

    Vector<Type> operator-(const Vector<Type> &vector);
    Vector<Type> operator-(const Type &element); // R
    Vector<Type> difVec(const Vector<Type> &vector); // R
    Vector<Type> difEl(const Type &element) const; // R

    double operator*(const Vector<Type> &vector);
    Vector<Type> operator*(const Type &element); // R
    double mulVec(const Vector<Type> &vector); // R
    Vector<Type> mulEl(const Type &element) const; // R

    double operator/(const Vector<Type> &vector);
    Vector<float> operator/(const Type &element); // R
    double divVec(const Vector<Type> &vector); // R
    Vector<float> divEl(const Type &element) const; // R

    Vector<Type> operator-();
    void negative();

    bool operator==(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;

    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;
    //< End

private:
    std::shared_ptr<Type> values;

protected:
    Type summaryValue();
    Vector<Type> vecSum(const Vector<Type> &vector) const;
    Vector<Type> vecDif(const Vector<Type> &vector) const;
    Vector<Type> vecMul(const Vector<Type> &vector) const;
    Vector<Type> vecDiv(const Vector<Type> &vector) const;

    void checkSizes(const Vector<Type> &vector, int lineError);

    void allocNewVectorMem(size_t itemsAmount);
};

template<typename Type>
Vector<Type> operator+(const Type &element, const Vector<Type> &vector) {
    return vector + element;
}

template<typename Type>
Vector<Type> operator-(const Type &element, const Vector<Type> &vector) {
    return vector - element;
}

template<typename Type>
Vector<Type> operator*(const Type &element, const Vector<Type> &vector) {
    return vector * element;
}

template<typename Type>
Vector<Type> operator/(const Type &element, const Vector<Type> &vector) {
    return vector / element;
}

// cio wk
template<typename Type>
std::ostream &operator<<(std::ostream &os, const Vector<Type> &vector) {
    ConstIterator<Type> iterator = vector.begin();
    if (!iterator) {
        os<< "Empty mVector";
        return os;
    }

    os<< "{";
    os<< *iterator;
    for (iterator++; iterator; iterator++)
            os<< ", "<< *iterator;
    os<< "}";

    return os;
}

#endif // VECTOR_H
