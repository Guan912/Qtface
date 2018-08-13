#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T20:58:54
#
#-------------------------------------------------

QT       += core gui
QT       +=  multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = facedet
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
        mainwindow.cpp \
    videowidget.cpp

HEADERS += \
        mainwindow.h \
    videowidget.h

FORMS += \
        mainwindow.ui \
    videowidget.ui

DISTFILES += \
    haarcascade_frontalface_default.xml \
    Face.py

win32: LIBS += -L'E:/Program Files/python2.7/libs/' -lpython27

INCLUDEPATH += 'E:/Program Files/python2.7/include'
DEPENDPATH += 'E:/Program Files/python2.7/include'

win32:!win32-g++: PRE_TARGETDEPS += 'E:/Program Files/python2.7/libs/python27.lib'
else:win32-g++: PRE_TARGETDEPS += 'E:/Program Files/python2.7/libs/libpython27.a'
