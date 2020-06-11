#ifndef VECTORR_H
#define VECTORR_H

#include "../Exceptions/exceptions.h"
#include "Vector.h"
#include "time.h"

template<typename T>
void Vector<T>::_allocateMemory(size_t size)
{
    shared_ptr<T[]> tmp;
    try {
        tmp.reset(new T[size]);
    } catch (std::bad_alloc &) {
        time_t curTime = time(NULL);
        throw MemoryException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
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
    _allocateMemory(vec.size());
    for (size_t i = 0; i < _size; ++i)
        _data[i] = vec[i];
    return *this;
}

template<typename T>
Vector<T>::Vector(const Vector &vec)
{
    _allocateMemory(vec.size());
    for (size_t i = 0; i < vec.size(); ++i)
        _data[i] = vec[i];
};

template<typename T>
T &Vector<T>::operator[](size_t index)
{
    if (index > _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }

    return _data[index];
};

template<typename T>
const T &Vector<T>::operator[](size_t index) const
{
    if (index > _size) {
        time_t curTime = time(NULL);
        throw OutOfRangeException(__FILE__, tyoeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return _data[index];
};

template<typename T>
void Vector<T>::pushBack(T elem)
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

#endif // VECTORR_H
