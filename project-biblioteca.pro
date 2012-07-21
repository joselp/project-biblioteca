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
    manualusuario.cpp \
    formadduser.cpp \
    formsearchuser.cpp \
    formedituser.cpp \
    formdeleteuser.cpp \
    formaddbook.cpp \
    formsearchbook.cpp \
    formdeletebook.cpp \
    formeditbook.cpp

HEADERS  += \
    mainwindow.h \
    usuario.h \
    conexion.h \
    prestamo.h \
    dialogprestamo.h \
    solvencia.h \
    libro.h \
    utils.h \
    manualusuario.h \
    formadduser.h \
    formsearchuser.h \
    formedituser.h \
    formdeleteuser.h \
    formaddbook.h \
    formsearchbook.h \
    formdeletebook.h \
    formeditbook.h

FORMS    += mainwindow.ui \
    dialogprestamo.ui \
    manualusuario.ui \
    formadduser.ui \
    formsearchuser.ui \
    formedituser.ui \
    formdeleteuser.ui \
    formaddbook.ui \
    formsearchbook.ui \
    formdeletebook.ui \
    formeditbook.ui

RESOURCES += \
    recursos.qrc
