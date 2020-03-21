#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H
#include "mainwindow.h"

typedef struct{
    double xCoord;
    double yCoord;
    double zCoord;
}node_t;

typedef struct{
    int firstNode;
    int secondNode;
}edge_t;

typedef struct{

}model_t;

int setModel(QString wayToFile);

#endif // MODEL_DOMAIN_H

