#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
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

    void slotNewUser();
    void slotCloseWindow();

private:
    Ui::MainWindow *ui;

    Usuarios *user;


};

#endif // MAINWINDOW_H
