#ifndef FORMEDITBOOK_H
#define FORMEDITBOOK_H

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
#include<QKeyEvent>


namespace Ui {
    class FormEditBook;
}

class FormEditBook : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditBook(QWidget *parent = 0);
    void inicializar();
    void limpiar();
    void mostrarEditar();
    void keyPressEvent(QKeyEvent *event);
    ~FormEditBook();

public slots:
    void buscarLibro();
    void btnEditar();
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
    QLineEdit *leBuscar;
    QPushButton *btnAceptar;
    QPushButton *btnCancelar;


    QString cota;
private:

    Ui::FormEditBook *ui;
};

#endif // FORMEDITBOOK_H
