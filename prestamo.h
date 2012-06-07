#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCalendarWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlQuery>
#include <dialogprestamo.h>

class Prestamo : public QWidget
{
    Q_OBJECT
public:
    explicit Prestamo(QWidget *parent = 0);
    void initGUI(QWidget *);
    void visibleWidget(bool );
    void showEntregaPrestamo();
    void visibleEntrega(bool );
    void showTablePrestamo();
    void visibleTable(bool );

private slots:
    void slotValidate();
    void slotCalendar();
    void slotDate(QDate );
    void slotRegistrar();
    void slotRowSelected(int);
    void slotUpperText();
    void slotAcceptEntrega();

private:
    QLabel *lblCota;
    QLineEdit *lineEditCota;
    QLineEdit *lineEditCotaEntrega;

    QLabel *lblAutor;
    QLineEdit *lineEditAutor;

    QLabel *lblTitulo;
    QLineEdit *lineEditTitulo;

    QLabel *lblTipoPrestamo;
    QComboBox *comboBoxTipoPrestamo;

    QLabel *lblGrado;
    QComboBox *comboBoxGrado;

    QLabel *lblCedula;
    QLineEdit *lineEditCedula;

    QLabel *lblFechaP;
    QLineEdit *lineEditFechaP;

    QLabel *lblFechaE;
    QLineEdit *lineEditFechaE;

    QLabel *lblCategoria;
    QLineEdit *lineEditCategoria;

    QLabel *lblCantidad;
    QLineEdit *lineEditCantidad;

    QLabel *lblStatus;
    QLineEdit *lineEditStatus;

    QLabel *lblResponsable;
    QComboBox *comboBoxResponsable;

    QCalendarWidget *calendarWidget;

    QPushButton *btnCalendar;
    QPushButton *btnRegistrar;
    QPushButton *btnEntregar;

    QTableWidget *tablePrestamo;
    QTableWidgetItem *item;

    DialogPrestamo *dialogPrestamo;

    QSqlQuery query;
    int cantBook;

    int rowCount;

};

#endif // PRESTAMO_H
