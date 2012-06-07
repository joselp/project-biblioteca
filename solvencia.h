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
    void printDocument(QPrinter *);

private slots:
    void slotGenerateSolvencia();

private:

    QLabel *lblCedula;
    QLineEdit *lineEditCedula;

    QPushButton *btnSolvencia;

    QSqlQuery query;

};

#endif // SOLVENCIA_H
