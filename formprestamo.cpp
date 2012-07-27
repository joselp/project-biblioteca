#include "formprestamo.h"
#include "ui_formprestamo.h"

FormPrestamo::FormPrestamo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPrestamo)
{
    ui->setupUi(this);

    initGUI();
}

FormPrestamo::~FormPrestamo()
{
    delete ui;
}

void FormPrestamo::initGUI()
{
    connect(ui->lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotValidateCota()));

    ui->lineEditAutor->setReadOnly(true);
    ui->lineEditTitulo->setReadOnly(true);

    ui->lineEditCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{0,11})"),this));
    connect(ui->lineEditCedula, SIGNAL(editingFinished()), this, SLOT(slotValidateCedula()));

    connect(ui->comboBoxTipoPrestamo, SIGNAL(activated(int)), this, SLOT(slotTipoPrestamo(int)));

    ui->lineEditFechaP->setText(QDate::currentDate().toString("dd/MM/yyyy"));

    ui->lineEditFechaE->setDate(QDate::currentDate());
    ui->lineEditFechaE->setMinimumDate(QDate::currentDate());

    connect(ui->btnPrestar, SIGNAL(clicked()), this, SLOT(slotPrestar()));
}

void FormPrestamo::slotValidateCota()
{
    if( ui->lineEditCota->text().isEmpty() )
        return;

    ui->lineEditCota->setText(ui->lineEditCota->text().toUpper());

    QString strQuery = "SELECT autor, titulo, ejemplar FROM libros WHERE cota = '" + ui->lineEditCota->text().toUpper() +"'";

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "La cota del Libro no existe");
        ui->lineEditCota->setText("");
        ui->lineEditAutor->setText("");
        ui->lineEditTitulo->setText("");
        ui->lineEditCota->setFocus();
    }else {
        ui->lineEditAutor->setText(query.value(0).toString());
        ui->lineEditTitulo->setText(query.value(1).toString());
        cantBook = query.value(2).toInt();
        ui->lineEditCedula->setFocus();
    }
}

void FormPrestamo::slotValidateCedula()
{
    if( ui->lineEditCedula->text().isEmpty() )
        return;

    QString strQuery = "SELECT tipo FROM personas WHERE cedula = "+ ui->lineEditCedula->text();

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "La cedula del usuario no existe.");
        ui->lineEditCedula->setText("");
        ui->lineEditCedula->setFocus();
    }else {

        if( (query.value(0).toString() == "Profesor") ) {
            ui->comboBoxTipoPrestamo->removeItem(2);
            ui->comboBoxTipoPrestamo->addItem("Aula - Profesor");
        }
        else {
            if( ui->comboBoxTipoPrestamo->count() == 3)
                ui->comboBoxTipoPrestamo->removeItem(2);
        }
    }
}

void FormPrestamo::slotTipoPrestamo(int item)
{
    if( item == 0 ) {
        ui->lineEditFechaE->setDate(QDate::currentDate());
    }
    else if( item == 1 ) {

        if ( QDate::currentDate().dayOfWeek() == 3 )
            ui->lineEditFechaE->setDate(QDate::currentDate().addDays(5));
        else if ( QDate::currentDate().dayOfWeek() == 4 )
            ui->lineEditFechaE->setDate(QDate::currentDate().addDays(4));
        else
            ui->lineEditFechaE->setDate(QDate::currentDate().addDays(3));
    }
    else {
       ui->lineEditFechaE->setDate(QDate::currentDate());
    }
}

void FormPrestamo::slotPrestar()
{
    if( ui->lineEditCota->text().isEmpty() || ui->lineEditAutor->text().isEmpty() || ui->lineEditTitulo->text().isEmpty()
        || ui->lineEditCedula->text().isEmpty() || ui->lineEditFechaP->text().isEmpty()
        || ui->lineEditFechaE->text().isEmpty() ) {

        QMessageBox::warning(this,"ADVERTENCIA","No debe dejar campos vacios.");

        return;
    }

    QDate fechaE = ui->lineEditFechaE->date();
    fechaE.toString("dd/MM/yyyy");

    if( fechaE.dayOfWeek() == 6 || fechaE.dayOfWeek() == 7 ){
        QMessageBox::information(this, "INFORMACIÓN", "La fecha de entrega no puede ser Sábado ni Domingo.");

        ui->lineEditFechaE->setFocus();

        return;
    }

    QString strQuery;

    if( cantBook > 0 ) {
        strQuery = "UPDATE libros SET ejemplar = " + QString::number(cantBook - 1)
                + " WHERE cota = '" + ui->lineEditCota->text() + "'";

        query.exec(strQuery);
    }
    else {
        QMessageBox::warning(this, "ADVERTENCIA", "No hay disponibilidad del libro.");

        ui->lineEditCota->setText("");
        ui->lineEditAutor->setText("");
        ui->lineEditTitulo->setText("");
        ui->lineEditCota->setFocus();

        return;

    }

    strQuery = "INSERT INTO libroPersona VALUES ( '" + ui->lineEditCota->text()
               + "', '" + ui->lineEditCedula->text() + "', '" + ui->lineEditFechaP->text()
               + "', '" + ui->lineEditFechaE->text() + "', '"
               + ui->comboBoxResponsable->currentText()+ "' )";

    if( query.exec(strQuery) )
        QMessageBox::information(this, "INFORMACIÓN", "Se ha realizado el prestamo del libro exitosamente.");

    clearWidget();
}

void FormPrestamo::clearWidget()
{
    ui->lineEditCota->setFocus();
    ui->lineEditCota->setText("");
    ui->lineEditAutor->setText("");
    ui->lineEditTitulo->setText("");
    ui->lineEditCedula->setText("");
    ui->comboBoxTipoPrestamo->removeItem(2);
    ui->comboBoxTipoPrestamo->setCurrentIndex(0);
    ui->lineEditFechaE->setDate(QDate::currentDate());
    ui->comboBoxResponsable->setCurrentIndex(0);
}

void FormPrestamo::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == 16777220 )
        slotPrestar();
}
