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

namespace Us {
    class Usuarios;
}

class Usuarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit Usuarios(QWidget *);
    void inicializar(QWidget *);
    void limpiar();
    ~Usuarios();

public slots:
    void nuevoUser();
    void aceptar();
    void buscarUsuario();
    void btnBuscar();
    void editarUsuario();
    void eliminarUsuario();
    void btnEliminar();
    void cancelar();


public:

    Us::Usuarios *us;

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


};

#endif // USUARIOS_H
