#pragma once

#include "Exceptions/exceptions.h"
#include "baseVector.hpp"
#include "time.h"
#include <cstddef>
#include <memory>

template<typename T>
using shared_ptr = std::shared_ptr<T>;

template<typename T>
using weak_ptr = std::weak_ptr<T>;

template<typename T>
class VecIterator;

template<typename T>
class ConstIterator;

template<typename Type>
class Vector : public BaseVector
{
    shared_ptr<Type[]> _data;
    void _allocateMemory(size_t size);

public:
    Vector();
    Vector(size_t size);
    Vector(const Vector &);
    Vector<Type> &operator=(const Vector &);
    void push_back(Type elem);
    void erase(VecIterator<Type>);
    Type &operator[](size_t index);
    const Type &operator[](size_t index) const;
    size_t size() { return _size; }
    bool isEmpty() const override;

    VecIterator<Type> begin();
    ConstIterator<Type> begin() const;
    VecIterator<Type> end();
    ConstIterator<Type> end() const;
};

template<typename T>
class VecIterator : public std::iterator<std::random_access_iterator_tag, T>
{
    weak_ptr<T[]> _data;
    size_t _size = 0;
    size_t _index = 0;

public:
    VecIterator();
    VecIterator(shared_ptr<T[]> data, size_t size, size_t index = 0);
    VecIterator(const VecIterator<T> &) = default;
    VecIterator(VecIterator<T> &&) = default;
    VecIterator<T> &operator=(VecIterator<T> &) = default;

    bool operator!=(const VecIterator<T> &vec) const { return _index != vec._index; }

    T *operator->();
    const T *operator->() const;
    T &operator*();
    const T &operator*() const;

    VecIterator<T> &operator++();
    VecIterator<T> operator++(int);
    VecIterator<T> &operator--();
    VecIterator<T> operator--(int);

    VecIterator<T> operator+(size_t diff) const;
    VecIterator<T> operator-(size_t diff) const;
};

template<typename T>
class ConstIterator : public std::iterator<std::random_access_iterator_tag, T>
{
    weak_ptr<T[]> _data;
    size_t _size = 0;
    mutable size_t _index = 0;

public:
    ConstIterator() = delete;
    ConstIterator(const ConstIterator<T> &) = default;
    ConstIterator(ConstIterator<T> &&) = default;
    ConstIterator(shared_ptr<T[]> data, size_t size, size_t index = 0);
    VecIterator<T> &operator=(ConstIterator<T> &) = default;

    bool operator!=(const ConstIterator<T> &vec) const { return _index == vec._index; }

    const T *operator->() const;
    const T &operator*() const;

    ConstIterator<T> &operator++() const;
    ConstIterator<T> operator++(int) const;
    ConstIterator<T> &operator--() const;
    ConstIterator<T> operator--(int) const;

    ConstIterator<T> operator+(size_t diff) const;
    ConstIterator<T> operator-(size_t diff) const;
};

template<typename T>
VecIterator<T>::VecIterator(){};

template<typename T>
VecIterator<T>::VecIterator(shared_ptr<T[]> data, size_t size, size_t index)
    : _data(data), _size(size), _index(index){};

template<typename T>
T *VecIterator<T>::operator->()
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template<typename T>
const T *VecIterator<T>::operator->() const
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template<typename T>
T &VecIterator<T>::operator*()
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template<typename T>
const T &VecIterator<T>::operator*() const
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template<typename T>
VecIterator<T> &VecIterator<T>::operator++()
{
    ++_index;
    return *this;
}

template<typename T>
VecIterator<T> VecIterator<T>::operator++(int)
{
    VecIterator<T> it(*this);
    ++(*this);
    return it;
}

template<typename T>
VecIterator<T> &VecIterator<T>::operator--()
{
    --_index;
    return *this;
}

template<typename T>
VecIterator<T> VecIterator<T>::operator--(int)
{
    VecIterator<T> it(*this);
    --(*this);
    return it;
}

template<typename T>
VecIterator<T> VecIterator<T>::operator+(size_t diff) const
{
    VecIterator<T> it(*this);
    it._index += diff;
    return it;
}

template<typename T>
VecIterator<T> VecIterator<T>::operator-(size_t diff) const
{
    VecIterator<T> it(*this);
    it._index -= diff;
    return it;
}

template<typename T>
ConstIterator<T>::ConstIterator(shared_ptr<T[]> data, size_t size, size_t index)
    : _data(data), _size(size), _index(index)
{}

template<typename T>
const T *ConstIterator<T>::operator->() const
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template<typename T>
const T &ConstIterator<T>::operator*() const
{
    if (_index >= _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired()) {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator+(size_t diff) const
{
    ConstIterator<T> it(*this);
    it._index += diff;
    return it;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator-(size_t diff) const
{
    ConstIterator<T> it(*this);
    it._index -= diff;
    return it;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++() const
{
    ++_index;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) const
{
    ConstIterator<T> it(*this);
    ++(*this);
    return it;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator--() const
{
    --_index;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) const
{
    ConstIterator<T> it(*this);
    --(*this);
    return it;
}

template<typename T>
void Vector<T>::_allocateMemory(size_t size)
{
    shared_ptr<T[]> tmp;
    try {
        tmp.reset(new T[size]);
    } catch (std::bad_alloc &) {
        time_t curTime = time(NULL);
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    for (size_t i = 0; i < std::min(size, _size); i++)
        tmp[i] = _data[i];
    _data = tmp;
    _size = size;
}

template<typename T>
Vector<T>::Vector(){};

template<typename T>
Vector<T>::Vector(size_t size)
{
    _allocateMemory(size);
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &vec)
{
    _allocateMemory(vec._size);
    for (size_t i = 0; i < _size; ++i)
        _data[i] = vec[i];
    return *this;
}

template<typename T>
Vector<T>::Vector(const Vector &vec)
{
    _allocateMemory(vec._size);
    for (size_t i = 0; i < vec._size; ++i)
        _data[i] = vec[i];
};

template<typename T>
T &Vector<T>::operator[](size_t index)
{
    if (index > _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data[index];
};

template<typename T>
const T &Vector<T>::operator[](size_t index) const
{
    if (index > _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data[index];
};

template<typename T>
void Vector<T>::push_back(T elem)
{
    _allocateMemory(_size + 1);
    _data[_size - 1] = elem;
}

template<typename T>
void Vector<T>::erase(VecIterator<T> di)
{
    auto si = di + 1;
    while (si != end())
        *di++ = *si++;
    _allocateMemory(_size - 1);
}

template<typename T>
bool Vector<T>::isEmpty() const
{
    return true ? this->_size : false;
}

template<typename T>
VecIterator<T> Vector<T>::begin()
{
    return VecIterator<T>(_data, _size);
}

template<typename T>
ConstIterator<T> Vector<T>::begin() const
{
    return ConstIterator<T>(_data, _size);
}

template<typename T>
VecIterator<T> Vector<T>::end()
{
    return VecIterator<T>(_data, _size, _size);
}

template<typename T>
ConstIterator<T> Vector<T>::end() const
{
    return ConstIterator<T>(_data, _size, _size);
}
