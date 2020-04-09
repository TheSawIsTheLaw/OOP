#include "userDomain.h"

#include "modelMove.h"

#include "modelRotation.h"

#include "modelScale.h"

#include "defines.h"


//< Entrance
int taskManager(int choice, Ui::MainWindow *ui, QString fileName) {
    static modelT model = initModel();
    int check;

    if (choice == GO_LEFT || choice == GO_DOWN || choice == GO_UP || choice == GO_RIGHT)
        check = moveModelWrap(choice, model.nodes, model.numOfNodes);
    else if (choice == ROTATE_Z_R || choice == ROTATE_Z_L)
        check = zRotateModelWrap(choice, model.nodes, model.numOfNodes);
    else if (choice == ROTATE_Y_R || choice == ROTATE_Y_L)
        check = yRotateModelWrap(choice, model.nodes, model.numOfNodes);
    else if (choice == ROTATE_X_R || choice == ROTATE_X_L)
        check = xRotateModelWrap(choice, model.nodes, model.numOfNodes);
    else if (choice == SCALE_PLUS || choice == SCALE_MINUS)
        check = scaleModelWrap(choice, model.nodes, model.numOfNodes);
    else if (choice == SET_MODEL) {
        check = setModel(fileName, model);
    }
    else
        return OUT_OF_CHOICE_ERROR;

    if (check)
        return check;

    showAll(model, ui);

    return SUCCESS;
}
//< End
