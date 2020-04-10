#include "modelDomain.h"

#include "defines.h"


//! Checks
int isModelInited(const modelT &model) {
    if (!model.edges || !model.nodes || model.numOfEdges <= EMPTY ||
        model.numOfNodes <= EMPTY)
        return MODEL_IS_NOT_INITED_ERROR;

    return SUCCESS;
}

int isModelReady(const modelT &model) {
    if (model.edges || model.nodes || model.numOfEdges != EMPTY ||
        model.numOfNodes != EMPTY)
        return MODEL_IS_NOT_READY_ERROR;

    return SUCCESS;
}
//< End

//! Initialization and free
modelT &initModel() {
    QDEB("initModel")
    static modelT model;

    if (!model.numOfEdges)
        model.numOfEdges = EMPTY;
    if (!model.edges)
        model.edges = nullptr;

    if (!model.numOfNodes)
        model.numOfNodes = EMPTY;
    if (!model.nodes)
        model.nodes = nullptr;

    if (!model.distanceToUser)
        model.distanceToUser = BASE;
    return model;
}

void freeModel(modelT &model) {
    QDEB("freeModel")
    if (model.edges) free(model.edges);
    model.numOfEdges = EMPTY;

    if (model.nodes) free(model.nodes);
    model.numOfNodes = EMPTY;

    model.distanceToUser = EMPTY;
}
//< End


//! Wrap
int readModelWrap(modelT &model, FILE *const modelFile) {
    QDEB("readModelWrap")
    if (!modelFile)
        return FILE_ERROR;

    int check;
    check = isModelReady(model);

    if (check) {
        model.edges = nullptr;
        model.nodes = nullptr;
        model.numOfEdges = 0;
        model.numOfNodes = 0;
    }

    check = readModel(model, modelFile);
    if (check)
        return check;

    return SUCCESS;
}
//< End

//! Actions
int readModel(modelT &model, FILE *const modelFile) {
    QDEB("readModel")
    int check;

    check = fscanf(modelFile, "%d %d",
                   &model.numOfNodes,
                   &model.numOfEdges);
    if (check != 2)
        return FILE_STRUCTURE_ERROR;

    model.edges = (edgeT *)calloc(model.numOfEdges, sizeof(edgeT));
    if (!model.edges) {
        freeModel(model);

        return MEMORY_ALLOCATION_ERROR;
    }

    model.nodes = (nodeT *)calloc(model.numOfNodes, sizeof(nodeT));
    if (!model.nodes) {
        freeModel(model);

        return MEMORY_ALLOCATION_ERROR;
    }

    for (int i = 0; i < model.numOfNodes; i++) {
        check = fscanf(modelFile, "%lf %lf %lf",
                       &model.nodes[i].xCoord,
                       &model.nodes[i].yCoord,
                       &model.nodes[i].zCoord);

        if (check != 3) {
            freeModel(model);

            return FILE_STRUCTURE_ERROR;
        }
    }

    for (int i = 0; i < model.numOfEdges; i++) {
        check = fscanf(modelFile, "%d %d",
                       &model.edges[i].firstNode,
                       &model.edges[i].secondNode);

        if (check != 2) {
            free(model.edges);
            model.numOfEdges = EMPTY;

            free(model.nodes);
            model.numOfNodes = EMPTY;

            return FILE_STRUCTURE_ERROR;
        }
    }

    return SUCCESS;
}

int setModel(modelT &model, const QString wayToFile) {
    QDEB("setModel")

    FILE * modelFile = fopen(qUtf8Printable(wayToFile), "r");
    if (!modelFile)
        return FILE_ERROR;

    int check = readModelWrap(model, modelFile);
    if (check) {
        fclose(modelFile);

        return check;
    }

    fclose(modelFile);

#if DEBUG == 1
    for (int i = 0; i < model.numOfNodes; i++)
        qDebug("%f %f %f\n", model.nodes[i].xCoord,
                             model.nodes[i].yCoord,
                             model.nodes[i].zCoord);

    for (int i = 0; i < model.numOfEdges; i++)
        qDebug("%d %d\n", model.edges[i].firstNode,
                          model.edges[i].secondNode);
#endif

    if (check) {
        freeModel(model);

        return check;
    }

    return SUCCESS;
}
//< End
