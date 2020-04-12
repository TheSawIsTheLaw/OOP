#include "requestActions.h"

#include "defines.h"


//! Free Request
//!
//! Никак не получается просто отработать с проверкой на choice, так как в таком
//! случае может получиться так, что пользователь после использования структуры
//! в разных целях освободит только часть занятой памяти.
//! Все данные зануляются для того, чтобы нельзя было внезапно достать информацию
//! предыдущего использования.
void freeRequest(requestT &request) {
    if (request.ui)
        request.ui = nullptr;
    if (request.choice)
        request.choice = EMPTY;
    if (request.fileName)
        free(request.fileName);
    if (request.moveRequest.bias)
        request.moveRequest.bias = 0;
    if (request.moveRequest.direction)
        request.moveRequest.direction = 0;
    if (request.scaleRequest.scaleCoef)
        request.scaleRequest.scaleCoef = 0;
    if (request.scaleRequest.xCenterScene)
        request.scaleRequest.xCenterScene = 0;
    if (request.scaleRequest.yCenterScene)
        request.scaleRequest.yCenterScene = 0;
    if (request.scaleRequest.zCenterScene)
        request.scaleRequest.zCenterScene = 0;
    if (request.rotateRequest.angle)
        request.rotateRequest.angle = 0;
    if (request.rotateRequest.direction)
        request.rotateRequest.direction = 0;
}
//< End

void setMoveChoice(requestT &request, int direction,
                   int bias) {
    request.choice = MOVEMENT;
    setMoveRequest(request.moveRequest, direction, bias);
}

void setMoveRequest(moveRequestT &request, int direction,
                    int bias) {
    request.bias = bias;
    request.direction = direction;
}

void setRotateChoice(requestT &request, int direction,
                     float angle) {
    request.choice = ROTATION;
    setRotateRequest(request.rotateRequest, direction, angle);
}

void setRotateRequest(rotateRequestT &request, int direction,
                      float angle) {
    request.angle = angle;
    request.direction = direction;
}

void setScaleChoice(requestT &request, int scaleCoef,
                    int xCenter, int yCenter, int zCenter) {
    request.choice = SCALE;
    setScaleRequest(request.scaleRequest, scaleCoef,
                    xCenter, yCenter, zCenter);
}

void setScaleRequest(scaleRequestT &request, int scaleCoef,
                     int xCenter, int yCenter, int zCenter) {
    request.scaleCoef = scaleCoef;
    request.xCenterScene = xCenter;
    request.yCenterScene = yCenter;
    request.zCenterScene = zCenter;
}

int setLoadRequest(requestT &request, QString qFileName) {
    request.fileName = (char *)calloc(qFileName.length(), sizeof(char));
    if (!request.fileName) {
        return MEMORY_ALLOCATION_ERROR;
    }
    request.choice = LOAD_MODEL;
    strcpy(request.fileName, qUtf8Printable(qFileName));
    return SUCCESS;
}

int setShowRequest(requestT &request, Ui::MainWindow *const ui) {
    if (!ui)
        return UI_POINTER_ERROR;
    request.choice = SHOW_MODEL;
    request.ui = ui;
    return SUCCESS;
}
