#ifndef REQUEST_ACTIONS_H
#define REQUEST_ACTIONS_H

#pragma once
#include "mainwindow.h"

typedef struct {
    int direction;
    int bias;
}moveRequestT; // move

typedef struct {
    int direction;
    int xCenterScene;
    int yCenterScene;
    int zCenterScene;
    float angle;
}rotateRequestT; // rotate

typedef struct {
    float scaleCoef;
    int xCenterScene;
    int yCenterScene;
    int zCenterScene;
}scaleRequestT; // scale

typedef struct {
    int choice;
    moveRequestT moveRequest;
    rotateRequestT rotateRequest;
    scaleRequestT scaleRequest;
    drawRequestT drawRequest;
    char *fileName;
}requestT; // request

//! Request actions
void resetRequest(requestT &request);

void freeFileNameRequest(requestT &request);
//< End

//! Move request
void setMoveChoice(requestT &request, const int direction,
                   const int bias);

void setMoveRequest(moveRequestT &request, const int direction,
                    const int bias);
//< End

//! Rotate requests
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
//< End

//! Scale requests
void setScaleChoice(requestT &request, const float scaleCoef,
                    const int xCenter, const int yCenter,
                    const int zCenter);

void setScaleRequest(scaleRequestT &request, float scaleCoef,
                     const int xCenter, const int yCenter,
                     const int zCenter);
//< End

//! Load request
int setLoadRequest(requestT &request, const char * const fileName);
//< End

//! Draw request
int setDrawRequest(requestT &request,
                   const int xRectStart, const int yRectStart,
                   const int xRectEnd, const int yRectEnd,
                   Ui::MainWindow *const ui);
//< End

#endif // REQUESTACTIONS_H
