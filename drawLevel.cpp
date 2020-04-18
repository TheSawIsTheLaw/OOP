#include "drawLevel.h"

#include "mainwindow.h"

#include "defines.h"

int drawModelQtWrap(modelT model, requestT request) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    if (!request.ui)
        return UI_POINTER_ERROR;

    drawModelQt(model, request.ui);

    return SUCCESS;
}

int drawModelWrap(modelT model, requestT request) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    int check = drawModelQtWrap(model, request);

    return check;
}

