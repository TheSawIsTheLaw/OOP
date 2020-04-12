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

void setMoveChoice(requestT &request, int direction,
                   int bias);

void setMoveRequest(moveRequestT &request, int direction,
                    int bias);

void setRotateChoice(requestT &request, int direction,
                     float angle);

void setRotateRequest(rotateRequestT &request, int direction,
                      float angle);

void setScaleChoice(requestT &request, float scaleCoef,
                    int xCenter, int yCenter, int zCenter);

void setScaleRequest(scaleRequestT &request, float scaleCoef,
                     int xCenter, int yCenter, int zCenter);

int setLoadRequest(requestT &request, QString qFileName);

int setShowRequest(requestT &request, Ui::MainWindow *const ui);

#endif // REQUESTACTIONS_H
