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
    void showPrestamo();
    void showEntrega();
    void showRenovacion();
    void showTablePrestamo();
    void clearWidget();
    void prestamoWidget();
    void distroyedCalendar();

private slots:
    void slotValidateCota();
    void slotValidateCedula();
    void slotTipoPrestamo(int);
    void slotCalendar();
    void slotDate(QDate );
    void slotRegistrar();
    void slotRowSelected(int);
    void slotUpperText();
    void slotUpperText(QString);
    void slotAcceptEntrega();
    void slotRenovacion();
    void slotTipoFiltro(int );
    void slotFiltro();

private:
    void filtroTable(QString );

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

    QLabel *lblCedula;
    QLineEdit *lineEditCedula;

    QLabel *lblFechaP;
    QLineEdit *lineEditFechaP;

    QLabel *lblFechaE;
    QLineEdit *lineEditFechaE;

    QRegExp expFecha;

    QLabel *lblResponsable;
    QComboBox *comboBoxResponsable;

    QCalendarWidget *calendarWidget;

    QPushButton *btnCalendar;
    QPushButton *btnRegistrar;

    QLabel *lblFiltro;
    QComboBox *comboBoxFiltro;
    QLineEdit *lineEditFiltro;

    QTableWidget *tablePrestamo;
    QTableWidgetItem *item;

    DialogPrestamo *dialogPrestamo;

    QSqlQuery query;
    int cantBook;

    int rowCount;
};

#endif // PRESTAMO_H
