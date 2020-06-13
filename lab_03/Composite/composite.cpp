#include "composite.h"

Composite::Composite() {}

void Composite::accept(const ComponentVisitorBase &) {}

bool Composite::isComposite()
{
    return true;
}

void Composite::add() {}

void Composite::del() {}

// CompIterator *Composite()
