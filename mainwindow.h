#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:

    void slotNewUser();

private:
    Ui::MainWindow *ui;

    Usuarios *user;

};

#endif // MAINWINDOW_H
