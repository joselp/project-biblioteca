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

    libro = new Libro();
    libro->inicializar(ui->centralWidget);

}

void MainWindow::initConnect()
{
    connect(ui->btnPrestamo, SIGNAL(clicked()), this, SLOT(slotPrestamo()));
    connect(ui->btnEntrega, SIGNAL(clicked()), this, SLOT(slotEntregaPrestamo()));
    connect(ui->btnRenovacion, SIGNAL(clicked()), this, SLOT(slotRenovacion()));
    connect(ui->btnConsultar, SIGNAL(clicked()), this, SLOT(slotConsultaPrestamo()));

    connect(ui->btnAgregarP,SIGNAL(clicked()),this,SLOT(slotNewUser()));
    connect(ui->btnEditarP,SIGNAL(clicked()),this,SLOT(slotEditUser()));
    connect(ui->btnBuscarP,SIGNAL(clicked()),this,SLOT(slotSearchUser()));
    connect(ui->btnEliminarP,SIGNAL(clicked()),this,SLOT(slotDeleteUser()));

    connect(ui->btnAgregarL,SIGNAL(clicked()),this,SLOT(slotNewBook()));
    connect(ui->btnBuscarL,SIGNAL(clicked()),this,SLOT(slotSearchBook()));
    connect(ui->btnEditarL,SIGNAL(clicked()),this,SLOT(slotEditBook()));
    connect(ui->btnEliminarL,SIGNAL(clicked()),this,SLOT(slotDeleteBook()));

    connect(ui->btnSolvencia, SIGNAL(clicked()), this, SLOT(slotSolvencia()));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
}

void MainWindow::slotPrestamo()
{
    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showPrestamo();
}

void MainWindow::slotEntregaPrestamo()
{
    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showEntrega();
}

void MainWindow::slotRenovacion()
{
    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showRenovacion();
}

void MainWindow::slotConsultaPrestamo()
{
    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showTablePrestamo();
}

void MainWindow::slotNewUser()
{
    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->nuevoUser();
}

void MainWindow::slotEditUser()
{
    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->editarUsuario();
}

void MainWindow::slotSearchUser()
{
    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->buscarUsuario();
}

void MainWindow::slotDeleteUser()
{
    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->eliminarUsuario();
}

void MainWindow::slotNewBook()
{
    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->nuevoLibro();
}

void MainWindow::slotSearchBook()
{
    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->buscarLibro();
}

void MainWindow::slotEditBook()
{
    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->editarLibro();
}

void MainWindow::slotDeleteBook()
{
    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->eliminarLibro();
}

void MainWindow::slotSolvencia()
{
    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();

    solvencia->visibleWidget(true);

}

void MainWindow::closeEvent(QCloseEvent *)
{
    prestamo->distroyedCalendar();
}

void MainWindow::slotCloseWindow()
{
    prestamo->distroyedCalendar();
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

