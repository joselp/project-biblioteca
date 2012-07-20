#ifndef FORMADDBOOK_H
#define FORMADDBOOK_H

#include <QWidget>
#include<QMessageBox>
#include<QPushButton>
#include<QComboBox>
#include<QLineEdit>
#include<QLabel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTableWidget>
#include<QWidgetItem>
#include<QTableView>
#include<QDebug>

namespace Ui {
    class FormAddBook;
}

class FormAddBook : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddBook(QWidget *parent = 0);
    void init();
    void clear();
    ~FormAddBook();

private slots:
    void slotAcept();

private:
    Ui::FormAddBook *ui;
};

#endif // FORMADDBOOK_H
