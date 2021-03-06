#ifndef EDGE_ACTIONS_H
#define EDGE_ACTIONS_H

#include "edgeLevel.h"

//! Scan
int scanEdgeFromFile(edgeT &edge, FILE *const modelFile);
//< End

//! Copy
void copyEdge(edgeT &edgeTo, const edgeT edgeFrom);
//< End

#endif // EDGE_ACTIONS_H
