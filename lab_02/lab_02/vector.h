#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

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



};

#endif // VECTOR_H
