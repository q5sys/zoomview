#-------------------------------------------------
#
# (c) q5sys 2019 under MIT or BSD2
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zoom
TEMPLATE = app

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \\
        main.cpp \
        mainwindow.cpp \
        zoomgview.cpp

HEADERS += \\
        mainwindow.h \ \
    zoomgview.h

FORMS += \
        mainwindow.ui
