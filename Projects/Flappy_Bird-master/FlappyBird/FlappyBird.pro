#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T13:08:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainscene.cpp \
    uicontroller.cpp \
    startmenu.cpp \
    endmenu.cpp

HEADERS  += mainwindow.h \
    mainscene.h \
    uicontroller.h \
    startmenu.h \
    endmenu.h

FORMS    += mainwindow.ui \
    startmenu.ui \
    endmenu.ui

RESOURCES += \
    images.qrc
