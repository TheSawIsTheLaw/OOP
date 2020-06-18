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
    Commands/commands.cpp \
    Composite/component.cpp \
    Composite/componentvisitorbase.cpp \
    Drawer/drawer.cpp \
    Drawer/drawingfactorybase.cpp \
    Exceptions/exceptionbase.cpp \
    Managers/drawmanager.cpp \
    Managers/scenemanager.cpp \
    Managers/transformmanager.cpp \
    Managers/uploadmanager.cpp \
    Model/carcassmodel.cpp \
    Model/dot.cpp \
    Model/edge.cpp \
    Model/model.cpp \
    Scene/scene.cpp \
    SceneUploader/objectuploader.cpp \
    SceneUploader/scenebuilderbase.cpp \
    SceneUploader/sceneuploader.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Camera/camera.hpp \
    Camera/camerabase.hpp \
    Camera/dotxy.hpp \
    Commands/commandbase.hpp \
    Commands/commands.hpp \
    Composite/component.hpp \
    Composite/componentvisitorbase.hpp \
    Drawer/drawer.hpp \
    Drawer/drawingfactorybase.hpp \
    Exceptions/exceptionbase.hpp \
    Exceptions/exceptions.hpp \
    Managers/drawmanager.hpp \
    Managers/managerbase.hpp \
    Managers/scenemanager.hpp \
    Managers/transformmanager.hpp \
    Managers/uploadmanager.hpp \
    Matrix/matrix.hpp \
    Matrix/matrixR.hpp \
    Model/carcassmodel.hpp \
    Model/dot.hpp \
    Model/edge.hpp \
    Model/model.hpp \
    Scene/ComponentName.hpp \
    Scene/scene.hpp \
    SceneUploader/objectuploader.hpp \
    SceneUploader/scenebuilderbase.hpp \
    SceneUploader/sceneuploader.hpp \
    Vector/Iterator.hpp \
    Vector/Vector.hpp \
    Vector/VectorR.hpp \
    Vector/baseVector.hpp \
    defines.hpp \
    facade.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
