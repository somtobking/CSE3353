TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tspnaive.cpp \
    tspdp.cpp \
    graph.cpp

HEADERS += \
    algorithm.h \
    tspnaive.h \
    tspdp.h \
    graph.h
