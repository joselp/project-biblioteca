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
    setWindowIcon(QIcon(":/images/logo.png"));
    setWindowFlags(Qt::WindowMinimizeButtonHint);

    QRect geometry = this->geometry();
    geometry.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(geometry);

    prestamo = new Prestamo();
    prestamo->initGUI(ui->centralWidget);

    user = new Usuarios();
//    user->inicializar(ui->centralWidget);

    banderaPersona=false;
    banderaLibro=false;

    solvencia = new Solvencia();
    solvencia->initGUI(ui->centralWidget);

    libro = new Libro();
//    libro->inicializar(ui->centralWidget);

}

void MainWindow::initConnect()
{
    connect(ui->btnPrestamo, SIGNAL(clicked()), this, SLOT(slotPrestamo()));
    connect(ui->btnEntrega, SIGNAL(clicked()), this, SLOT(slotEntregaPrestamo()));
    connect(ui->btnConsultar, SIGNAL(clicked()), this, SLOT(slotConsultaPrestamo()));

    connect(ui->btnAgregarP,SIGNAL(clicked()),this,SLOT(slotNewUser()));
    connect(ui->btnEditarP,SIGNAL(clicked()),this,SLOT(slotEditUser()));
    connect(ui->btnBuscarP,SIGNAL(clicked()),this,SLOT(slotSearchUser()));
    connect(ui->btnEliminarP,SIGNAL(clicked()),this,SLOT(slotDeleteUser()));

    connect(ui->btnAgregarL,SIGNAL(clicked()),this,SLOT(slotNewLibro()));

    connect(ui->btnSolvencia, SIGNAL(clicked()), this, SLOT(slotSolvencia()));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
}

void MainWindow::slotPrestamo()
{

    user->limpiar();
    libro->limpiar();
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    prestamo->visibleWidget(true);
}

void MainWindow::slotEntregaPrestamo()
{
    user->limpiar();
    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    solvencia->visibleWidget(false);

    prestamo->showEntregaPrestamo();
}

void MainWindow::slotConsultaPrestamo()
{
    user->limpiar();
    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    prestamo->showTablePrestamo();
}

void MainWindow::slotNewUser()
{

    if(banderaPersona==false){
        //user = new Usuarios();
        user->inicializar(ui->centralWidget);
        banderaPersona=true;
    }

    if(banderaLibro==true){
        libro->limpiar();
        libro->removeAll();
        banderaLibro=false;
    }

    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->nuevoUser();
}

void MainWindow::slotEditUser()
{
    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->editarUsuario();
}

void MainWindow::slotSearchUser()
{
    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->buscarUsuario();
}

void MainWindow::slotDeleteUser()
{

    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->eliminarUsuario();
}

void MainWindow::slotNewLibro(){

    if(banderaPersona==true){
        user->limpiar();
        user->removeall();
        banderaPersona=false;
    }

    if(banderaLibro==false){
        //libro = new Libro();
        libro->inicializar(ui->centralWidget);
        banderaLibro=true;
    }

    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    libro->nuevoLibro();
}

void MainWindow::slotSolvencia()
{
    user->limpiar();
    libro->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);

    solvencia->visibleWidget(true);

}

void MainWindow::slotCloseWindow()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

