#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T17:04:44
#
#-------------------------------------------------

QT       += core sql
QT       += network
QT       += widgets
QT       +=gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FBServer
TEMPLATE = app


SOURCES += main.cpp \
    fbserver.cpp \
    fbsocket.cpp

HEADERS  += \
    fbserver.h \
    fbsocket.h

FORMS    +=
