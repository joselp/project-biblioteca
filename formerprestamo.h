#ifndef FORMERPRESTAMO_H
#define FORMERPRESTAMO_H

#include <QWidget>
#include <QMessageBox>
#include <QDate>
#include <QSqlQuery>
#include <QKeyEvent>

namespace Ui {
class FormERPrestamo;
}

class FormERPrestamo : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormERPrestamo(QWidget *parent = 0);
    void setTipoBoton(int tipo);
    ~FormERPrestamo();
    
private:
    void initGUI();
    void clearWidget();
    void keyPressEvent(QKeyEvent *);

private slots:
    void slotUpperText();
    void slotEntregar();
    void slotRenovar();

private:
    Ui::FormERPrestamo *ui;

    int tipo;

    QSqlQuery query;
};

#endif // FORMERPRESTAMO_H
