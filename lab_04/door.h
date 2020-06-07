#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "defines.h"

class Door : public QObject {
    Q_OBJECT
    enum doors_state { OPENED, CLOSED, OPENNING, CLOSING };

   public:
    explicit Door(QObject *parent = nullptr);

   signals:
    void closed_doors();
    void opened_doors();

   public slots:
    void start_openning();
    void start_closing();

   private slots:
    void open();
    void close();

   private:
    doors_state currentState;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
    QTimer doors_stay_open_timer;
};

#endif // DOOR_H
