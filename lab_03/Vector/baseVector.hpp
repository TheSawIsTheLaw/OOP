#ifndef BASEVECTOR_HPP
#define BASEVECTOR_HPP

#include <cstddef>

class BaseVector
{
protected:
    size_t _size = 0;

public:
    virtual bool isEmpty() const;
};

#endif // BASEVECTOR_HPP
