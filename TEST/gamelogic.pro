#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T16:22:14
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_gamelogictest
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app


SOURCES += tst_gamelogictest.cpp\
    SOURCE/Gindy5.cpp \
    SOURCE/GameWorld.cpp \
    SOURCE/gameTime.cpp \
    SOURCE/GamePlayer.cpp \
    SOURCE/Foods.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS +=  HEADER/Gindy5.h \
    HEADER/GameWorld.h \
    HEADER/gameTime.h \
    HEADER/GamePlayer.h \
    HEADER/Foods.h
