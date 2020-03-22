#include "mainwindow.h"
#include "userDomain.h"

#include "defines.h"

int taskManager(int choice){
    if (!choice){
        printf("Ход влево");
    }
    else if (choice == GO_DOWN){
        printf("Ход вниз");
    }
    else if (choice == GO_UP){
        printf("Ход вверх");
    }
    else if (choice == GO_RIGHT){
        printf("Ход вниз");
    }
    else if (choice == ROTATE_Z_R){
        printf("Ход вправо");
    }
    else if (choice == ROTATE_Z_L){
        printf("Верчение...");
    }
    else if (choice == ROTATE_Y_D){
        printf("Что-то...");
    }
    else if (choice == ROTATE_Y_U){
        printf("Что-то...");
    }
    else if (choice == ROTATE_X_R){
        printf("Что-то...");
    }
    else if (choice == ROTATE_X_L){
        printf("Что-то...");
    }
    else if (choice == SCALE_PLUS){
        printf("Что-то...");
    }
    else if (choice == SCALE_MINUS){
        printf("Что-то...");
    }

    return SUCCESS;
}
