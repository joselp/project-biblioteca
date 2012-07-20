#ifndef FORMEDITUSER_H
#define FORMEDITUSER_H

#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QValidator>
#include <QRegExpValidator>
#include <QRegExp>

namespace Ui {
    class FormEditUser;
}

class FormEditUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditUser(QWidget *parent = 0);
    void clear();
    void init();
    ~FormEditUser();

private slots:
    void buscar();
    void acept();

private:

    QString cedula;
    QString aux;
    Ui::FormEditUser *ui;
};

#endif // FORMEDITUSER_H
