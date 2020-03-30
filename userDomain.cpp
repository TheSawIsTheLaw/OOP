#include "userDomain.h"

int taskManager(int choice, modelT &model){
    int check;
    if (!choice){
        check = moveModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_DOWN){
        check = moveModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_UP){
        check = moveModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_RIGHT){
        check = moveModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_R){
        check = zRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_L){
        check = zRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_R){
        check = yRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_L){
        check = yRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_R){
        check = xRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_L){
        check = xRotateModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == SCALE_PLUS){
        check = scaleModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == SCALE_MINUS){
        check = scaleModelWrap(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }

    check = showModelWrap(model);
    if (check)
        return check;

    return SUCCESS;
}
