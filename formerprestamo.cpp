#include "formerprestamo.h"
#include "ui_formerprestamo.h"

FormERPrestamo::FormERPrestamo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormERPrestamo)
{
    ui->setupUi(this);

    initGUI();
}

FormERPrestamo::~FormERPrestamo()
{
    delete ui;
}

void FormERPrestamo::initGUI()
{
    connect(ui->lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotUpperText()));
}

void FormERPrestamo::setTipoBoton(int tipo)
{
    this->tipo = tipo;

    if( tipo == 0 ) {
        ui->btnAceptar->setText("&Entregar");
        connect(ui->btnAceptar, SIGNAL(clicked()), this, SLOT(slotEntregar()));
    }
    else {
        ui->btnAceptar->setText("&Renovar");
        connect(ui->btnAceptar, SIGNAL(clicked()), this, SLOT(slotRenovar()));
    }

}
void FormERPrestamo::slotUpperText()
{
    ui->lineEditCota->setText(ui->lineEditCota->text().toUpper());
}

void FormERPrestamo::slotEntregar()
{
    if( ui->lineEditCota->text().isEmpty() || ui->lineEditCedula->text().isEmpty() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No debe dejar campos vacios.");
        return;
    }

    QString strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + ui->lineEditCota->text().toUpper()
            + "' AND cedulaFk = " + ui->lineEditCedula->text();

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "Datos no existente en préstamo.");

        return;
    } else {

        strQuery = "SELECT ejemplar FROM libros WHERE cota = '" + ui->lineEditCota->text().toUpper() + "'";

        query.exec(strQuery);
        int ejemplar;

        if( query.next() ) {
            ejemplar = query.value(0).toInt();
            ejemplar += 1;
        }

        strQuery = "UPDATE libros SET ejemplar = " + QString::number(ejemplar)
                + " WHERE cota = '" + ui->lineEditCota->text().toUpper() + "'";

        query.exec(strQuery);

        strQuery = "DELETE FROM libroPersona WHERE cotaFk = '" + ui->lineEditCota->text().toUpper()
                + "' AND cedulaFk = " + ui->lineEditCedula->text();

        if( query.exec(strQuery) )
            QMessageBox::information(this, "INFORMACIÓN", "Se ha realizado la entrega exitosa.");

    }

    clearWidget();

}

void FormERPrestamo::slotRenovar()
{
    if( ui->lineEditCota->text().isEmpty() || ui->lineEditCedula->text().isEmpty() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No debe dejar campos vacios.");
        return;
    }

    QString strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + ui->lineEditCota->text().toUpper()
                       + "' AND cedulaFk = " + ui->lineEditCedula->text();

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "Datos no existente en préstamo.");

        return;
    } else {

        QDate fecha;
        fecha = QDate::fromString(query.value(3).toString(),"dd/MM/yyyy");

        QString fechaUpdate;

        if( fecha.dayOfWeek() == 4  )
            fechaUpdate = fecha.addDays(4).toString("dd/MM/yyyy");
        else if( fecha.dayOfWeek() == 5 )
            fechaUpdate = fecha.addDays(3).toString("dd/MM/yyyy");
        else
            fechaUpdate = fecha.addDays(2).toString("dd/MM/yyyy");

        strQuery = "UPDATE libroPersona SET fechaEntrega = '" + fechaUpdate
                   + "' WHERE cotaFk = '" + ui->lineEditCota->text().toUpper() + "'"
                   + " AND cedulaFk = " + ui->lineEditCedula->text();

        if( query.exec(strQuery) )
            QMessageBox::information(this, "INFORMACIÓN", "Se ha realizado la renovación exitosa.");

    }

    clearWidget();
}

void FormERPrestamo::clearWidget()
{
    ui->lineEditCota->setFocus();
    ui->lineEditCota->setText("");
    ui->lineEditCedula->setText("");
}

void FormERPrestamo::keyPressEvent(QKeyEvent * event)
{
    if( event->key() == 16777220 ) {
        if( this->tipo == 0 )
            slotEntregar();
        else
            slotRenovar();
    }
}






