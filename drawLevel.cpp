#include "drawLevel.h"

#include "defines.h"

QPen initBlackPen(void) {
    static QPen blackPen(Qt::black);
    return blackPen;
}

int drawModelQtWrap(modelT model, const Ui::MainWindow *const ui) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    if (!ui)
        return UI_POINTER_ERROR;

    drawModelQt(model, ui);

    return SUCCESS;
}

int drawModelWrap(modelT model, requestT request) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    int check = drawModelQtWrap(model, request.ui);

    return check;
}

