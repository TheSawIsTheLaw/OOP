#include "mainwindow.h"
#include "modelDomain.h"

#include "defines.h"

// Возможно, следует рассматривать случай, когда подана уже использованная модель

int isModelInited(modelT &model){
    if (!model.edges || !model.nodes || model.numOfEdges <= 0 || model.numOfNodes <= 0)
        return MODEL_IS_NOT_INITED_ERROR;

    return SUCCESS;
}

int isModelReady(modelT &model){
    if (model.edges || model.nodes || model.numOfEdges != 0 || model.numOfNodes != 0)
        return MODEL_IS_NOT_READY_ERROR;

    return SUCCESS;
}

void initModel(modelT &model){
    QDEB("initModel")
    model.numOfEdges = 0;
    model.edges = nullptr;

    model.numOfNodes = 0;
    model.nodes = nullptr;

    model.distanceToUser = 1;
}

void freeModel(modelT &model){
    QDEB("freeModel")
    if (model.edges)
        free(model.edges);
    model.numOfEdges = 0;

    if (model.nodes)
        free(model.nodes);
    model.numOfNodes = 0;

    model.distanceToUser = 0;
}

int readModel(modelT &model, FILE *modelFile){
    QDEB("readModel")
    int check;

    check = fscanf(modelFile, "%d %d", &model.numOfNodes, &model.numOfEdges);
    if (check != 2)
        return FILE_STRUCTURE_ERROR;
    model.edges = (edgeT *)calloc(model.numOfEdges, sizeof(edgeT));
    if (!model.edges){
        freeModel(model);

        return MEMORY_ALLOCATION_ERROR;
    }

    model.nodes = (nodeT *)calloc(model.numOfNodes, sizeof(nodeT));
    if (!model.nodes){
        freeModel(model);

        return MEMORY_ALLOCATION_ERROR;
    }


    for (int i = 0; i < model.numOfNodes; i++){
        check = fscanf(modelFile, "%lf %lf %lf", &model.nodes[i].xCoord, &model.nodes[i].yCoord, &model.nodes[i].zCoord);

        if (check != 3){
            freeModel(model);

            return FILE_STRUCTURE_ERROR;
        }
    }

    for (int i = 0; i < model.numOfEdges; i++){
        check = fscanf(modelFile, "%d %d", &model.edges[i].firstNode, &model.edges[i].secondNode);

        if (check != 2){
            free(model.edges);
            model.numOfEdges = 0;

            free(model.nodes);
            model.numOfNodes = 0;

            return FILE_STRUCTURE_ERROR;
        }
    }

    return SUCCESS;
}

int readModelWrap(modelT &model, FILE *modelFile){
    QDEB("readModelWrap")
    if (!modelFile)
        return FILE_ERROR;

    int check;
    check = isModelReady(model);

    if (check)
        return check;

    check = readModel(model, modelFile);
    if (check)
        return check;

    return SUCCESS;
}

int showModelWrap(modelT &model){
    int check;
    check = isModelInited(model);

    if (check)
        return check;

    return SUCCESS;
}

int setModel(QString wayToFile, modelT &model){
    QDEB("setModel")
    initModel(model);

    FILE *modelFile = fopen(qUtf8Printable(wayToFile), "r");
    if (!modelFile)
        return FILE_ERROR;

    int check = readModelWrap(model, modelFile);
    if (check){
        fclose(modelFile);

        return check;
    }

    fclose(modelFile);

#if DEBUG == 1
    for (int i = 0; i < model.numOfNodes; i++)
        qDebug("%f %f %f\n", model.nodes[i].xCoord, model.nodes[i].yCoord, model.nodes[i].zCoord);

    for (int i = 0; i < model.numOfEdges; i++)
        qDebug("%d %d\n", model.edges[i].firstNode, model.edges[i].secondNode);
#endif

    check = showModelWrap(model);
    if (check){
        freeModel(model);

        return check;
    }

    return SUCCESS;
}

void moveModel(int direction, nodeT *nodes, int numOfNodes){
    int moveDirection;
    if (!direction || direction == 3){
        if (direction)
            moveDirection = 10;
        else
            moveDirection = -10;
        for (int i = 0; i < numOfNodes; i++)
            nodes[i].xCoord += moveDirection;
    }
    else{
        if (direction == 2)
            moveDirection = -10;
        else
            moveDirection = 10;
        for (int i = 0; i < numOfNodes; i++)
            nodes[i].yCoord += moveDirection;
    }
}

int moveModelWarp(int direction, nodeT *nodes, int numOfNodes){
    if (direction < GO_LEFT || direction > GO_RIGHT)
        return WRONG_DIRECTION_ERROR;

    if (!nodes)
        return INVALID_NODES_MOVE_POINTER_ERROR;

    if (numOfNodes <= 0)
        return WRONG_NUMBER_OF_NODES_ERROR;

    moveModel(direction, nodes, numOfNodes);

    return SUCCESS;
}
