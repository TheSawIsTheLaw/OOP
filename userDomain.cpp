#include "userDomain.h"

#include "modelMove.h"

#include "modelRotation.h"

#include "modelScale.h"

#include "defines.h"


//< Entrance
// fix Передача в функцию структуры запроса, место не экономим
// fix Отказываемся от QString, от нас требуется пластичность
int taskManager(const int choice, Ui::MainWindow *ui, QString fileName) {
    static modelT model = initModel();
    int check;

    // fix ROTATE, MOVE, SCALE - наши команды
    // fix Параметры направлений передаются через параметры
    // fix Во все функции передаём только model, здесь иной уровень абстракции
    // fix Зашитые константы угла поворота и так далее мы передаём параметрами <!!!
    if (choice == GO_LEFT || choice == GO_DOWN || choice == GO_UP || choice == GO_RIGHT)
        check = moveModelWrap(model.nodes, choice, model.numOfNodes);
    else if (choice == ROTATE_Z_R || choice == ROTATE_Z_L)
        check = zRotateModelWrap(model.nodes, choice, model.numOfNodes);
    else if (choice == ROTATE_Y_R || choice == ROTATE_Y_L)
        check = yRotateModelWrap(model.nodes, choice, model.numOfNodes);
    else if (choice == ROTATE_X_R || choice == ROTATE_X_L)
        check = xRotateModelWrap(model.nodes, choice, model.numOfNodes);
    else if (choice == SCALE_PLUS || choice == SCALE_MINUS)
        check = scaleModelWrap(model.nodes, choice, model.numOfNodes);
    else if (choice == SET_MODEL) {
        check = setModel(model, fileName); // fix Поменять название функции
    }
    else
        return OUT_OF_CHOICE_ERROR;

    showAll(model, ui);  // fix Требуется выполнять по команде, так как нам может и не понадобиться
                         // отрисовывать модель

    return check;
}
//< End
