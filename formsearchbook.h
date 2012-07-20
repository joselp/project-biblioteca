#ifndef FORMSEARCHBOOK_H
#define FORMSEARCHBOOK_H

#include <QWidget>
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

namespace Ui {
    class FormSearchBook;
}

class FormSearchBook : public QWidget
{
    Q_OBJECT

public:
    explicit FormSearchBook(QWidget *parent = 0);
    void inicializar();
    void limpiar();
    void mostrarEditar();
    void mostrarNuevo();
    ~FormSearchBook();

public slots:
    void buscarLibro();
    void btnBuscar();

private:

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
    QTableWidget *tableBusqueda;
    QTableWidgetItem *item;

    QTableView *tableview;

    bool bandera;

    int cantBook;
    int rowCount;

    QString cota;

    Ui::FormSearchBook *ui;

};

#endif // FORMSEARCHBOOK_H
