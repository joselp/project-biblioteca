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

    ui->lblEscudo->setVisible(false);
    ui->lblTitulo->setVisible(false);
    ui->lblLibro->setVisible(false);

    FormHome *formHome = new FormHome(this);
    ui->horizontalLayout->addWidget(formHome);
    ptrWidget = formHome;

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

void MainWindow::includeHead()
{
    ui->lblEscudo->setVisible(true);
    ui->lblTitulo->setVisible(true);
    ui->lblLibro->setVisible(true);
}

void MainWindow::slotHome()
{
    ui->lblEscudo->setVisible(false);
    ui->lblTitulo->setVisible(false);
    ui->lblLibro->setVisible(false);

    FormHome *formHome = new FormHome(this);
    deletePanel();
    ui->horizontalLayout->addWidget(formHome);
    ptrWidget = formHome;

}

void MainWindow::deletePanel(){

    if(!ui->verticalLayout->isEmpty())
        delete(ptrWidget);

    if( !ui->horizontalLayout->isEmpty() )
        delete(ptrWidget);
}

void MainWindow::changePanel(QWidget *widget){

    deletePanel();
    ui->verticalLayout->addWidget(widget);
}

void MainWindow::slotPrestamo()
{
    includeHead();

    FormPrestamo *formPrestamo = new FormPrestamo(this);
    changePanel(formPrestamo);
    ptrWidget = formPrestamo;
}

void MainWindow::slotEntregaPrestamo()
{
    includeHead();

    FormERPrestamo *formERPrestamo = new FormERPrestamo(this);
    formERPrestamo->setTipoBoton(0);
    changePanel(formERPrestamo);
    ptrWidget = formERPrestamo;
}

void MainWindow::slotRenovacion()
{
    includeHead();

    FormERPrestamo *formERPrestamo = new FormERPrestamo(this);
    formERPrestamo->setTipoBoton(1);
    changePanel(formERPrestamo);
    ptrWidget = formERPrestamo;
}

void MainWindow::slotConsultaPrestamo()
{
    includeHead();

    FormSearchPrestamo *formSearchPrestamo = new FormSearchPrestamo(this);
    changePanel(formSearchPrestamo);
    ptrWidget = formSearchPrestamo;
}

void MainWindow::slotNewUser()
{
    includeHead();

    FormAddUser *NewUser=new FormAddUser(this);
    changePanel(NewUser);
    ptrWidget=NewUser;

}

void MainWindow::slotEditUser()
{
    includeHead();

    FormEditUser *editUser = new FormEditUser(this);
    changePanel(editUser);
    ptrWidget=editUser;
}

void MainWindow::slotSearchUser()
{
    includeHead();

    FormSearchUser *searchUser = new FormSearchUser(this);
    changePanel(searchUser);
    ptrWidget=searchUser;

}

void MainWindow::slotDeleteUser()
{
    includeHead();

    FormDeleteUser *deleteUser = new FormDeleteUser(this);
    changePanel(deleteUser);
    ptrWidget=deleteUser;
}

void MainWindow::slotNewBook()
{
    includeHead();

    FormAddBook *addBook = new FormAddBook(this);
    changePanel(addBook);
    ptrWidget=addBook;
}

void MainWindow::slotSearchBook()
{
    includeHead();

    FormSearchBook *searchBook = new FormSearchBook(this);
    changePanel(searchBook);
    ptrWidget=searchBook;

}

void MainWindow::slotEditBook()
{
    includeHead();

    FormEditBook *editBook = new FormEditBook(this);
    changePanel(editBook);
    ptrWidget=editBook;

}

void MainWindow::slotDeleteBook()
{
    includeHead();

    FormDeleteBook *deleteBook = new FormDeleteBook(this);
    changePanel(deleteBook);
    ptrWidget=deleteBook;
}

void MainWindow::slotSolvencia()
{
    includeHead();

    FormSolvencia *formSolvencia = new FormSolvencia(this);
    changePanel(formSolvencia);
    ptrWidget = formSolvencia;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    if( manualUsuario->isWindow() )
        manualUsuario->close();

}

void MainWindow::slotCloseWindow()
{
    if( manualUsuario->isWindow() )
        manualUsuario->close();

    close();
    exit(0);
}

void MainWindow::slotCargarLibros()
{
    Utils * util = new Utils;
    util->cargarArchivo(ui->centralWidget);
}

void MainWindow::slotManualUsuario()
{
    manualUsuario = new ManualUsuario;
    manualUsuario->show();
}

void MainWindow::slotAbout()
{
    QString text = "<h2><center> MainWindow </center></h2>\n<center> Version 1.0 </center><br><br><br>"
                   "Es una aplicación. <br><br>"
                   "<center><b>Desarrollado por: </b><br>"
                   "Rossy Mayoral <br> Jose Pérez <br> Jonathan Monsalve <br>"
                   "Ana Calderon <br> Julio Muchacho <br> Antonio López <br><br>"
                   "Dirección electronica: <br>"
                   "...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> ...@ula.ve <br> antoniol@ula.ve<br> </center>"
                   "<font color = blue><center> Universidad de los Andes </center></font>";

    QMessageBox::about(this,"Acerca de MainWindow",text);

}

MainWindow::~MainWindow()
{
    delete ui;
}
