#ifndef FORMSEARCHUSER_H
#define FORMSEARCHUSER_H

#include <QWidget>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QValidator>
#include <QRegExpValidator>
#include <QRegExp>
#include<QKeyEvent>

namespace Ui {
    class FormSearchUser;
}

class FormSearchUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormSearchUser(QWidget *parent = 0);
    void init();
    void keyPressEvent(QKeyEvent *event);
    ~FormSearchUser();

private slots:
    void acept();

private:

    QString cedula;
    QString aux;

    Ui::FormSearchUser *ui;
};

#endif // FORMSEARCHUSER_H
