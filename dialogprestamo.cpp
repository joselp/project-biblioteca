#include "dialogprestamo.h"
#include "ui_dialogprestamo.h"

DialogPrestamo::DialogPrestamo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogPrestamo)
{
    ui->setupUi(this);

    initGUI();
}

void DialogPrestamo::initGUI()
{

    setWindowIcon(QIcon(":/images/logo.png"));
    setWindowFlags(Qt::WindowMaximizeButtonHint);

    QRect geometry = this->geometry();
    geometry.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(geometry);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slotAceptar()));
}

void DialogPrestamo::setNombre(QString nombre)
{
    ui->lineEditNombre->setText(nombre);
}

void DialogPrestamo::setApellido(QString apellido)
{
    ui->lineEditApellido->setText(apellido);
}

void DialogPrestamo::setCedula(QString cedula)
{
    ui->lineEditCedula->setText(cedula);
}

void DialogPrestamo::setTipoUser(QString tipo)
{
    ui->lblTipo->setText(tipo);
}

void DialogPrestamo::setCota(QString cota)
{
    ui->lineEditCota->setText(cota);
}

void DialogPrestamo::setAutor(QString autor)
{
    ui->lineEditAutor->setText(autor);
}

void DialogPrestamo::setTitulo(QString titulo)
{
    ui->lineEditTitulo->setText(titulo);
}

void DialogPrestamo::setEditorial(QString editorial)
{
    ui->lineEditEditorial->setText(editorial);
}

void DialogPrestamo::setPublicacion(QString publicacion)
{
    ui->lineEditPublicacion->setText(publicacion);
}

void DialogPrestamo::setEjemplar(QString ejemplar)
{
    ui->lineEditEjemplar->setText(ejemplar);
}

void DialogPrestamo::setAdquisicion(QString adquisicion)
{
    ui->lineEditAdquisicion->setText(adquisicion);
}

void DialogPrestamo::setEstado(QString estado)
{
    ui->lineEditEstado->setText(estado);
}

void DialogPrestamo::slotAceptar()
{
    close();
}

DialogPrestamo::~DialogPrestamo()
{
    delete ui;
}
