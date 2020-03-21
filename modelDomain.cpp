#include "mainwindow.h"
#include "modelDomain.h"

#include "defines.h"

int setModel(QString wayToFile){
    FILE *modelFile = fopen(qUtf8Printable(wayToFile), "r");
    if (!modelFile)
        return FILE_ERROR;


    fclose(modelFile);

    return SUCCESS;
}
