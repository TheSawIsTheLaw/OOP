#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT

   public slots:
    void onFloor(short floor);
    void passedFloor(short floor);

   public:
    explicit Controller(QObject *parent = nullptr);
    void setNewDestinationFloor(short floor);

   signals:
    void setDestinationFloor(short floor);

   private:
    enum controllerState { FREE, BUSY };

    short currentFloor;

    //
    QVector<bool> destinations;
    controllerState currentState;
};

#endif // CONTROLLER_H
