#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <formhome.h>
#include <formprestamo.h>
#include <formerprestamo.h>
#include <formsearchprestamo.h>
#include <formadduser.h>
#include <formsearchuser.h>
#include <formedituser.h>
#include <formdeleteuser.h>
#include <formaddbook.h>
#include <formsearchbook.h>
#include <formeditbook.h>
#include <formdeletebook.h>
#include <formsolvencia.h>
#include <manualusuario.h>
#include <dialogprestamo.h>
//#include <prestamo.h>
//#include <usuario.h>
//#include <solvencia.h>
//#include <libro.h>
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
    void includeHead();
    void deletePanel();
    void changePanel(QWidget *);
    void closeEvent(QCloseEvent *);

private slots:

    void slotHome();
    void slotPrestamo();
    void slotEntregaPrestamo();
    void slotRenovacion();
    void slotConsultaPrestamo();
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
    void slotCargarLibros();
    void slotManualUsuario();
    void slotAbout();


private:
    Ui::MainWindow *ui;

    QWidget * ptrWidget;

    ManualUsuario *manualUsuario;

};

#endif // MAINWINDOW_H
