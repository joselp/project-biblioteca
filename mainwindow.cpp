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

    lblTitulo = new QLabel(ui->centralWidget);
    lblTitulo->setPixmap(QPixmap(":/images/tituloHome.png"));
    lblTitulo->setGeometry(245,50,468,72);

    lblEscudo = new QLabel(ui->centralWidget);
    lblEscudo->setPixmap(QPixmap(":/images/escudoHome.png"));
    lblEscudo->setGeometry(370,160,200,250);

    ui->lblEscudo->setVisible(false);
    ui->lblTitulo->setVisible(false);
    ui->lblLibro->setVisible(false);

    prestamo = new Prestamo();
    prestamo->initGUI(ui->centralWidget);

    user = new Usuarios();
    user->inicializar(ui->centralWidget);

    solvencia = new Solvencia();
    solvencia->initGUI(ui->centralWidget);

    libro = new Libro();
    libro->inicializar(ui->centralWidget);

    util = new Utils();
   // util->cargarArchivo();



}

void MainWindow::initConnect()
{
    connect(ui->actionInicio, SIGNAL(triggered()), this, SLOT(slotHome()));
    connect(ui->actionCargar_Lote_libros, SIGNAL(triggered()), this, SLOT(slotCargarLibros()));

    connect(ui->actionPrestar, SIGNAL(triggered()), this, SLOT(slotPrestamo()));
    connect(ui->actionEntregar, SIGNAL(triggered()), this, SLOT(slotEntregaPrestamo()));
    connect(ui->actionRenovar, SIGNAL(triggered()), this, SLOT(slotRenovacion()));
    connect(ui->actionConsultar, SIGNAL(triggered()), this, SLOT(slotConsultaPrestamo()));

    connect(ui->actionAgregar, SIGNAL(triggered()), this, SLOT(slotNewUser()));
    connect(ui->actionBuscar, SIGNAL(triggered()), this, SLOT(slotSearchUser()));
    connect(ui->actionEditar, SIGNAL(triggered()), this, SLOT(slotEditUser()));
    connect(ui->actionEliminar, SIGNAL(triggered()), this, SLOT(slotDeleteUser()));

    connect(ui->actionAgregar_2, SIGNAL(triggered()), this, SLOT(slotNewBook()));
    connect(ui->actionBuscar_2, SIGNAL(triggered()), this, SLOT(slotSearchBook()));
    connect(ui->actionEditar_2, SIGNAL(triggered()), this, SLOT(slotEditBook()));
    connect(ui->actionEliminar_2, SIGNAL(triggered()), this, SLOT(slotDeleteBook()));

    connect(ui->actionSolvencia, SIGNAL(triggered()), this, SLOT(slotSolvencia()));

    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
    connect(ui->actionManual_de_Usuario, SIGNAL(triggered()), this, SLOT(slotManualUsuario()));
    connect(ui->actionAcerca, SIGNAL(triggered()), this, SLOT(slotAbout()));

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
}

void MainWindow::includeHome()
{
    lblTitulo->setVisible(false);
    lblEscudo->setVisible(false);
}

void MainWindow::includeHead()
{
    includeHome();
    ui->lblEscudo->setVisible(true);
    ui->lblTitulo->setVisible(true);
    ui->lblLibro->setVisible(true);
}

void MainWindow::slotHome()
{
    ui->lblEscudo->setVisible(false);
    ui->lblTitulo->setVisible(false);
    ui->lblLibro->setVisible(false);

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    lblTitulo->setVisible(true);
    lblEscudo->setVisible(true);
}

void MainWindow::deletePanel(){

    if(!ui->verticalLayout->isEmpty())
        delete(ptrWidget);
}

void MainWindow::changePanel(QWidget *widget){

    deletePanel();
    ui->verticalLayout->addWidget(widget);
}

void MainWindow::slotPrestamo()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showPrestamo();
}

void MainWindow::slotEntregaPrestamo()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showEntrega();
}

void MainWindow::slotRenovacion()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showRenovacion();

}

void MainWindow::slotConsultaPrestamo()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();
    solvencia->visibleWidget(false);

    prestamo->showTablePrestamo();
}

void MainWindow::slotNewUser()
{
    includeHead();

    FormUsuario *newUs=new FormUsuario(this);
    changePanel(newUs);
    ptrWidget=newUs;


//    prestamo->clearWidget();
//    libro->limpiar();
//    solvencia->visibleWidget(false);

//    user->nuevoUser();
}

void MainWindow::slotEditUser()
{
    includeHead();

    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->editarUsuario();
}

void MainWindow::slotSearchUser()
{
    includeHead();

    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->buscarUsuario();
}

void MainWindow::slotDeleteUser()
{
    includeHead();

    prestamo->clearWidget();
    libro->limpiar();
    solvencia->visibleWidget(false);

    user->eliminarUsuario();
}

void MainWindow::slotNewBook()
{
    includeHead();

    FormLibro *uiL = new FormLibro(this);
    changePanel(uiL);
    ptrWidget=uiL;

//    prestamo->clearWidget();
//    user->limpiar();
//    solvencia->visibleWidget(false);

//    libro->nuevoLibro();
}

void MainWindow::slotSearchBook()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->buscarLibro();
}

void MainWindow::slotEditBook()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->editarLibro();
}

void MainWindow::slotDeleteBook()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    solvencia->visibleWidget(false);

    libro->eliminarLibro();
}

void MainWindow::slotSolvencia()
{
    includeHead();

    prestamo->clearWidget();
    user->limpiar();
    libro->limpiar();

    solvencia->visibleWidget(true);

}

void MainWindow::closeEvent(QCloseEvent *)
{
    prestamo->distroyedCalendar();

    if( manualUsuario->isWindow() )
        manualUsuario->close();

}

void MainWindow::slotCloseWindow()
{
    prestamo->distroyedCalendar();

    if( manualUsuario->isWindow() )
        manualUsuario->close();

    close();
}

void MainWindow::slotCargarLibros(){

    util->cargarArchivo(ui->centralWidget);
    //util->start();

}

void MainWindow::slotManualUsuario()
{
    manualUsuario = new ManualUsuario;
    manualUsuario->show();
}

void MainWindow::slotAbout()
{
    QString text = "<h2><center> MainWindow </center></h2>\n<center> Version 1.0 </center><br><br><br>"
                   "Es una aplicaci�n. <br><br>"
                   "<center><b>Desarrollado por: </b><br>"
                   "Rossy Mayoral <br> Jose P�rez <br> Jonathan Monsalve <br>"
                   "Ana Calderon <br> Julio Muchacho <br> Antonio L�pez <br><br>"
                   "Direcci�n electronica: <br>"
                   "...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> antoniol@ula.ve<br> </center>"
                   "<font color = blue><center> Universidad de los Andes </center></font>";


    QMessageBox::about(this,"Acerca de MainWindow",text);

}


MainWindow::~MainWindow()
{
    delete ui;
}
