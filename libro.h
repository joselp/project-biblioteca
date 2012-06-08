#ifndef LIBRO_H
#define LIBRO_H

#include<QMainWindow>
#include<QMessageBox>
#include<QPushButton>
#include<QComboBox>
#include<QLineEdit>
#include<QLabel>
#include<QSqlDatabase>
#include<QSqlQuery>

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro();
    void inicializar(QWidget *);
    void limpiar();
    void mostrarNuevo();
    void removeAll();
    ~Libro();

public slots:
    void nuevoLibro();
    void buscarLibro();
    bool btnBuscar();
    void editarLibro();
    void btnEditar();
    void eliminarLibro();
    void btnEliminar();
    void cancelar();
    void aceptar();

public:

    QLabel *lbCota;
    QLabel *lbAutor;
    QLabel *lbTitulo;
    QLabel *lbMateria;
    QLabel *lbEditorial;
    QLabel *lbAnhoPublicacion;
    QLabel *lbLugar;
    QLabel *lbAdquisicion;
    QLabel *lbVolumen;
    QLabel *lbEjemplar;
    QLabel *lbEstado;
    QComboBox *comboEstado;
    QComboBox *comboAdquisicion;
    QLineEdit *leCota;
    QLineEdit *leAutor;
    QLineEdit *leTitulo;
    QLineEdit *leMateria;
    QLineEdit *leEditorial;
    QLineEdit *leAnhoPublicacion;
    QLineEdit *leLugar;
    QLineEdit *leVolumen;
    QLineEdit *leEjemplar;
    QPushButton *btnAceptar;
    QPushButton *btnCancelar;



};

#endif // LIBRO_H
