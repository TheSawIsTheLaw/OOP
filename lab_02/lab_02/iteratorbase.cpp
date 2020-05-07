#include "IteratorBase.h"

IteratorBase::IteratorBase()
{
    currentIndex = 0;
    vectorLen = 0;
}

IteratorBase::IteratorBase(const IteratorBase &iterFrom) {
    currentIndex = iterFrom.currentIndex;
    vectorLen = iterFrom.vectorLen;
}

IteratorBase::~IteratorBase() {
    currentIndex = 0;
    vectorLen = 0;
}
