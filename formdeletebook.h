#ifndef FORMDELETEBOOK_H
#define FORMDELETEBOOK_H

#include <QWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>

namespace Ui {
    class FormDeleteBook;
}

class FormDeleteBook : public QWidget
{
    Q_OBJECT

public:
    explicit FormDeleteBook(QWidget *parent = 0);
    void init();
    ~FormDeleteBook();

private slots:
    void deleteBook();

private:
    Ui::FormDeleteBook *ui;
};

#endif // FORMDELETEBOOK_H
