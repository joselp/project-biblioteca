#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <prestamo.h>
#include <usuario.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initGUI();
    void initConnect();

private slots:

    void slotPrestamo();
    void slotConsultaPrestamo();
    void slotNewUser();
    void slotCloseWindow();
    void slotDeleteUser();
    void slotSearchUser();
    void slotEditUser();


private:
    Ui::MainWindow *ui;

    Prestamo *prestamo;
    Usuarios *user;


};

#endif // MAINWINDOW_H
