TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        IteratorBase.cpp \
        Vector.hpp \
        VectorBase.cpp \
        main.cpp

HEADERS += \
    ConstantIterator.h \
    ExceptionBase.h \
    Exceptions.h \
    Iterator.h \
    IteratorBase.h \
    Vector.h \
    VectorBase.h
