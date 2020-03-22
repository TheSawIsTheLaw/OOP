#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H
#include "mainwindow.h"

typedef struct{
    double xCoord;
    double yCoord;
    double zCoord;
}nodeT;

typedef struct{
    int firstNode;
    int secondNode;
}edgeT;

typedef struct{
    int numOfNodes;
    nodeT *nodes;
    int numOfEdges;
    edgeT *edges;
    int distanceToUser;
}modelT;

int setModel(QString wayToFile, modelT &model);

void initModel(modelT &model);

int readModelWrap(modelT &model, FILE *modelFile);

int readModel(modelT &model, FILE *modelFile);

int showModelWrap(modelT &model);

void showModel(modelT &model);

#endif // MODEL_DOMAIN_H

