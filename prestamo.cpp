#include "prestamo.h"
#include <QDebug>

Prestamo::Prestamo(QWidget *parent) :
        QWidget(parent)
{

}

void Prestamo::initGUI(QWidget *central)
{
    lblCota = new QLabel(central);
    lblCota->setText("Cota: ");
    lblCota->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCota->move(QPoint(255,140));
    lblCota->setVisible(false);

    lineEditCota = new QLineEdit(central);
    lineEditCota->move(QPoint(305,140));
    lineEditCota->setVisible(false);
    connect(lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotValidate()));

    lblAutor = new QLabel(central);
    lblAutor->setText("Autor: ");
    lblAutor->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblAutor->move(QPoint(245,170));
    lblAutor->setVisible(false);

    lineEditAutor = new QLineEdit(central);
    lineEditAutor->move(QPoint(305,170));
    lineEditAutor->setReadOnly(true);
    lineEditAutor->setVisible(false);

    lblTitulo = new QLabel(central);
    lblTitulo->setText("Titulo: ");
    lblTitulo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblTitulo->move(QPoint(242,200));
    lblTitulo->setVisible(false);

    lineEditTitulo = new QLineEdit(central);
    lineEditTitulo->move(QPoint(305,200));
    lineEditTitulo->setReadOnly(true);
    lineEditTitulo->setVisible(false);

    lblTipoPrestamo = new QLabel(central);
    lblTipoPrestamo->setText("Tipo Préstamo: ");
    lblTipoPrestamo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblTipoPrestamo->move(QPoint(180,230));
    lblTipoPrestamo->setVisible(false);

    comboBoxTipoPrestamo = new QComboBox(central);
    comboBoxTipoPrestamo->setGeometry(305,230,121,22);
    comboBoxTipoPrestamo->addItem("Aula");
    comboBoxTipoPrestamo->addItem("Hogar");
    comboBoxTipoPrestamo->addItem("Profesor");
    comboBoxTipoPrestamo->setVisible(false);

    lblGrado = new QLabel(central);
    lblGrado->setText("Grado: ");
    lblGrado->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblGrado->move(QPoint(243,260));
    lblGrado->setVisible(false);

    comboBoxGrado = new QComboBox(central);
    comboBoxGrado->setGeometry(305,260,121,22);
    comboBoxGrado->addItem("1º Grado");
    comboBoxGrado->addItem("2º Grado");
    comboBoxGrado->addItem("3º Grado");
    comboBoxGrado->addItem("4º Grado");
    comboBoxGrado->addItem("5º Grado");
    comboBoxGrado->addItem("6º Grado");
    comboBoxGrado->addItem("7º Grado");
    comboBoxGrado->addItem("8º Grado");
    comboBoxGrado->addItem("9º Grado");
    comboBoxGrado->setVisible(false);

    lblCedula = new QLabel(central);
    lblCedula->setText("Cédula: ");
    lblCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCedula->move(QPoint(518,140));
    lblCedula->setVisible(false);

    lineEditCedula = new QLineEdit(central);
    lineEditCedula->move(QPoint(585,140));
    lineEditCedula->setValidator(new QIntValidator(0,99999999,this));
    lineEditCedula->setVisible(false);

    lblFechaP = new QLabel(central);
    lblFechaP->setText("Fecha Préstamo: ");
    lblFechaP->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblFechaP->move(QPoint(455,170));
    lblFechaP->setVisible(false);

    lineEditFechaP = new QLineEdit(central);
    lineEditFechaP->move(QPoint(585,170));
    lineEditFechaP->setToolTip("El formato de la fecha es: DD/MM/AAAA");

    QString expDia("([0-2]\\d|[3][0-1])");
    QString expMes("/([0]\\d)/|/([1][0-2])/");
    QString expAnho("[0-9]{4}");
    QRegExp expFecha(expDia.append(expMes.append(expAnho)));

    lineEditFechaP->setValidator(new QRegExpValidator(QRegExp(expFecha),this));
    lineEditFechaP->setVisible(false);

    btnCalendar = new QPushButton(central);
    btnCalendar->setIcon(QIcon(":/images/calendar.png"));
    btnCalendar->setGeometry(726,170,21,21);
    connect(btnCalendar, SIGNAL(clicked()), this, SLOT(slotCalendar()));
    btnCalendar->setVisible(false);

    calendarWidget = new QCalendarWidget;
    calendarWidget->setVisible(false);

    lblFechaE = new QLabel(central);
    lblFechaE->setText("Fecha Entrega: ");
    lblFechaE->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblFechaE->move(QPoint(467,200));
    lblFechaE->setVisible(false);

    lineEditFechaE = new QLineEdit(central);
    lineEditFechaE->move(QPoint(585,200));
    lineEditFechaE->setToolTip("El formato de la fecha es: DD/MM/AAAA");
    lineEditFechaE->setReadOnly(true);
    lineEditFechaE->setVisible(false);

    lblCategoria = new QLabel(central);
    lblCategoria->setText("Categoría: ");
    lblCategoria->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCategoria->move(QPoint(500,230));
    lblCategoria->setVisible(false);

    lineEditCategoria = new QLineEdit(central);
    lineEditCategoria->move(QPoint(585,230));
    lineEditCategoria->setReadOnly(true);
    lineEditCategoria->setVisible(false);

    lblCantidad = new QLabel(central);
    lblCantidad->setText("Cantidad: ");
    lblCantidad->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCantidad->move(QPoint(505,260));
    lblCantidad->setVisible(false);

    lineEditCantidad = new QLineEdit(central);
    lineEditCantidad->setGeometry(585,260,45,20);
    lineEditCantidad->setValidator(new QIntValidator(1,100,this));
    lineEditCantidad->setVisible(false);

    lblStatus = new QLabel(central);
    lblStatus->setText("Estado: ");
    lblStatus->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblStatus->move(QPoint(645,260));
    lblStatus->setVisible(false);

    lineEditStatus = new QLineEdit(central);
    lineEditStatus->setGeometry(710,260,70,20);
    lineEditStatus->setStyleSheet("background-color: rgb(255, 255, 127);");
    lineEditStatus->setText("[P] Préstamo");
    lineEditStatus->setReadOnly(true);
    lineEditStatus->setVisible(false);

    lblResponsable = new QLabel(central);
    lblResponsable->setText("Responsable: ");
    lblResponsable->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblResponsable->move(QPoint(390,300));
    lblResponsable->setVisible(false);

    comboBoxResponsable = new QComboBox(central);
    comboBoxResponsable->setGeometry(495,300,51,22);
    comboBoxResponsable->addItem("01");
    comboBoxResponsable->addItem("02");
    comboBoxResponsable->setVisible(false);

    btnRegistrar = new QPushButton(central);
    btnRegistrar->setText("&Registrar");
    btnRegistrar->move(455,350);
    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotRegistrar()));
    btnRegistrar->setVisible(false);

}

void Prestamo::visibleWidget(bool visible)
{

    lblCota->setVisible(visible);
    lineEditCota->setVisible(visible);
    lineEditCota->setText("");

    lblAutor->setVisible(visible);
    lineEditAutor->setVisible(visible);
    lineEditAutor->setText("");

    lblTitulo->setVisible(visible);
    lineEditTitulo->setVisible(visible);
    lineEditTitulo->setText("");

    lblTipoPrestamo->setVisible(visible);
    comboBoxTipoPrestamo->setVisible(visible);

    lblGrado->setVisible(visible);
    comboBoxGrado->setVisible(visible);

    lblCedula->setVisible(visible);
    lineEditCedula->setVisible(visible);
    lineEditCedula->setText("");

    lblFechaP->setVisible(visible);
    lineEditFechaP->setVisible(visible);
    lineEditFechaP->setText("");
    btnCalendar->setVisible(visible);

    lblFechaE->setVisible(visible);
    lineEditFechaE->setVisible(visible);
    lineEditFechaE->setText("");

    lblCategoria->setVisible(visible);
    lineEditCategoria->setVisible(visible);
    lineEditCategoria->setText("");

    lblCantidad->setVisible(visible);
    lineEditCantidad->setVisible(visible);
    lineEditCantidad->setText("");

    lblStatus->setVisible(visible);
    lineEditStatus->setVisible(visible);

    lblResponsable->setVisible(visible);
    comboBoxResponsable->setVisible(visible);

    btnRegistrar->setVisible(visible);

}

void Prestamo::slotCalendar()
{

    calendarWidget->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    calendarWidget->setWindowIcon(QIcon(":/images/calendar.png"));
    calendarWidget->setWindowTitle("Fecha Prestamo");
    calendarWidget->setGeometry(685, 250, 220, 150);
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(slotDate(QDate)));

    calendarWidget->setVisible(true);
}

void Prestamo::slotValidate()
{
    if( lineEditCota->text().isEmpty() )
        return;

    QString strQuery = "SELECT autor, titulo, ejemplar FROM libros WHERE cota = " + lineEditCota->text();
    qDebug() << strQuery;

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "La cota del Libro no existe");
        lineEditCota->setText("");
        lineEditAutor->setText("");
        lineEditTitulo->setText("");
        lineEditCategoria->setText("");
        lineEditCota->setFocus();
    }else {
        lineEditAutor->setText(query.value(0).toString());
        lineEditTitulo->setText(query.value(1).toString());
        cantBook = query.value(2).toInt();
        lineEditCategoria->setText("ELIminar esto!!");
    }

}

void Prestamo::slotDate(QDate date)
{

    lineEditFechaP->setValidator(new QRegExpValidator(QRegExp(date.toString("dd/MM/yyyy")),this));
    lineEditFechaP->setText(date.toString("dd/MM/yyyy"));

    calendarWidget->close();

    if( comboBoxTipoPrestamo->currentText() == "Aula" ) {
        lineEditFechaE->setText(date.toString("dd/MM/yyyy"));
    }
    else if( comboBoxTipoPrestamo->currentText() == "Hogar" ) {

        if ( date.dayOfWeek() == 3 )
            lineEditFechaE->setText(date.addDays(5).toString("dd/MM/yyyy"));
        else if ( date.dayOfWeek() == 4 )
            lineEditFechaE->setText(date.addDays(4).toString("dd/MM/yyyy"));
        else
            lineEditFechaE->setText(date.addDays(3).toString("dd/MM/yyyy"));
    }
    else {
        lineEditFechaE->setText(date.addDays(7).toString("dd/MM/yyyy"));
    }

}

void Prestamo::slotRegistrar()
{
    if( lineEditCota->text().isEmpty() || lineEditAutor->text().isEmpty() || lineEditTitulo->text().isEmpty()
            || lineEditCedula->text().isEmpty() || lineEditFechaP->text().isEmpty()
            || lineEditFechaE->text().isEmpty() || lineEditCategoria->text().isEmpty()
            || lineEditCantidad->text().isEmpty() ) {

            QMessageBox::warning(this,"Advertencia - Campos Vacios","No debe dejar campos vacios.");

            return;
        }

    QString strQuery = "SELECT cedula FROM personas WHERE cedula = " + lineEditCedula->text();
    qDebug() << strQuery;

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {

        QMessageBox::warning(this, "Advertencia", "La persona no existe.");
        lineEditCedula->setText("");
        lineEditCedula->setFocus();

    }else {

        if( lineEditCantidad->text().toInt() == 0 ) {

            QMessageBox::warning(this, "Advertencia", "La cantidad no puede ser cero.");
            lineEditCantidad->setText("");
            lineEditCantidad->setFocus();
        }
        else if ( lineEditCantidad->text().toInt() <= cantBook ) {

            strQuery = "UPDATE libros SET ejemplar = " + QString::number(cantBook - lineEditCantidad->text().toInt())
                       + " WHERE cota = " + lineEditCota->text();
            qDebug() << strQuery;

            query.exec(strQuery);
        }
        else {

            QMessageBox::warning(this, "Advertencia", "La cantidad es mayor a la existente en la Base de Datos.");
            lineEditCantidad->setText("");
            lineEditCantidad->setFocus();
            return;
        }


        strQuery = "INSERT INTO libroPersona VALUES ( '" + lineEditCedula->text()
                    + "', '" + lineEditCota->text() + "', '" + lineEditFechaP->text()
                    + "', '" + lineEditFechaE->text() + "', '"
                    + comboBoxResponsable->currentText()+ "' )";

        qDebug() << strQuery;

        query.exec(strQuery);

        visibleWidget(false);
    }
}
