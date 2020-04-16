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
    float angle;
}rotateRequestT;

typedef struct {
    float scaleCoef;
    int xCenterScene;
    int yCenterScene;
    int zCenterScene;
}scaleRequestT;

typedef struct {
    int choice;
    moveRequestT moveRequest;
    rotateRequestT rotateRequest;
    scaleRequestT scaleRequest;
    char *fileName;
    Ui::MainWindow *ui;
}requestT;

void resetRequest(requestT &request);
void freeFileNameRequest(requestT &request);

void setMoveChoice(requestT &request, const int direction,
                   const int bias);

void setMoveRequest(moveRequestT &request, const int direction,
                    const int bias);

void setRotateChoice(requestT &request, const int direction,
                     const float angle);

void setRotateRequest(rotateRequestT &request, const int direction,
                      const float angle);

void setScaleChoice(requestT &request, const float scaleCoef,
                    const int xCenter, const int yCenter,
                    const int zCenter);

void setScaleRequest(scaleRequestT &request, float scaleCoef,
                     const int xCenter, const int yCenter,
                     const int zCenter);

int setLoadRequest(requestT &request, const QString qFileName);

int setShowRequest(requestT &request, Ui::MainWindow *const ui);

#endif // REQUESTACTIONS_H
