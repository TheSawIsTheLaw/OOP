#include "edge.h"

Edge::Edge(size_t fNode, size_t sNode) : firstNode(fNode), secondNode(sNode) {}

size_t Edge::getFNodeNum()
{
    return firstNode;
}

size_t Edge::getSNodeNum()
{
    return secondNode;
}
