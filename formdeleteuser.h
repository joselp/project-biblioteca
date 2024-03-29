#ifndef FORMDELETEUSER_H
#define FORMDELETEUSER_H

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

namespace Ui {
    class FormDeleteUser;
}

class FormDeleteUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormDeleteUser(QWidget *parent = 0);
    void clear();
    void init();
    void keyPressEvent(QKeyEvent *event);
    ~FormDeleteUser();

private slots:
    void acept();

private:
    Ui::FormDeleteUser *ui;
};

#endif // FORMDELETEUSER_H
