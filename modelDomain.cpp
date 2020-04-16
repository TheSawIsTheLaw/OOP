#include "modelDomain.h"

#include "defines.h"

#include "stdlib.h"

#include "mainwindow.h"


//! Checks
int isModelInited(const modelT &model) {
    if (!model.edges || !model.nodes || model.numOfEdges <= EMPTY ||
        model.numOfNodes <= EMPTY)
        return MODEL_IS_NOT_INITED_ERROR;

    return SUCCESS;
}
//< End

//! Initialization and free
modelT &initModel() {
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
    if (model.edges) free(model.edges);
    model.numOfEdges = EMPTY;

    if (model.nodes) free(model.nodes);
    model.numOfNodes = EMPTY;

    model.distanceToUser = EMPTY;
}

modelT &initModelCopy() {
    static modelT modelCopy;

    if (!modelCopy.numOfEdges)
        modelCopy.numOfEdges = EMPTY;
    if (!modelCopy.edges)
        modelCopy.edges = nullptr;

    if (!modelCopy.numOfNodes)
        modelCopy.numOfNodes = EMPTY;
    if (!modelCopy.nodes)
        modelCopy.nodes = nullptr;

    if (!modelCopy.distanceToUser)
        modelCopy.distanceToUser = BASE;
    return modelCopy;
}

int copyModelToModel(modelT &modelTo, modelT modelFrom) {
    modelTo.numOfEdges = modelFrom.numOfEdges;
    modelTo.numOfNodes = modelFrom.numOfNodes;
    int check = SUCCESS;

    check = copyEdgesToEdges(modelTo.edges, modelFrom.edges, modelFrom.numOfEdges);
    if (check)
        return check;

    check = copyNodesToNodes(modelTo.nodes, modelFrom.nodes, modelFrom.numOfNodes);
    if (check)
        return check;

    modelTo.distanceToUser = modelFrom.distanceToUser;
    return check;
}
//< End


//! Wrap
//! FIXED БЫДЛОКОД!
//! FIXED Реорганизация процесса! Первоначальная работа над копией и только потом, при SUCCESS,
//! перенос в неё
int readModelWrap(modelT &model, FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    static modelT modelCopy = initModelCopy();

    int check = readModel(modelCopy, modelFile);

    if (!check)
        check = copyModelToModel(model, modelCopy);

    freeModel(modelCopy);

    return check;
}
//< End

//! Actions
//! FIX ЛЮТЫЙ ГОВНОКОД, ТУТ ЗАМЕШАНО ТРИ УРОВНЯ АБСТРАКЦИИ
int readModel(modelT &model, FILE *const modelFile) {
    int check;

    // FIXED включены проверки, переход на новый уровень абстракции
    check = getNumOfNodesFromFile(model.numOfNodes, modelFile);
    if (check)
        return check;

    check = getNumOfEdgesFromFile(model.numOfEdges, modelFile);
    if (check)
        return check;

    // FIXED Check более не отвечает за количество прочтённых символов

    // Так как мы теперь работаем с копией, освобождение проводится
    // в конце при любом исходе

    check = scanModelNodesFromFile(model.nodes, model.numOfNodes, modelFile);
    if (check)
        return check;

    check = scanModelEdgesFromFile(model.edges, model.numOfEdges, modelFile);

    return check;
}

int loadModel(modelT &model, const char *fileName) {
    if (!fileName)
        return FILE_ERROR;

    FILE *modelFile = fopen(fileName, "r");
    if (!modelFile)
        return FILE_ERROR;

    int check = readModelWrap(model, modelFile);
    fclose(modelFile);

    return check;
}
//< End
