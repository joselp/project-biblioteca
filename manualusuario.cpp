#include "manualusuario.h"
#include "ui_manualusuario.h"

ManualUsuario::ManualUsuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManualUsuario)
{
    ui->setupUi(this);

    initGUI();
    initAction();
    initToolBar();
}

void ManualUsuario::initGUI()
{
    setWindowTitle("Manual de Usuario");
    setWindowIcon(QIcon(":/images/help.png"));

}

void ManualUsuario::initAction()
{
    actionHome = new QAction(QIcon(":/images/home.png"),"Inicio",this);
    connect(actionHome, SIGNAL(triggered()), this, SLOT(slotHome()));
    actionBack = new QAction(QIcon(":/images/back.png"),"Ir Atras",this);
    connect(actionBack, SIGNAL(triggered()), this, SLOT(slotBack()));
    actionForward = new QAction(QIcon(":/images/forward.png"),"Ir Adelante",this);
    connect(actionForward, SIGNAL(triggered()), this, SLOT(slotForward()));
}

void ManualUsuario::initToolBar()
{
    toolBar = new QToolBar;
    toolBar->setMovable(false);
    toolBar->addAction(actionHome);
    toolBar->addSeparator();
    toolBar->addAction(actionBack);
    toolBar->addAction(actionForward);

    addToolBar(toolBar);

}

void ManualUsuario::slotHome()
{
    ui->webView->load(QUrl("qrc:/manual/index.html"));
}

void ManualUsuario::slotBack()
{
    ui->webView->page()->triggerAction(QWebPage::Back);
}

void ManualUsuario::slotForward()
{
    ui->webView->page()->triggerAction(QWebPage::Forward);
}

ManualUsuario::~ManualUsuario()
{
    delete ui;
}
