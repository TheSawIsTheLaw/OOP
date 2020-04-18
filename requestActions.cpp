#include "requestActions.h"

#include "defines.h"


//! Reset Request
//!
//! Никак не получается просто отработать с проверкой на choice, так как в таком
//! случае может получиться так, что пользователь после использования структуры
//! в разных целях освободит только часть занятой памяти.
//! Все данные зануляются для того, чтобы нельзя было внезапно достать информацию
//! предыдущего использования.
void resetRequest(requestT &request) {
    if (request.ui)
        request.ui = nullptr;
    if (request.choice)
        request.choice = EMPTY;
    if (request.moveRequest.bias)
        request.moveRequest.bias = EMPTY;
    if (request.moveRequest.direction)
        request.moveRequest.direction = EMPTY;
    if (request.scaleRequest.scaleCoef)
        request.scaleRequest.scaleCoef = EMPTY;
    if (request.scaleRequest.xCenterScene)
        request.scaleRequest.xCenterScene = EMPTY;
    if (request.scaleRequest.yCenterScene)
        request.scaleRequest.yCenterScene = EMPTY;
    if (request.scaleRequest.zCenterScene)
        request.scaleRequest.zCenterScene = EMPTY;
    if (request.rotateRequest.angle)
        request.rotateRequest.angle = EMPTY;
    if (request.rotateRequest.direction)
        request.rotateRequest.direction = EMPTY;
}
//< End

//! Free
void freeFileNameRequest(requestT &request) {
    if (request.fileName)
        free(request.fileName);
}
//< End

//! Move set
void setMoveChoice(requestT &request, const int direction,
                   const int bias) {
    request.choice = MOVEMENT;
    setMoveRequest(request.moveRequest, direction, bias);
}

void setMoveRequest(moveRequestT &request, const int direction,
                    const int bias) {
    request.bias = bias;
    request.direction = direction;
}
//< End

// Rotation set
void setRotateChoiceZ(requestT &request, const int xCenter,
                      const int yCenter, const float angle) {
    request.choice = ROTATION;
    setRotateRequestZ(request.rotateRequest, ROTATE_Z,
                      xCenter, yCenter, angle);
}

void setRotateChoiceY(requestT &request, const int xCenter,
                      const int zCenter, const float angle) {
    request.choice = ROTATION;
    setRotateRequestY(request.rotateRequest, ROTATE_Y,
                     xCenter, zCenter, angle);
}

void setRotateChoiceX(requestT &request, const int yCenter,
                      const int zCenter, const float angle) {
    request.choice = ROTATION;
    setRotateRequestX(request.rotateRequest, ROTATE_X,
                     yCenter, zCenter, angle);
}

void setRotateRequestZ(rotateRequestT &request, const int direction,
                       const int xCenter, const int yCenter,
                       const float angle) {
    request.angle = angle;
    request.xCenterScene = xCenter;
    request.yCenterScene = yCenter;
    request.direction = direction;
}

void setRotateRequestY(rotateRequestT &request, const int direction,
                       const int xCenter, const int zCenter,
                       const float angle) {
    request.angle = angle;
    request.xCenterScene = xCenter;
    request.zCenterScene = zCenter;
    request.direction = direction;
}

void setRotateRequestX(rotateRequestT &request, const int direction,
                       const int yCenter, const int zCenter,
                       const float angle) {
    request.angle = angle;
    request.yCenterScene = yCenter;
    request.zCenterScene = zCenter;
    request.direction = direction;
}
//< End

//! Scale set
void setScaleChoice(requestT &request, const float scaleCoef,
                    const int xCenter, const int yCenter,
                    const int zCenter) {
    request.choice = SCALE;
    setScaleRequest(request.scaleRequest, scaleCoef,
                    xCenter, yCenter, zCenter);
}

void setScaleRequest(scaleRequestT &request, const float scaleCoef,
                     const int xCenter, const int yCenter,
                     const int zCenter) {
    request.scaleCoef = scaleCoef;
    request.xCenterScene = xCenter;
    request.yCenterScene = yCenter;
    request.zCenterScene = zCenter;
}
//< End

//! Load set
int setLoadRequest(requestT &request, const QString qFileName) {
    request.fileName = (char *)calloc(qFileName.length(), sizeof(char));
    if (!request.fileName)
        return MEMORY_ALLOCATION_ERROR;
    request.choice = LOAD_MODEL;
    strcpy(request.fileName, qUtf8Printable(qFileName));
    return SUCCESS;
}
//< End

//! Show set
int setShowRequest(requestT &request, Ui::MainWindow *const ui) {
    if (!ui)
        return UI_POINTER_ERROR;
    request.choice = SHOW_MODEL;
    request.ui = ui;
    return SUCCESS;
}
//< End
