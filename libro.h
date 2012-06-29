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
#include<QTableWidget>
#include<QWidgetItem>
#include<QTableView>
#include<QDebug>

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro();
    void inicializar(QWidget *);
    void limpiar();
    void mostrarNuevo();
    void mostrarEditar();
    void removeAll();
    ~Libro();

public slots:
    void nuevoLibro();
    void buscarLibro();
    void btnBuscar();
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
    QLabel *lbBuscar;
    QLabel *lbTipoBusqueda;
    QComboBox *comboEstado;
    QComboBox *comboAdquisicion;
    QComboBox *comboTipoBusqueda;
    QLineEdit *leCota;
    QLineEdit *leAutor;
    QLineEdit *leTitulo;
    QLineEdit *leMateria;
    QLineEdit *leEditorial;
    QLineEdit *leAnhoPublicacion;
    QLineEdit *leLugar;
    QLineEdit *leVolumen;
    QLineEdit *leEjemplar;
    QLineEdit *leBuscar;
    QPushButton *btnAceptar;
    QPushButton *btnCancelar;
    QTableWidget *tableBusqueda;
    QTableWidgetItem *item;

    QTableView *tableview;

    bool bandera;

    int cantBook;
    int rowCount;

    QString cota;


};

#endif // LIBRO_H
