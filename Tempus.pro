#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T10:14:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = Tempus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    setlocation.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    setlocation.h \
    settings.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    setlocation.ui

RESOURCES += \
    tempusrsrc.qrc
