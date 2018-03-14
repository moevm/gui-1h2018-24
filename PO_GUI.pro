#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T21:39:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PO_GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    interface/view/recordstable.cpp \
    interface/view/choosinglevel.cpp \
    interface/view/game.cpp \
    interface/view/mainwindow.cpp \
    interface/view/mainmenu.cpp \
    game/gamefield.cpp \

HEADERS += \
    interface/view/recordstable.h \
    interface/view/choosinglevel.h \
    interface/view/game.h \
    interface/view/mainwindow.h \
    interface/view/mainmenu.h \
    game/gamefield.h \

FORMS += \
    interface/view/recordstable.ui \
    interface/view/choosinglevel.ui \
    interface/view/game.ui \
    interface/view/mainwindow.ui \
    interface/view/mainmenu.ui
