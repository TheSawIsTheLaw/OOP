#ifndef REQUEST_ACTIONS_H
#define REQUEST_ACTIONS_H

#pragma once
#include "mainwindow.h"

typedef struct {
    int direction;
    int bias;
}moveRequestT;

typedef struct {
    int direction;
    int xCenterScene;
    int yCenterScene;
    int zCenterScene;
    float angle;
}rotateRequestT;

typedef struct {
    float scaleCoef;
    int xCenterScene;
    int yCenterScene;
    int zCenterScene;
}scaleRequestT;

typedef struct {
    int xRectStart;
    int yRectStart;
    int xRectEnd;
    int yRectEnd;
    Ui::MainWindow *ui;
}drawRequestT;

typedef struct {
    int choice;
    moveRequestT moveRequest;
    rotateRequestT rotateRequest;
    scaleRequestT scaleRequest;
    char *fileName;
    drawRequestT drawRequest;
}requestT;

void resetRequest(requestT &request);
void freeFileNameRequest(requestT &request);

void setMoveChoice(requestT &request, const int direction,
                   const int bias);

void setMoveRequest(moveRequestT &request, const int direction,
                    const int bias);

void setRotateChoiceZ(requestT &request, const int xCenter,
                      const int yCenter, const float angle);

void setRotateChoiceY(requestT &request, const int xCenter,
                      const int zCenter, const float angle);

void setRotateChoiceX(requestT &request, const int yCenter,
                      const int zCenter, const float angle);

void setRotateRequestZ(rotateRequestT &request, const int direction,
                       const int xCenter, const int yCenter,
                       const float angle);

void setRotateRequestY(rotateRequestT &request, const int direction,
                       const int xCenter, const int zCenter,
                       const float angle);

void setRotateRequestX(rotateRequestT &request, const int direction,
                       const int yCenter, const int zCenter,
                       const float angle);

void setScaleChoice(requestT &request, const float scaleCoef,
                    const int xCenter, const int yCenter,
                    const int zCenter);

void setScaleRequest(scaleRequestT &request, float scaleCoef,
                     const int xCenter, const int yCenter,
                     const int zCenter);

int setLoadRequest(requestT &request, const char * const fileName);

int setDrawRequest(requestT &request, Ui::MainWindow *const ui);

#endif // REQUESTACTIONS_H
