#ifndef FORMSEARCHPRESTAMO_H
#define FORMSEARCHPRESTAMO_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <dialogprestamo.h>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class FormSearchPrestamo;
}

class FormSearchPrestamo : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormSearchPrestamo(QWidget *parent = 0);
    void closedDialog();
    ~FormSearchPrestamo();
    
private:
    void initGUI();
    void filtroTable(QString );
    void keyPressEvent(QKeyEvent *);

private slots:
    void slotTipoFiltro(int);
    void slotRowSelected(int);
    void slotUpperText(QString);
    void slotFiltro();


private:
    Ui::FormSearchPrestamo *ui;

    QTableWidget * tablePrestamo;
    QTableWidgetItem * item;

    DialogPrestamo * dialogPrestamo;
};

#endif // FORMSEARCHPRESTAMO_H
