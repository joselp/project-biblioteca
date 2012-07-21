#ifndef FORMADDUSER_H
#define FORMADDUSER_H

#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QValidator>
#include <QRegExpValidator>
#include <QRegExp>
#include <QKeyEvent>
#include <QFrame>

namespace Ui {
    class FormAddUser;
}

class FormAddUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddUser(QWidget *parent = 0);
    void clear();
    void init();
    ~FormAddUser();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void acept();

private:

    QString cedula;
    QString aux;

    Ui::FormAddUser *ui;
};

#endif // FORMADDUSER_H
