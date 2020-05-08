#include "iteratorbase.h"

IteratorBase::IteratorBase()
{
    currentIndex = 0;
    vectorLen = 0;
}

IteratorBase::IteratorBase(const IteratorBase &iterator) {
    currentIndex = iterator.currentIndex;
    vectorLen = iterator.vectorLen;
}

IteratorBase::~IteratorBase() {
    currentIndex = 0;
    vectorLen = 0;
}
