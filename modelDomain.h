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
    nodeT *nodes;
    edgeT *edges;
}modelT;

int setModel(QString wayToFile, modelT &model);

int initModelWrap(modelT &model);

void initModel(modelT &model);

int readModelWprap(modelT &model, FILE *modelFile);

void readModel(modelT &model, FILE *modelFile);

#endif // MODEL_DOMAIN_H

