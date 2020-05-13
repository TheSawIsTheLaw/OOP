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

    Vector(int len);
    Vector(int len, Type *vector);
    Vector(int len, Type element);

    Vector(std::initializer_list<Type> elements);

    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector);
    //< End

    // Destructor
    ~Vector();


    //! Vector bool funcs
    bool isZeroV() const;
    bool isUnitV() const;
    //< End

    //! One vector methods
    double length() const;
    void pushBack(const Type &value); // REALIZE UWU
    void popBack(); // REALIZE UWU

    bool setItemByIndex(int index, const Type item);
    Type &at(int index);
    const Type &at(int index) const; // Добавить исключение на выход за перделы, переименуй в at

    Vector<Type> getUnitV() const;
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
    Vector<Type> &operator*=(const Type number);
    Vector<Type> &operator/=(const Type number);

    Vector<Type> operator+(const Vector<Type> &vector);
//    Vector<Type> sumVec(const Vector<Type> &vector);
//    Vector<Type> sumEl(const Type element);

    Vector<Type> operator-(const Vector<Type> &vector) const; // noexcept mb?
//    Vector<Type> differenceVec(const Vector<Type> &vector);
//    Vector<Type> differenceEl(const Type element);

    double operator*(const Vector<Type> &vector) const;
//    double compositionVec(const Vector<Type> &vector);
//    Vector<Type> compositionEl(const Type element);

    double operator/(const Vector<Type> &vector) const;
//    double divisionVec(const Vector<Type> &vector);
//    Vector<Type> divisionEl(const Type element);

    Vector<Type> operator-();

    bool operator==(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;

    Type &operator[](int index);
    const Type &operator[](int index) const;
    //< End

private:
    std::shared_ptr<Type> values;

protected:
    Type summaryValue();
    void vecSum(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    void vecDif(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    void vecMul(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;
    void vecDiv(Vector<Type> &result, const Vector<Type> &firstV,
                const Vector<Type> &secondV) const;

    void allocNewVectorMem(int itemsAmount);
};

// cio wk
template<typename Type>
std::ostream &operator<<(std::ostream &os, const Vector<Type> &vector) {
    Iterator<Type> iterator(vector);
    if (!iterator) {
        os<< "Empty mVector";
        return os;
    }

    os<< *iterator;
    for (iterator++; iterator; iterator++)
            os<< ", "<< *iterator;

    return os;
}

#endif // VECTOR_H
