#ifndef SOLVENCIA_H
#define SOLVENCIA_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QRect>
#include <QSqlQuery>
#include <QDebug>

class Solvencia : public QWidget
{
    Q_OBJECT
public:
    explicit Solvencia(QWidget *parent = 0);
    void initGUI(QWidget *);
    void visibleWidget(bool );

private:
    void printDocument(QPrinter *, QSqlQuery );
    QList<QString> cuadroTitulo();
    QString cuadroConstancia();

private slots:
    void slotGenerateSolvencia();

private:

    QLabel *lblCedula;
    QLineEdit *lineEditCedula;

    QLabel *lblGrado;
    QComboBox *comboBoxGrado;

    QLabel *lblPeriodo;
    QLineEdit *lineEditPeriodo;

    QPushButton *btnSolvencia;

    QSqlQuery query;

    QTextDocument doc;

};

#endif // SOLVENCIA_H
