#ifndef USUARIOS_H
#define USUARIOS_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>

namespace Ui {
    class Usuarios;
}

class Usuarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit Usuarios(QWidget *parent = 0);
    void inicializar();
    void limpiar();
    ~Usuarios();

private slots:
          void nuevoUser();
          void aceptar();
          void buscarUsuario();
          void btnBuscar();
          void editarUsuario();
          void eliminarUsuario();
          void btnEliminar();
          void cancelar();


private:

    Ui::Usuarios *ui;
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
