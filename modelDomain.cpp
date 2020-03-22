#include "mainwindow.h"
#include "modelDomain.h"

#include "defines.h"

int setModel(QString wayToFile, modelT &model){
    int check = initModelWrap(model);
    if (check)
        return check;

    FILE *modelFile = fopen(qUtf8Printable(wayToFile), "r");
    if (!modelFile)
        return FILE_ERROR;

    check = readModelWprap(model, modelFile);
    if (check){
        fclose(modelFile);
        return check;
    }

    fclose(modelFile);

    return SUCCESS;
}
