#ifndef VECTORBASE_H
#define VECTORBASE_H

#include <cstddef>

class VectorBase {
public:
    VectorBase(size_t vectorSize = 0): vectorSize(vectorSize) { }

    virtual size_t size() const noexcept {
        return vectorSize;
    };

    virtual operator bool() const noexcept {
        return bool(vectorSize);
    }

    virtual ~VectorBase() = 0;

protected:
    size_t vectorSize = 0;
};

VectorBase::~VectorBase() { }

#endif // VECTORBASE_H
