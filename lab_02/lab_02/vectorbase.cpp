#include "vectorbase.h"

VectorBase::VectorBase() {
    vectorLen = 0;
}

VectorBase::~VectorBase() {
    vectorLen = 0;
}

VectorBase::VectorBase(const VectorBase &fromBase) {
    vectorLen = fromBase.vectorLen;
}

bool VectorBase::isEmpty() const {
    return !vectorLen;
}

int VectorBase::size() const {
    return vectorLen;
}

