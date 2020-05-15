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
    Vector(size_t size, const Type *arrayFrom);
    Vector(size_t size, Type element);

    Vector(std::initializer_list<Type> elements);

    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector);
    //< End

    // Destructor
    virtual ~Vector();


    //! Vector bool funcs
    bool isZeroV() const noexcept;
    bool isUnitV() const noexcept;
    //< End

    //! One vector methods
    double length() const;
    void pushBack(const Type &value);
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
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> cBegin() const noexcept;
    ConstIterator<Type> cEnd() const noexcept;
    //< End

    //! Operators overloads
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(const std::initializer_list<Type> &arguments);
    Vector<Type> &operator=(Vector<Type> &&vector);

    Vector<Type> &operator+=(const Vector<Type> &vector);
    Vector<Type> &operator+=(const Type &element);
    void sumEq(const Vector<Type> &vector);
    void sumEq(const Type &element);

    Vector<Type> &operator-=(const Vector<Type> &vector);
    Vector<Type> &operator-=(const Type &element);
    void difEq(const Vector<Type> &vector);
    void difEq(const Type &element);

    Vector<Type> &operator*=(const Vector<Type> &vector);
    Vector<Type> &operator*=(const Type &element);
    void mulEq(const Vector<Type> &vector);
    void mulEq(const Type &element);

    Vector<Type> &operator/=(const Vector<Type> &vector);
    Vector<Type> &operator/=(const Type &element);
    void divEq(const Vector<Type> &vector);
    void divEq(const Type &element);

    Vector<Type> operator+(const Vector<Type> &vector) const;
    Vector<Type> operator+(const Type &element) const;
    Vector<Type> vecSum(const Vector<Type> &vector) const;
    Vector<Type> sumEl(const Type &element) const;

    Vector<Type> operator-(const Vector<Type> &vector) const;
    Vector<Type> operator-(const Type &element) const;
    Vector<Type> vecDif(const Vector<Type> &vector) const;
    Vector<Type> difEl(const Type &element) const;

    double operator*(const Vector<Type> &vector) const;
    Vector<Type> operator*(const Type &element) const;
    double VecMultip(const Vector<Type> &vector) const;
    Vector<Type> mulEl(const Type &element) const;

    double operator/(const Vector<Type> &vector) const;
    Vector<float> operator/(const Type &element) const;
    double VecDivid(const Vector<Type> &vector) const;
    Vector<float> divEl(const Type &element) const;

    Vector<Type> operator-();
    Vector<Type> negative();

    bool operator==(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;

    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;
    //< End

private:
    std::shared_ptr<Type> values;

protected:
    Type summaryValue();
    Vector<Type> vecMul(const Vector<Type> &vector) const;
    Vector<Type> vecDiv(const Vector<Type> &vector) const;

    void checkSizes(const Vector<Type> &vector, int lineError) const;

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
