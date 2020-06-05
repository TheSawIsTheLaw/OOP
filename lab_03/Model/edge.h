#ifndef EDGE_H
#define EDGE_H

#include "stdio.h"

class Edge
{
public:
    Edge();
    ~Edge() = default;

    Edge get();
    void set();

private:
    size_t firstNode, secondNode;
};

#endif // EDGE_H
