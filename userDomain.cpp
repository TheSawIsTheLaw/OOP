#include "userDomain.h"

int taskManager(int choice, modelT &model){
    int check;
    if (!choice){
        check = moveModelWarp(GO_LEFT, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_DOWN){
        check = moveModelWarp(GO_DOWN, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_UP){
        check = moveModelWarp(GO_UP, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == GO_RIGHT){
        check = moveModelWarp(GO_RIGHT, model.nodes, model.numOfNodes);
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_R){
        check = printf("Ход вправо");
        if (check)
            return check;
    }
    else if (choice == ROTATE_Z_L){
        check = printf("Верчение...");
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_D){
        check = printf("Что-то...");
        if (check)
            return check;
    }
    else if (choice == ROTATE_Y_U){
        check = printf("Что-то...");
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_R){
        check = printf("Что-то...");
        if (check)
            return check;
    }
    else if (choice == ROTATE_X_L){
        check = printf("Что-то...");
        if (check)
            return check;
    }
    else if (choice == SCALE_PLUS){
        check = printf("Что-то...");
        if (check)
            return check;
    }
    else if (choice == SCALE_MINUS){
        check = printf("Что-то...");
        if (check)
            return check;
    }

    check = showModelWrap(model);
    if (check)
        return check;

    return SUCCESS;
}
