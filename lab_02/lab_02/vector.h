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

    bool setItemByIndex(size_t index, const Type item);
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
    Vector<Type> &operator-=(const Vector<Type> &vector);
    Vector<Type> &operator*=(const Vector<Type> &vector);
    Vector<Type> &operator/=(const Vector<Type> &vector);

    Vector<Type> operator+(const Vector<Type> &vector);
    void vecSum(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    Vector<Type> sumEl(const Type element) const;

    Vector<Type> operator-(const Vector<Type> &vector) const; // noexcept mb?
    void vecDif(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    Vector<Type> difEl(const Type element) const;

    double operator*(const Vector<Type> &vector) const;
    void vecMul(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    Vector<Type> mulEl(const Type element) const;

    double operator/(const Vector<Type> &vector) const;
    void vecDiv(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    Vector<float> divEl(const Type element) const;

    Vector<Type> operator-();
    void negative(Vector<Type> &result);

    bool operator==(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;

    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;
    //< End

private:
    std::shared_ptr<Type> values;

protected:
    Type summaryValue();

    void allocNewVectorMem(size_t itemsAmount);
};

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
