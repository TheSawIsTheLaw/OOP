TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        iteratorbase.cpp \
        main.cpp \
        vector.hpp \
        vectorbase.cpp

HEADERS += \
    exceptionBase.h \
    exceptions.h \
    iterator.h \
    iteratorbase.h \
    vector.h \
    vectorbase.h
