#ifndef FORMPRESTAMO_H
#define FORMPRESTAMO_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class FormPrestamo;
}

class FormPrestamo : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormPrestamo(QWidget *parent = 0);
    ~FormPrestamo();

private:
    void initGUI();
    void clearWidget();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void slotValidateCota();
    void slotValidateCedula();
    void slotTipoPrestamo(int);
    void slotPrestar();
    
private:
    Ui::FormPrestamo *ui;

    QSqlQuery query;

    int cantBook;
};

#endif // FORMPRESTAMO_H
