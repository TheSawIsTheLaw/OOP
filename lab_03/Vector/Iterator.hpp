#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Vector.hpp"
#include "time.h"

template <typename T>
VecIterator<T>::VecIterator() {};

template <typename T>
VecIterator<T>::VecIterator(shared_ptr<T[]> data, size_t size, size_t index)
    : _data(data)
    , _size(size)
    , _index(index) {};

template <typename T>
T *VecIterator<T>::operator->()
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template <typename T>
const T *VecIterator<T>::operator->() const
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template <typename T>
T &VecIterator<T>::operator*()
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template <typename T>
const T &VecIterator<T>::operator*() const
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template <typename T>
VecIterator<T> &VecIterator<T>::operator++()
{
    ++_index;
    return *this;
}

template <typename T>
VecIterator<T> VecIterator<T>::operator++(int)
{
    VecIterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
VecIterator<T> &VecIterator<T>::operator--()
{
    --_index;
    return *this;
}

template <typename T>
VecIterator<T> VecIterator<T>::operator--(int)
{
    VecIterator<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
VecIterator<T> VecIterator<T>::operator+(size_t diff) const
{
    VecIterator<T> it(*this);
    it._index += diff;
    return it;
}

template <typename T>
VecIterator<T> VecIterator<T>::operator-(size_t diff) const
{
    VecIterator<T> it(*this);
    it._index -= diff;
    return it;
}

template <typename T>
ConstIterator<T>::ConstIterator(shared_ptr<T[]> data, size_t size, size_t index)
    : _data(data)
    , _size(size)
    , _index(index)
{
}

template <typename T>
const T *ConstIterator<T>::operator->() const
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock() + _index;
}

template <typename T>
const T &ConstIterator<T>::operator*() const
{
    if (_index >= _size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeIterException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    if (_data.expired())
    {
        time_t curTime = time(NULL);
        throw InvalidIterator(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data.lock()[_index];
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator+(size_t diff) const
{
    ConstIterator<T> it(*this);
    it._index += diff;
    return it;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator-(size_t diff) const
{
    ConstIterator<T> it(*this);
    it._index -= diff;
    return it;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator++() const
{
    ++_index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) const
{
    ConstIterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator--() const
{
    --_index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) const
{
    ConstIterator<T> it(*this);
    --(*this);
    return it;
}

#endif // ITERATOR_HPP
