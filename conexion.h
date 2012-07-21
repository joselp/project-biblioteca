#ifndef CONEXION_H
#define CONEXION_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

bool crearConexion(){


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("biblioteca.db3");

    if (!db.open())
    {
        qDebug() << "Error Al abrir la base de datos";
        return false;
    }
    return true;
}



#endif // CONEXION_H
