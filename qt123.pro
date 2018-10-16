#-------------------------------------------------
#
# Project created by QtCreator 2018-09-03T16:44:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt123
TEMPLATE = app
RC_ICONS = cat.ico
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dg_esc.cpp \
    search.cpp \
    languagechage.cpp \
    showcmd.cpp \
    downloadicon.cpp

HEADERS += \
        mainwindow.h \
    dg_esc.h \
    search.h \
    languagechage.h \
    showcmd.h \
    downloadicon.h

FORMS += \
        mainwindow.ui \
    dg_esc.ui \
    search.ui \
    languagechage.ui \
    showcmd.ui \
    downloadicon.ui

RESOURCES += \
    icon.qrc
