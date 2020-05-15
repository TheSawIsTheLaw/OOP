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
    Vector(const std::initializer_list<Type> &elements);


    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type> &&vector) noexcept; //! noexcept
    //< End

    // Destructor
    virtual ~Vector() = default; //! = default


    //! Vector bool funcs
    bool isZeroV() const noexcept;
    bool isSingleV() const noexcept; //! Переименовано
    //< End

    //! One vector methods
    template<typename TypeOut>
    TypeOut length() const; //! Сделана специализация для int
    //! Убрал push, pop
    template<typename TypeOut>
    Vector<TypeOut> getUnitV() const; //! Специализация
    //< End

    //! Two vectors methods
    double angle(const Vector<Type> &vector) const;
    bool collinear(const Vector<Type> &vector) const;
    bool orthgonal(const Vector<Type> &vector) const; //! Переименовано
    //< End

    Type &at(size_t index);
    const Type &at(size_t index) const;
    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;


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
    Vector<Type> operator+(const Vector<Type> &vector) const; //! перенести к +=
    Vector<Type> operator+(const Type &element) const;
    Vector<Type> vecSum(const Vector<Type> &vector) const;
    Vector<Type> sumEl(const Type &element) const;

    Vector<Type> &operator-=(const Vector<Type> &vector);
    Vector<Type> &operator-=(const Type &element);
    void difEq(const Vector<Type> &vector);
    void difEq(const Type &element);
    Vector<Type> operator-(const Vector<Type> &vector) const;
    Vector<Type> operator-(const Type &element) const;
    Vector<Type> vecDif(const Vector<Type> &vector) const;
    Vector<Type> difEl(const Type &element) const;

    Vector<Type> &operator*=(const Vector<Type> &vector);
    Vector<Type> &operator*=(const Type &element);
    void mulEq(const Vector<Type> &vector);
    void mulEq(const Type &element);
    Vector<Type> operator*(const Vector<Type> &vector) const; //! В новую функцию
    Vector<Type> operator*(const Type &element) const;
    Vector<Type> vecMultip(const Vector<Type> &vector) const;
    Vector<Type> mulEl(const Type &element) const;

    Type operator&(const Vector<Type> &vector) const; //! Вынесено!
    Type scalarMult(const Vector<Type> &vector) const;

    Vector<Type> operator^(const Vector<Type> &vector) const; //! Добавлено векторное произведение
    Vector<Type> &operator^=(const Vector<Type> &vector);
    Vector<Type> VectorMult(const Vector<Type> &vector) const;
    void VectorEq(const Vector<Type> &vector);

    Vector<Type> &operator/=(const Vector<Type> &vector);
    Vector<Type> &operator/=(const Type &element);
    void divEq(const Vector<Type> &vector);
    void divEq(const Type &element);
    Vector<Type> operator/(const Vector<Type> &vector) const;
    Vector<Type> operator/(const Type &element) const;
    Vector<Type> vecDivid(const Vector<Type> &vector) const;
    Vector<Type> divEl(const Type &element) const;

    Vector<Type> operator-();
    Vector<Type> negative();

    bool operator==(const Vector<Type> &vector) const; //! + методы
    bool isEqual(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const; //! + методы
    bool isNotEqual(const Vector<Type> &vector) const;

    //< End

private:
    std::shared_ptr<Type[]> values;

protected:
    Type summaryValue();
    Vector<Type> vecMul(const Vector<Type> &vector) const;
    Vector<Type> vecDiv(const Vector<Type> &vector) const;

    void checkSizes(const Vector<Type> &vector, int lineError) const;
    void checkSizeForVecMul(const Vector<Type> &vector, int lineError) const;
    void allocNewVectorMem(size_t itemsAmount);
};

#include "vector.hpp"

#endif // VECTOR_H
