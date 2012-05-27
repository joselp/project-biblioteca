#include <QtGui/QApplication>
#include "project-biblioteca.h"
#include "conexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!crearConexion())
           return 1;

    MainWindow w;
    w.show();

    return a.exec();
}
