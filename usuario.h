#ifndef USUARIOS_H
#define USUARIOS_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QValidator>


class Usuarios : public QWidget
{
    Q_OBJECT

public:
    explicit Usuarios();
    void inicializar(QWidget *);
    void limpiar();
    void removeall();
    ~Usuarios();

public slots:
    void nuevoUser();
    void buscarUsuario();
    bool btnBuscar();
    void editarUsuario();
    void btnEditar();
    void eliminarUsuario();
    void btnEliminar();
    void cancelar();
    void aceptar();

public:

    QPushButton *btnAceptar;
    QPushButton *btnCancelar;
    QLabel *lbNombre;
    QLabel *lbApellido;
    QLabel *lbCedula;
    QLabel *lbTipo;
    QLabel *lbTipo2;
    QRadioButton *rbProf;
    QRadioButton *rbEstu;
    QLineEdit *leNombre;
    QLineEdit *leApellido;
    QLineEdit *leCedula;
    QString cedula;
    QString aux;

};

#endif // USUARIOS_H
