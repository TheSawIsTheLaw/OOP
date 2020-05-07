TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        iterator.cpp \
        iteratorbase.cpp \
        main.cpp \
        vector.cpp \
        vectorbase.cpp

HEADERS += \
    exceptionBase.h \
    exeptions.h \
    iterator.h \
    iteratorbase.h \
    vector.h \
    vectorbase.h
