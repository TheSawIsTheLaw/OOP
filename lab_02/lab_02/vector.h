#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

#include "vectorbase.h"

template<typename Type>
class Vector: public VectorBase{
public:
    //class Iterator

    Vector();

    Vector(int len);
    Vector(int len, Type *vector);
    Vector(int len, Type vector, ...);

    Vector(std::initializer_list<Type> elements);

    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector);
    ~Vector();


    bool isZeroV() const;
    bool isUnitV() const;

    int size() const;
    Type length() const;

    Type &getItemByIndex(int index);
    const Type &getItemByIndex(int index) const;

    bool &setItemByIndex(int index, const Type &vector);

    double vectorsAngle(const Vector<Type> &vector) const;

    bool areCollinear(const Vector<Type> &vector) const;
    bool areOrthgonal(const Vector<Type> &vector) const;

    Vector<Type> getUnitV() const;


    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(std::initializer_list<Type> arguments);
    Vector<Type> &operator=(Vector<Type> &&vector);

    Vector<Type> &operator+=(const Type &number);
    Vector<Type> &operator-=(const Type &number);
    Vector<Type> &operator*=(const Type &number);
    Vector<Type> &operator/=(const Type &number);
    Vector<Type> &operator&=(const Vector<Type> &vector);

    Vector<Type> &operator+(const Type &number);
    Vector<Type> &operator-(const Type &number);

    Vector<Type> &operator*(const Vector<Type>) const;

    Vector<Type> operator&(const Vector<Type> &vector) const;

    Vector<Type> &operator-();

    bool operator==(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;

    Type &operator[](int index);
    const Type &operator[](int index) const;

private:
    std::shared_ptr<Type> values;

protected:
    Type summaryValue();
    void vecSum(Vector<Type> &result, const Vector<Type> &firstV, const Vector<Type> &secondV) const;
    void vecDif(Vector<Type> &result, const Vector<Type> &firstV, const Vector<Type> &secondV) const;
    void vecMul(Vector<Type> &result, const Vector<Type> &firstV, const Vector<Type> &secondV) const;

    void newMemory(int itemsAmount);
};

#endif // VECTOR_H
