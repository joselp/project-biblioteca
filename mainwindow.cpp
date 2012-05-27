#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initGUI();
}

void MainWindow::initGUI()
{
    connect(ui->btnAgregar,SIGNAL(clicked()),this,SLOT(slotNewUser()));

    user = new Usuarios(ui->centralWidget);
}

void MainWindow::slotNewUser()
{
    user->nuevoUser();
}


MainWindow::~MainWindow()
{
    delete ui;
}
