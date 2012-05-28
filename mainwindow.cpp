#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initGUI();
    initConnect();
}

void MainWindow::initGUI()
{

    setWindowFlags(Qt::WindowMinimizeButtonHint);

//    QRect geometry = this->geometry();
//    geometry.moveCenter(QApplication::Desktop()->availableGeometry().center());
//    setGeometry(geometry);


    user = new Usuarios();
    user->inicializar(ui->centralWidget);

}

void MainWindow::initConnect()
{
    connect(ui->btnAgregarP,SIGNAL(clicked()),this,SLOT(slotNewUser()));
    connect(ui->btnEditarP,SIGNAL(clicked()),this,SLOT(slotEditUser()));
    connect(ui->btnBuscarP,SIGNAL(clicked()),this,SLOT(slotSearchUser()));
    connect(ui->btnEliminarP,SIGNAL(clicked()),this,SLOT(slotDeleteUser()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
}

void MainWindow::slotNewUser()
{
    user->nuevoUser();
}

void MainWindow::slotEditUser(){


    user->editarUsuario();

}

void MainWindow::slotSearchUser(){

    user->buscarUsuario();

}

void MainWindow::slotDeleteUser(){

    user->eliminarUsuario();

}


void MainWindow::slotCloseWindow()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

