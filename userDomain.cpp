#include "userDomain.h"

#include "modelMove.h"

#include "modelRotation.h"

#include "modelScale.h"

#include "drawLevel.h"

#include "defines.h"


//< Entrance
int taskManager(const requestT request) {
    static modelT model = initModel();
    int check = SUCCESS;

    if (request.choice == DRAW_MODEL)
        check = drawModelWrap(model, request);
    else if (request.choice == ROTATION)
        check = rotateModelWrap(model, request.rotateRequest);
    else if (request.choice == SCALE)
        check = scaleModelWrap(model, request.scaleRequest);
    else if (request.choice == MOVEMENT)
        check = moveModelWrap(model, request.moveRequest);
    else if (request.choice == LOAD_MODEL)
        check = loadModel(model, request.fileName);
    else
        check = OUT_OF_CHOICE_ERROR;

    return check;
}
//< End
