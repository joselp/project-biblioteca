#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <prestamo.h>
#include <usuario.h>
#include <solvencia.h>

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
    void slotEntregaPrestamo();
    void slotConsultaPrestamo();
    void slotNewUser();
    void slotEditUser();
    void slotSearchUser();
    void slotDeleteUser();
    void slotSolvencia();
    void slotCloseWindow();

private:
    Ui::MainWindow *ui;

    Prestamo *prestamo;
    Usuarios *user;
    Solvencia *solvencia;


};

#endif // MAINWINDOW_H
