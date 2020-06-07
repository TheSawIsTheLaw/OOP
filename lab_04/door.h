#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "defines.h"

class Door : public QObject {
    Q_OBJECT
    enum states { OPENED, OPENING, CLOSED, CLOSING };


   public:
    explicit Door(QObject *parent = nullptr);

   public slots:
    void startOpen();
    void startClose();

   private slots:
    void open();
    void close();

   private:
    states state;
    QTimer openTimer;
    QTimer closeTimer;
    QTimer openStateTimer;

   signals:
    void doorIsOpened();
    void doorIsClosed();
};

#endif // DOOR_H
