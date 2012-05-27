#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnAgregar,SIGNAL(clicked()),this,SLOT(slotNewUser()));

}


void MainWindow::slotNewUser(){

    Usuarios *user = new Usuarios(ui->centralWidget);
    user->nuevoUser();

}


MainWindow::~MainWindow()
{
    delete ui;
}
