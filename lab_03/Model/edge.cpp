#include "edge.h"

Edge::Edge(size_t fNode, size_t sNode) : firstNode(fNode), secondNode(sNode) {}

Edge &Edge::get()
{
    return *this;
}
