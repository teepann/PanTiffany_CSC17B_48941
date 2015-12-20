#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T12:10:38
#
#-------------------------------------------------

QT       += core sql
QT       += network
QT       += widgets
QT       +=gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048Server
TEMPLATE = app


SOURCES += main.cpp\
    _2048server.cpp \
    _2048socket.cpp

HEADERS  += \
    _2048server.h \
    _2048socket.h

FORMS    += mainwindow.ui
