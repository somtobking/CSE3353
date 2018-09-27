TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    astar.cpp \
    dijkstra.cpp \
    iterativebfs.cpp \
    iterativedfs.cpp \
    recursivebfs.cpp \
    recursivedfs.cpp \
    searchalgo.cpp \
    tests.cpp \
    BubbleSort.cpp \
    InsertionSort.cpp \
    MergeSort.cpp \
    Sort.cpp

HEADERS += \
    algorithm.h \
    astar.h \
    dijkstra.h \
    iterativebfs.h \
    iterativedfs.h \
    recursivebfs.h \
    recursivedfs.h \
    searchalgo.h \
    searchimplementation.h \
    catch.hpp \
    BubbleSort.h \
    InsertionSort.h \
    MergeSort.h \
    Sort.h
