#ifndef FORMSOLVENCIA_H
#define FORMSOLVENCIA_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDate>
#include <QKeyEvent>

namespace Ui {
class FormSolvencia;
}

class FormSolvencia : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormSolvencia(QWidget *parent = 0);
    ~FormSolvencia();

private:
    void initGUI();
    QList<QString> cuadroTitulo();
    QString cuadroConstancia();
    void printDocument(QPrinter *, QSqlQuery );
    void clearWidget();
    void keyPressEvent(QKeyEvent *);

private slots:
    void slotGenerateSolvencia();
    
private:
    Ui::FormSolvencia *ui;
};

#endif // FORMSOLVENCIA_H
