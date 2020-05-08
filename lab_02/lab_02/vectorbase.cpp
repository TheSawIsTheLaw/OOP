#include "vectorbase.h"

VectorBase::VectorBase() {
    vectorSize = 0;
}

VectorBase::~VectorBase() {
    vectorSize = 0;
}

VectorBase::VectorBase(const VectorBase &fromBase) {
    vectorSize = fromBase.vectorSize;
}

bool VectorBase::isEmpty() const {
    return !vectorSize;
}

int VectorBase::size() const {
    return vectorSize;
}

