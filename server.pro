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
    API/dataminingfactory.cpp \
    API/mining.cpp \
    API/DebianMining/debianprocessormining.cpp \
    API/DebianMining/debianosmining.cpp \
    API/DebianMining/debianmemorymining.cpp \
    API/DebianMining/debianstoragemining.cpp \
    API/Windows7Mining/windows7osmining.cpp \
    API/Windows7Mining/windows7memorymining.cpp \
    API/Windows7Mining/windows7processormining.cpp \
    API/Windows7Mining/windows7storagemining.cpp \
    API/Windows10Mining/windows10memorymining.cpp \
    API/Windows10Mining/windows10osmining.cpp \
    API/Windows10Mining/windows10processormining.cpp \
    API/Windows10Mining/windows10storagemining.cpp \
    controller/maincontroller.cpp \
    requestmapper.cpp

HEADERS += \
    API/dataminingfactory.h \
    server.h \
    API/mining.h \
    API/iDataMining.h \
    API/iStrategy.h \
    API/DebianMining/debianprocessormining.h \
    API/DebianMining/debianosmining.h \
    API/DebianMining/debianmemorymining.h \
    API/DebianMining/debianstoragemining.h \
    API/Windows7Mining/windows7osmining.h \
    API/Windows7Mining/windows7memorymining.h \
    API/Windows7Mining/windows7processormining.h \
    API/Windows7Mining/windows7storagemining.h \
    API/Windows10Mining/windows10memorymining.h \
    API/Windows10Mining/windows10osmining.h \
    API/Windows10Mining/windows10processormining.h \
    API/Windows10Mining/windows10storagemining.h \
    controller/maincontroller.h \
    requestmapper.h

DISTFILES += \
    LICENSE \
    README.md \
    Port-Server.ini

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(Lib/QtWebApp/logging/logging.pri)
include(Lib/QtWebApp/httpserver/httpserver.pri)
include(Lib/QtWebApp/templateengine/templateengine.pri)
