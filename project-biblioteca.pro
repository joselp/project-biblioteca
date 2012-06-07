#-------------------------------------------------
#
# Project created by QtCreator 2012-05-27T00:28:51
#
#-------------------------------------------------

QT       += core gui sql

TARGET = project-biblioteca
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    usuario.cpp \
    prestamo.cpp \
    dialogprestamo.cpp \
    solvencia.cpp

HEADERS  += \
    mainwindow.h \
    usuario.h \
    conexion.h \
    prestamo.h \
    dialogprestamo.h \
    solvencia.h

FORMS    += mainwindow.ui \
    dialogprestamo.ui

RESOURCES += \
    recursos.qrc
