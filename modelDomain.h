#ifndef MODEL_DOMAIN_H
#define MODEL_DOMAIN_H

#include "mainwindow.h"
#include <math.h>

//! Node
typedef struct {
  double xCoord;
  double yCoord;
  double zCoord;
} nodeT;
//< End

//! Edge
typedef struct {
  int firstNode;
  int secondNode;
} edgeT;
//< End

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
void initModel(modelT &model);

//! Read model
int readModelWrap(modelT &model, FILE *const modelFile);
int readModel(modelT &model, FILE *const modelFile);
//< End

//! Show model
int showModelWrap(const modelT &model);
void showModel(const modelT &model);
//< End

//! Move model
int moveModelWrap(const int direction, nodeT *const nodes,
                  const int numOfNodes);
void moveModel(const int direction, nodeT *const nodes,
               const int numOfNodes);
//< End

//! Z rotate
int zRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes);
void zRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! Y rotate
int yRotateModelWrap(const int direction, nodeT *nodes,
                     const int numOfNodes);
void yRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! X rotate
int xRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes);
void xRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! Scale
int scaleModelWrap(const int direction, nodeT *const nodes,
                   const int numOfNodes);
void scaleModel(const int direction, nodeT *const nodes,
                const int numOfNodes);
// End

#endif  // MODEL_DOMAIN_H
