#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H

#include <QFileDialog>

#include "edgeLevel.h"

#include "nodeLevel.h"


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
int isModelInited(const modelT &model);

// Set model
int setModel(modelT &model, const QString wayToFile);

// Init model
modelT &initModel();

//! Read model
int readModelWrap(modelT &model, FILE *const modelFile);
int readModel(modelT &model, FILE *const modelFile);
//< End

#endif  // MODEL_DOMAIN_H
