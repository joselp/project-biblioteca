#-------------------------------------------------
#
# Project created by QtCreator 2012-05-27T00:28:51
#
#-------------------------------------------------

QT       += core gui sql webkit

TARGET = project-biblioteca
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    usuario.cpp \
    prestamo.cpp \
    dialogprestamo.cpp \
    solvencia.cpp \
    libro.cpp \
    utils.cpp \
    manualusuario.cpp

HEADERS  += \
    mainwindow.h \
    usuario.h \
    conexion.h \
    prestamo.h \
    dialogprestamo.h \
    solvencia.h \
    libro.h \
    utils.h \
    manualusuario.h

FORMS    += mainwindow.ui \
    dialogprestamo.ui \
    manualusuario.ui

RESOURCES += \
    recursos.qrc
