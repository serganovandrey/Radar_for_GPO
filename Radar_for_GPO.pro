#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T15:29:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Radar_for_GPO
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    grid_radar.cpp \
    generator.cpp

HEADERS  += widget.h \
    grid_radar.h \
    generator.h

FORMS    += widget.ui
