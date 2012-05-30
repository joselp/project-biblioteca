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


class Usuarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit Usuarios();
    void inicializar(QWidget *);
    void limpiar();
    ~Usuarios();

public slots:
    void nuevoUser();
    void aceptar();
    void buscarUsuario();
    bool btnBuscar();
    void editarUsuario();
    void btnEditar();
    void eliminarUsuario();
    void btnEliminar();
    void cancelar();


public:

    QPushButton *btnAceptar;
    QPushButton *btnCancelar;
    QLabel *lbNombre;
    QLabel *lbApellido;
    QLabel *lbCedula;
    QLabel *lbTipo;
    QRadioButton *rbProf;
    QRadioButton *rbEstu;
    QLineEdit *leNombre;
    QLineEdit *leApellido;
    QLineEdit *leCedula;
    QString cedula;

};

#endif // USUARIOS_H
