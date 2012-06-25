#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <prestamo.h>
#include <usuario.h>
#include <solvencia.h>
#include <libro.h>
#include <utils.h>

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
    void closeEvent(QCloseEvent *);

private slots:

    void slotPrestamo();
    void slotEntregaPrestamo();
    void slotConsultaPrestamo();
    void slotRenovacion();
    void slotNewUser();
    void slotEditUser();
    void slotSearchUser();
    void slotDeleteUser();
    void slotSolvencia();
    void slotCloseWindow();
    void slotNewBook();
    void slotSearchBook();
    void slotDeleteBook();
    void slotEditBook();
    void cargarLibros();

private:
    Ui::MainWindow *ui;

    Prestamo *prestamo;
    Usuarios *user;
    Solvencia *solvencia;
    Libro *libro;
    Utils *util;


};

#endif // MAINWINDOW_H