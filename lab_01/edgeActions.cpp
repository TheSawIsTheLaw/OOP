#include "edgeActions.h"

#include "pointActions.h"

//! Scan
int scanEdgeFromFile(edgeT &edge, FILE *const modelFile) {
    int read = 0;
    if (!modelFile)
        return read;

    read += scanPointSerNumFromFile(edge.firstNode, modelFile);

    read += scanPointSerNumFromFile(edge.secondNode, modelFile);

    return read;
}
//< End

//! Copy
void copyEdge(edgeT &edgeTo, const edgeT edgeFrom){
    edgeTo = edgeFrom;
}
//< End
