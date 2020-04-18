#include "userDomain.h"

#include "modelMove.h"

#include "modelRotation.h"

#include "modelScale.h"

#include "defines.h"


//< Entrance
// fixed Передача в функцию структуры запроса, место не экономим
// fixed Отказываемся от QString, от нас требуется пластичность
int taskManager(const requestT request) {
    static modelT model = initModel();
    int check = SUCCESS;

    if (request.choice == MOVEMENT)
        check = moveModelWrap(model, request.moveRequest);
    else if (request.choice == ROTATION)
        check = rotateModelWrap(model, request.rotateRequest);
    else if (request.choice == SCALE)
        check = scaleModelWrap(model, request.scaleRequest);
    else if (request.choice == LOAD_MODEL)
        check = loadModel(model, request.fileName); // fixed Поменять название функции
    else if (request.choice == SHOW_MODEL)
        check = drawModelWrap(model, request.ui);
    else
        check = OUT_OF_CHOICE_ERROR;

    return check;
}
//< End
