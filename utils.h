#ifndef UTILS_H
#define UTILS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtCore>
#include <QProgressBar>
#include <QProgressDialog>
#include <QStyle>
#include <QDebug>
#include <string>


class Utils : public QThread
{
    Q_OBJECT
public:
    explicit Utils();
    void cargarArchivo(QWidget *);
    void cargarUsuarios(QWidget *);
    void guardarUsuarios(QWidget *);
    void run();

private:

    QString nombreArchivo;
    QString cota;
    QString autor;
    QString titulo;
    QString materia;
    QString editorial;
    QString anhoPublicacion;
    QString lugar;
    QString canjeado;
    QString donado;
    QString comprado;
    QString volumen;
    QString ejemplar;
    QString bueno;
    QString malo;
    QString regular;

    QString line;
    std::string aux;

    int c;
    int comienzo;
    int fin;
    int j;
    int k;

    QProgressBar *progress;
    QProgressDialog *progressDialog;


};

#endif // UTILS_H
