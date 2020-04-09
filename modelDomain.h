#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H

#include "mainwindow.h"
#include "edgeLevel.h"
#include "nodeLevel.h"
#include <math.h>


//! model
typedef struct {
    int numOfNodes;
    nodeT *nodes;
    int numOfEdges;
    edgeT *edges;
    int distanceToUser;
} modelT;
//< End

/// ! WRAPS HERE ARE CHECKS FOR UNITIALIZED/WRONG DATA

// Check
int isModelInited(const modelT &model);

// Set model
int setModel(const QString wayToFile, modelT &model);

// Init model
modelT &initModel();

//! Read model
int readModelWrap(modelT &model, FILE *const modelFile);
int readModel(modelT &model, FILE *const modelFile);
//< End

#endif  // MODEL_DOMAIN_H
