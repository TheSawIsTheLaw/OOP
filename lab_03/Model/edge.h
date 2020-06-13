#ifndef EDGE_H
#define EDGE_H

#include "stdio.h"

class Edge
{
public:
    Edge() = default;
    Edge(size_t fNode, size_t sNode);
    ~Edge() = default;

    size_t getFNodeNum();
    size_t getSNodeNum();

private:
    size_t firstNode, secondNode;
};

#endif // EDGE_H
