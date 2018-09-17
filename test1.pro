#-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T17:11:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    internetdialog.cpp \
    opentxtdialog.cpp \
    welcomedialog.cpp \
    executefile.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    internetdialog.h \
    opentxtdialog.h \
    welcomedialog.h \
    ../Desktop/transfer file module/executefile.h \
    ../Desktop/transfer file module/executefile.h \
    executefile.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    internetdialog.ui \
    opentxtdialog.ui \
    welcomedialog.ui \
    executefile.ui \
    aboutdialog.ui

RESOURCES += \
    images.qrc
