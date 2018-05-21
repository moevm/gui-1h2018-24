#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T21:39:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreakOut
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
    interface/recordstable.cpp \
    interface/choosinglevel.cpp \
    interface/game.cpp \
    interface/mainwindow.cpp \
    interface/mainmenu.cpp \
    game/gamefield.cpp \
    game/ball.cpp \
    game/board.cpp \
    game/brick.cpp \
    game/state.cpp \
    records/record.cpp

HEADERS += \
    interface/recordstable.h \
    interface/choosinglevel.h \
    interface/game.h \
    interface/mainwindow.h \
    interface/mainmenu.h \
    game/gamefield.h \
    game/ball.h \
    game/board.h \
    game/brick.h \
    game/constants.h \
    game/state.h \
    records/record.h

FORMS += \
    interface/recordstable.ui \
    interface/choosinglevel.ui \
    interface/game.ui \
    interface/mainwindow.ui \
    interface/mainmenu.ui

RESOURCES += application.qrc
