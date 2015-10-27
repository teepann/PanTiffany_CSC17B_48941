#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T00:25:39
#
#-------------------------------------------------

QT       += core gui

TARGET = Filippakoc_mechanic_pacman_demo
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    pacman.cpp \
    map.cpp \
    ball.cpp \
    ghost.cpp \
    powerball.cpp \
    textdrawing.cpp

HEADERS  += window.h \
    pacman.h \
    map.h \
    ball.h \
    ghost.h \
    powerball.h \
    textdrawing.h

FORMS    += window.ui

RESOURCES += \
    images.qrc \
    sounds.qrc
QT+= widgets\
 widgets multimedia
