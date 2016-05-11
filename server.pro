#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T17:27:07
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    dataminingfactory.cpp \
    mining.cpp \
    DebianMining/debianprocessormining.cpp \
    DebianMining/debianosmining.cpp \
    DebianMining/debianmemorymining.cpp \
    DebianMining/debianstoragemining.cpp \
    Windows7Mining/windows7osmining.cpp \
    Windows7Mining/windows7memorymining.cpp \
    Windows7Mining/windows7processormining.cpp \
    Windows7Mining/windows7storagemining.cpp

HEADERS += \
    dataminingfactory.h \
    server.h \
    mining.h \
    iDataMining.h \
    iStrategy.h \
    DebianMining/debianprocessormining.h \
    DebianMining/debianosmining.h \
    DebianMining/debianmemorymining.h \
    DebianMining/debianstoragemining.h \
    Windows7Mining/windows7osmining.h \
    Windows7Mining/windows7memorymining.h \
    Windows7Mining/windows7processormining.h \
    Windows7Mining/windows7storagemining.h
