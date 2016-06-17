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
CONFIG   += c++11

TEMPLATE = app

win32:LIBS += -lPdh

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
    Windows7Mining/windows7storagemining.cpp \
    Windows10Mining/windows10memorymining.cpp \
    Windows10Mining/windows10osmining.cpp \
    Windows10Mining/windows10processormining.cpp \
    Windows10Mining/windows10storagemining.cpp \
    controller/maincontroller.cpp \
    requestmapper.cpp

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
    Windows7Mining/windows7storagemining.h \
    Windows10Mining/windows10memorymining.h \
    Windows10Mining/windows10osmining.h \
    Windows10Mining/windows10processormining.h \
    Windows10Mining/windows10storagemining.h \
    controller/maincontroller.h \
    requestmapper.h

DISTFILES += \
    LICENSE \
    README.md \
    Port-Server.ini

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../QtWebApp/logging/logging.pri)
include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)
