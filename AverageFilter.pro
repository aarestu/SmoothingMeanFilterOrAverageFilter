#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T11:52:10
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = AverageFilter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


INCLUDEPATH += D://opencv//sources//opencv_bin//install//include

LIBS += D://opencv//sources//opencv_bin//bin//*.dll
