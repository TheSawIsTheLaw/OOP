#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT
    enum controllerState { FREE, BUSY };

   public:
    explicit Controller(QObject *parent = nullptr);
    void setNewDestinationFloor(short floor);

   signals:
    void setDestinationFloor(short floor, direction dir);

   public slots:
    void achieved_floor(short floor);
    void passed_floor(short floor);

   private:
    int cur_floor;
    int cur_target = -1;

    QVector<bool> is_target;
    controllerState currentState;
    direction cur_direction;
    bool next_target(short &floor);
    void find_new_target();
};

#endif // CONTROLLER_H
