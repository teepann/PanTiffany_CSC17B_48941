#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T11:07:47
#
#-------------------------------------------------

QT       += core gui \
        multimedia
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tile.cpp \
    helper.cpp

HEADERS  += mainwindow.h \
    tile.h \
    helper.h

FORMS    += mainwindow.ui

RESOURCES += \
    tile.qrc \
    tile.qrc \
    tile.qrc
