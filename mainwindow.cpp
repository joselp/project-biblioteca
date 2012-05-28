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

    QRect geometry = this->geometry();
    geometry.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(geometry);


    user = new Usuarios(ui->centralWidget);
}

void MainWindow::initConnect()
{
    connect(ui->btnAgregarP, SIGNAL(clicked()), this, SLOT(slotNewUser()));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
}

void MainWindow::slotNewUser()
{
    user->nuevoUser();
}


void MainWindow::slotCloseWindow()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
