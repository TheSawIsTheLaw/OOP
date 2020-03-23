#include "userDomain.h"

int taskManager(int choice, modelT &model){
    int check;
    if (!choice){
        check = moveModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_DOWN){
        check = moveModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_UP){
        check = moveModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_RIGHT){
        check = moveModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_R){
        check = zRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_L){
        check = zRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_R){
        check = yRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_L){
        check = yRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_R){
        check = xRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_L){
        check = xRotateModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == SCALE_PLUS){
        check = scaleModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == SCALE_MINUS){
        check = scaleModelWarp(choice, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }

    check = showModelWrap(model);
    if (check)
        return check;

    return SUCCESS;
}
