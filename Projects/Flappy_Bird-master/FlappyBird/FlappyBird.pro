#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T13:08:38
#
#-------------------------------------------------

QT       += core gui sql \
        multimedia
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainscene.cpp \
    uicontroller.cpp \
    gamelevel.cpp \
    difficultydialog.cpp \
    godialog.cpp \
    fbhelper.cpp

HEADERS  += mainwindow.h \
    mainscene.h \
    uicontroller.h \
    gamelevel.h \
    difficultydialog.h \
    godialog.h \
    fbhelper.h

FORMS    += mainwindow.ui \
    difficultydialog.ui \
    godialog.ui

RESOURCES += \
    images.qrc \
    soundtracks.qrc
