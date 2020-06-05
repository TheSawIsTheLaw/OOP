QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Camera/camera.cpp \
    Camera/camerabase.cpp \
    Commands/commandbase.cpp \
    Managers/drawmanager.cpp \
    Managers/managerbase.cpp \
    Managers/scenemanager.cpp \
    Managers/transformmanager.cpp \
    Managers/uploadmanager.cpp \
    SceneUploader/scenebuilderbase.cpp \
    SceneUploader/sceneuploader.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Camera/camera.h \
    Camera/camerabase.h \
    Commands/commandbase.h \
    Managers/drawmanager.h \
    Managers/managerbase.h \
    Managers/scenemanager.h \
    Managers/transformmanager.h \
    Managers/uploadmanager.h \
    SceneUploader/scenebuilderbase.h \
    SceneUploader/sceneuploader.h \
    Vector/ConstIterator.hpp \
    Vector/ConstantIterator.h \
    Vector/ExceptionBase.hpp \
    Vector/Iterator.hpp \
    Vector/defines.h \
    Vector/exceptionBase.h \
    Vector/exceptions.h \
    Vector/iterator.h \
    Vector/vector.h \
    Vector/vector.hpp \
    Vector/vectorbase.h \
    defines.h \
    facade.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Component/temp.txt
