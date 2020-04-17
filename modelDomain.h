#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H

#include "nodeLevel.h"

#include "edgeLevel.h"

#include "stdio.h"


//! model
typedef struct {
    int numOfNodes;
    nodeT *nodes;
    int numOfEdges;
    edgeT *edges;
    int distanceToUser;
} modelT;
//< End

// Check
int isModelEmpty(const modelT &model);

// Set model
int loadModel(modelT &model, const char *const fileName);

// Init model
modelT &initModel();

//! Read model
int readModelWrap(modelT &model, FILE *const modelFile);
int readModel(modelT &model, FILE *const modelFile);
//< End

#endif  // MODEL_DOMAIN_H
