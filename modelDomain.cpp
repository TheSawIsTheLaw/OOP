#include "mainwindow.h"
#include "modelDomain.h"

#include "defines.h"

//! Checks
int isModelInited(const modelT& model) {
  if (!model.edges || !model.nodes || model.numOfEdges <= 0 ||
      model.numOfNodes <= 0)
    return MODEL_IS_NOT_INITED_ERROR;

  return SUCCESS;
}

int isModelReady(const modelT& model) {
  if (model.edges || model.nodes || model.numOfEdges != 0 ||
      model.numOfNodes != 0)
    return MODEL_IS_NOT_READY_ERROR;

  return SUCCESS;
}
//< End

//! Initialization and free
void initModel(modelT& model) {
  QDEB("initModel")
  model.numOfEdges = 0;
  model.edges = nullptr;

  model.numOfNodes = 0;
  model.nodes = nullptr;

  model.distanceToUser = 1;
}

void freeModel(modelT& model) {
  QDEB("freeModel")
  if (model.edges) free(model.edges);
  model.numOfEdges = 0;

  if (model.nodes) free(model.nodes);
  model.numOfNodes = 0;

  model.distanceToUser = 0;
}

int areNodesLigit(const nodeT* const nodes, const int numOfNodes) {
  if (!nodes) return INVALID_NODES_MOVE_POINTER_ERROR;

  if (numOfNodes <= 0) return WRONG_NUMBER_OF_NODES_ERROR;

  return SUCCESS;
}
//< End

//! Actions
int readModel(modelT& model, FILE* const modelFile) {
  QDEB("readModel")
  int check;

  check = fscanf(modelFile, "%d %d", &model.numOfNodes, &model.numOfEdges);
  if (check != 2) return FILE_STRUCTURE_ERROR;

  model.edges = (edgeT*)calloc(model.numOfEdges, sizeof(edgeT));
  if (!model.edges) {
    freeModel(model);

    return MEMORY_ALLOCATION_ERROR;
  }

  model.nodes = (nodeT*)calloc(model.numOfNodes, sizeof(nodeT));
  if (!model.nodes) {
    freeModel(model);

    return MEMORY_ALLOCATION_ERROR;
  }

  for (int i = 0; i < model.numOfNodes; i++) {
    check = fscanf(modelFile, "%lf %lf %lf", &model.nodes[i].xCoord,
                   &model.nodes[i].yCoord, &model.nodes[i].zCoord);

    if (check != 3) {
      freeModel(model);

      return FILE_STRUCTURE_ERROR;
    }
  }

  for (int i = 0; i < model.numOfEdges; i++) {
    check = fscanf(modelFile, "%d %d", &model.edges[i].firstNode,
                   &model.edges[i].secondNode);

    if (check != 2) {
      free(model.edges);
      model.numOfEdges = 0;

      free(model.nodes);
      model.numOfNodes = 0;

      return FILE_STRUCTURE_ERROR;
    }
  }

  return SUCCESS;
}

int setModel(const QString wayToFile, modelT& model) {
  QDEB("setModel")
  initModel(model);

  FILE* modelFile = fopen(qUtf8Printable(wayToFile), "r");
  if (!modelFile) return FILE_ERROR;

  int check = readModelWrap(model, modelFile);
  if (check) {
    fclose(modelFile);

    return check;
  }

  fclose(modelFile);

#if DEBUG == 1
  for (int i = 0; i < model.numOfNodes; i++)
    qDebug("%f %f %f\n", model.nodes[i].xCoord, model.nodes[i].yCoord,
           model.nodes[i].zCoord);

  for (int i = 0; i < model.numOfEdges; i++)
    qDebug("%d %d\n", model.edges[i].firstNode, model.edges[i].secondNode);
#endif

  check = showModelWrap(model);
  if (check) {
    freeModel(model);

    return check;
  }

  return SUCCESS;
}

void moveModel(const int direction, nodeT* const nodes, const int numOfNodes) {
  int moveDirection;
  if (!direction || direction == 3) {
    if (direction)
      moveDirection = 10;
    else
      moveDirection = -10;
    for (int i = 0; i < numOfNodes; i++) nodes[i].xCoord += moveDirection;
  } else {
    if (direction == 2)
      moveDirection = -10;
    else
      moveDirection = 10;
    for (int i = 0; i < numOfNodes; i++) nodes[i].yCoord += moveDirection;
  }
}

void zRotateModel(const int direction, nodeT* const nodes,
                  const int numOfnodes) {
  double rotateAngle = PI_EIGHTEEN;
  if (direction == ROTATE_Z_R) rotateAngle *= -1;

  double xTemp, yTemp;
  for (int i = 0; i < numOfnodes; i++) {
    xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(rotateAngle);
    yTemp = Y_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(rotateAngle);

    nodes[i].xCoord = xTemp;
    nodes[i].yCoord = yTemp;
  }
}

void yRotateModel(const int direction, nodeT* const nodes,
                  const int numOfnodes) {
  double rotateAngle = PI_EIGHTEEN;
  if (direction == ROTATE_Y_R) rotateAngle *= -1;

  double xTemp, zTemp;
  for (int i = 0; i < numOfnodes; i++) {
    xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(rotateAngle);
    zTemp = Z_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(rotateAngle);

    nodes[i].xCoord = xTemp;
    nodes[i].zCoord = zTemp;
  }
}

void xRotateModel(const int direction, nodeT* const nodes,
                  const int numOfnodes) {
  double rotateAngle = PI_EIGHTEEN;
  if (direction == ROTATE_X_R) rotateAngle *= -1;

  double yTemp, zTemp;
  for (int i = 0; i < numOfnodes; i++) {
    yTemp = Y_CENTER_SCENE +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(rotateAngle);
    zTemp = Z_CENTER_SCENE -
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(rotateAngle);

    nodes[i].yCoord = yTemp;
    nodes[i].zCoord = zTemp;
  }
}

void scaleModel(const int direction, nodeT* const nodes, const int numOfnodes) {
  double scaleCoef = 0.9;
  if (direction == SCALE_PLUS) scaleCoef = 1.1;

  qDebug("scale");

  for (int i = 0; i < numOfnodes; i++) {
    nodes[i].xCoord =
        nodes[i].xCoord * scaleCoef + (1 - scaleCoef) * X_CENTER_SCENE;
    nodes[i].yCoord =
        nodes[i].yCoord * scaleCoef + (1 - scaleCoef) * Y_CENTER_SCENE;
    nodes[i].zCoord =
        nodes[i].zCoord * scaleCoef + (1 - scaleCoef) * Z_CENTER_SCENE;
  }
}
// End

//! Wraps
int readModelWrap(modelT& model, FILE* const modelFile) {
  QDEB("readModelWrap")
  if (!modelFile) return FILE_ERROR;

  int check;
  check = isModelReady(model);

  if (check) return check;

  check = readModel(model, modelFile);
  if (check) return check;

  return SUCCESS;
}

int showModelWrap(const modelT& model) {
  int check;
  check = isModelInited(model);

  if (check) return check;

  return SUCCESS;
}

int moveModelWrap(const int direction, nodeT* const nodes,
                  const int numOfNodes) {
  if (direction < GO_LEFT || direction > GO_RIGHT) return WRONG_DIRECTION_ERROR;

  int check;
  check = areNodesLigit(nodes, numOfNodes);

  if (check) return check;

  moveModel(direction, nodes, numOfNodes);

  return SUCCESS;
}

int zRotateModelWrap(const int direction, nodeT* const nodes,
                     const int numOfNodes) {
  if (direction < ROTATE_Z_R || direction > ROTATE_Z_L)
    return WRONG_DIRECTION_ERROR;

  int check;
  check = areNodesLigit(nodes, numOfNodes);

  if (check) return check;

  zRotateModel(direction, nodes, numOfNodes);

  return SUCCESS;
}

int yRotateModelWrap(const int direction, nodeT* const nodes,
                     const int numOfNodes) {
  if (direction < ROTATE_Y_R || direction > ROTATE_Y_L)
    return WRONG_DIRECTION_ERROR;

  int check;
  check = areNodesLigit(nodes, numOfNodes);

  if (check) return check;

  yRotateModel(direction, nodes, numOfNodes);

  return SUCCESS;
}

int xRotateModelWrap(const int direction, nodeT* const nodes,
                     const int numOfNodes) {
  if (direction < ROTATE_X_R || direction > ROTATE_X_L)
    return WRONG_DIRECTION_ERROR;

  int check;
  check = areNodesLigit(nodes, numOfNodes);

  if (check) return check;

  xRotateModel(direction, nodes, numOfNodes);

  return SUCCESS;
}

int scaleModelWrap(const int direction, nodeT* const nodes,
                   const int numOfNodes) {
  if (direction < SCALE_PLUS || direction > SCALE_MINUS)
    return WRONG_DIRECTION_ERROR;

  int check;
  check = areNodesLigit(nodes, numOfNodes);

  if (check) return check;

  scaleModel(direction, nodes, numOfNodes);

  return SUCCESS;
}
//< End
