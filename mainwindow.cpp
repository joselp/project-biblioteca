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
    user->inicializar(ui->centralWidget);

    solvencia = new Solvencia();
    solvencia->initGUI(ui->centralWidget);

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

    connect(ui->btnSolvencia, SIGNAL(clicked()), this, SLOT(slotSolvencia()));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
}

void MainWindow::slotPrestamo()
{
    user->limpiar();
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    prestamo->visibleWidget(true);
}

void MainWindow::slotEntregaPrestamo()
{
    user->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    solvencia->visibleWidget(false);

    prestamo->showEntregaPrestamo();
}

void MainWindow::slotConsultaPrestamo()
{
    user->limpiar();
    prestamo->visibleWidget(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    prestamo->showTablePrestamo();
}

void MainWindow::slotNewUser()
{
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->nuevoUser();
}

void MainWindow::slotEditUser()
{
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->editarUsuario();
}

void MainWindow::slotSearchUser()
{
    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->buscarUsuario();
}

void MainWindow::slotDeleteUser()
{

    prestamo->visibleWidget(false);
    prestamo->visibleTable(false);
    prestamo->visibleEntrega(false);
    solvencia->visibleWidget(false);

    user->eliminarUsuario();
}

void MainWindow::slotSolvencia()
{
    user->limpiar();
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

