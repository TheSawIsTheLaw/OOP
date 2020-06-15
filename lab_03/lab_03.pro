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
    Commands/commandbase.cpp \
    Commands/uploadcommand.cpp \
    Composite/component.cpp \
    Composite/componentvisitorbase.cpp \
    Drawer/drawer.cpp \
    Drawer/drawingfactorybase.cpp \
    Exceptions/exceptionbase.cpp \
    Managers/drawmanager.cpp \
    Managers/managerbase.cpp \
    Managers/scenemanager.cpp \
    Managers/transformmanager.cpp \
    Managers/uploadmanager.cpp \
    Model/carcassmodel.cpp \
    Model/dot.cpp \
    Model/edge.cpp \
    Scene/scene.cpp \
    SceneUploader/camerauploader.cpp \
    SceneUploader/modelbuilderbase.cpp \
    SceneUploader/modeluploader.cpp \
    SceneUploader/scenebuilderbase.cpp \
    SceneUploader/sceneuploader.cpp \
    SceneUploader/txtscenebuilder.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Camera/camera.h \
    Camera/camerabase.h \
    Camera/dotxy.h \
    Commands/commandbase.h \
    Commands/uploadcommand.h \
    Composite/component.h \
    Composite/componentvisitorbase.h \
    Drawer/drawer.h \
    Drawer/drawingfactorybase.h \
    Exceptions/exceptionbase.h \
    Exceptions/exceptions.h \
    Managers/drawmanager.h \
    Managers/managerbase.h \
    Managers/scenemanager.h \
    Managers/transformmanager.h \
    Managers/uploadmanager.h \
    Matrix/matrix.hpp \
    Matrix/matrixR.hpp \
    Model/carcassmodel.h \
    Model/dot.h \
    Model/edge.h \
    Model/model.h \
    Scene/ComponentName.h \
    Scene/scene.h \
    SceneUploader/camerauploader.h \
    SceneUploader/modelbuilderbase.h \
    SceneUploader/modeluploader.h \
    SceneUploader/scenebuilderbase.h \
    SceneUploader/sceneuploader.h \
    SceneUploader/txtscenebuilder.h \
    Vector/Iterator.hpp \
    Vector/Vector.hpp \
    Vector/VectorR.hpp \
    Vector/baseVector.hpp \
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
    Drawer/temp.txt \
    config.txt
