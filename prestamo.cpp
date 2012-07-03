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
    lblCota->move(QPoint(255,180));
    lblCota->setVisible(false);

    lineEditCota = new QLineEdit(central);
    lineEditCota->move(QPoint(305,180));
    lineEditCota->setVisible(false);

    lblAutor = new QLabel(central);
    lblAutor->setText("Autor: ");
    lblAutor->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblAutor->move(QPoint(245,210));
    lblAutor->setVisible(false);

    lineEditAutor = new QLineEdit(central);
    lineEditAutor->move(QPoint(305,210));
    lineEditAutor->setReadOnly(true);
    lineEditAutor->setVisible(false);

    lblTitulo = new QLabel(central);
    lblTitulo->setText("Titulo: ");
    lblTitulo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblTitulo->move(QPoint(242,240));
    lblTitulo->setVisible(false);

    lineEditTitulo = new QLineEdit(central);
    lineEditTitulo->move(QPoint(305,240));
    lineEditTitulo->setReadOnly(true);
    lineEditTitulo->setVisible(false);

    lblCedula = new QLabel(central);
    lblCedula->setText("Cédula: ");
    lblCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCedula->setVisible(false);

    lineEditCedula = new QLineEdit(central);
    lineEditCedula->setValidator(new QIntValidator(0,99999999,this));
    lineEditCedula->setVisible(false);

    lblTipoPrestamo = new QLabel(central);
    lblTipoPrestamo->setText("Tipo Préstamo: ");
    lblTipoPrestamo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblTipoPrestamo->move(QPoint(462,180));
    lblTipoPrestamo->setVisible(false);

    comboBoxTipoPrestamo = new QComboBox(central);
    comboBoxTipoPrestamo->setGeometry(585,180,121,22);
    comboBoxTipoPrestamo->addItem("Aula");
    comboBoxTipoPrestamo->addItem("Hogar");
    comboBoxTipoPrestamo->setVisible(false);
    connect(comboBoxTipoPrestamo, SIGNAL(activated(int)), this, SLOT(slotTipoPrestamo(int)));

    lblFechaP = new QLabel(central);
    lblFechaP->setText("Fecha Préstamo: ");
    lblFechaP->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblFechaP->move(QPoint(455,210));
    lblFechaP->setVisible(false);

    lineEditFechaP = new QLineEdit(central);
    lineEditFechaP->move(QPoint(585,210));
    lineEditFechaP->setReadOnly(true);
    lineEditFechaP->setToolTip("El formato de la fecha es: DD/MM/AAAA");
    lineEditFechaP->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    lineEditFechaP->setVisible(false);

    lblFechaE = new QLabel(central);
    lblFechaE->setText("Fecha Entrega: ");
    lblFechaE->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblFechaE->move(QPoint(467,240));
    lblFechaE->setVisible(false);

    lineEditFechaE = new QLineEdit(central);
    lineEditFechaE->move(QPoint(585,240));
    lineEditFechaE->setToolTip("El formato de la fecha es: DD/MM/AAAA");

    QString expDia("([0-2]\\d|[3][0-1])/");
    QString expMes("([0]\\d|[1][0-2])/");
    QString expAnho("([0-9]{4})");
    expFecha.setPattern(expDia.append(expMes.append(expAnho)));

    lineEditFechaE->setValidator(new QRegExpValidator(QRegExp(expFecha),this));
    lineEditFechaE->setVisible(false);

    btnCalendar = new QPushButton(central);
    btnCalendar->setIcon(QIcon(":/images/calendar.png"));
    btnCalendar->setGeometry(726,240,21,21);
    btnCalendar->setVisible(false);
    connect(btnCalendar, SIGNAL(clicked()), this, SLOT(slotCalendar()));

    calendarWidget = new QCalendarWidget;
    calendarWidget->setVisible(false);

    lblResponsable = new QLabel(central);
    lblResponsable->setText("Responsable: ");
    lblResponsable->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblResponsable->move(QPoint(480,270));
    lblResponsable->setVisible(false);

    comboBoxResponsable = new QComboBox(central);
    comboBoxResponsable->setGeometry(585,270,51,22);
    comboBoxResponsable->addItem("01");
    comboBoxResponsable->addItem("02");
    comboBoxResponsable->setVisible(false);

    btnRegistrar = new QPushButton(central);
    btnRegistrar->setVisible(false);

    lblFiltro = new QLabel(central);
    lblFiltro->setText("Filtrar: ");
    lblFiltro->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblFiltro->move(270,180);
    lblFiltro->setVisible(false);

    comboBoxFiltro = new QComboBox(central);
    comboBoxFiltro->move(340,180);
    comboBoxFiltro->addItem("Todas");
    comboBoxFiltro->addItem("Cota");
    comboBoxFiltro->addItem("Cédula");
    comboBoxFiltro->addItem("Fecha Préstamo");
    comboBoxFiltro->addItem("Fecha Entrega");
    comboBoxFiltro->addItem("Responsable");
    comboBoxFiltro->setVisible(false);
    connect(comboBoxFiltro, SIGNAL(currentIndexChanged(int)), this, SLOT(slotTipoFiltro(int)));

    lineEditFiltro = new QLineEdit(central);
    lineEditFiltro->move(465,180);
    lineEditFiltro->setReadOnly(true);
    lineEditFiltro->setVisible(false);

    tablePrestamo = new QTableWidget(central);
    tablePrestamo->setColumnCount(5);

    QStringList listHeader;
    listHeader << "Cota" << "Cédula" << "Fecha Préstamo" << "Fecha Entrega" <<"Responsable";
    tablePrestamo->setHorizontalHeaderLabels(listHeader);
    rowCount = tablePrestamo->rowCount();
    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), tablePrestamo, SLOT(selectRow(int)));
    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), this, SLOT(slotRowSelected(int)));

    tablePrestamo->setVisible(false);

}

void Prestamo::showPrestamo()
{
    lblCota->setVisible(true);
    lineEditCota->setVisible(true);
    lineEditCota->disconnect(this);
    connect(lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotValidateCota()));

    lblAutor->setVisible(true);
    lineEditAutor->setVisible(true);

    lblTitulo->setVisible(true);
    lineEditTitulo->setVisible(true);

    lblCedula->setVisible(true);
    lblCedula->move(QPoint(242,270));
    lineEditCedula->setVisible(true);
    lineEditCedula->move(QPoint(305,270));
    lineEditCedula->setText("");
    connect(lineEditCedula, SIGNAL(editingFinished()), this, SLOT(slotValidateCedula()));

    lblTipoPrestamo->setVisible(true);
    comboBoxTipoPrestamo->setVisible(true);
    comboBoxTipoPrestamo->setCurrentIndex(0);

    lblFechaP->setVisible(true);
    lineEditFechaP->setVisible(true);
    btnCalendar->setVisible(true);

    lblFechaE->setVisible(true);
    lineEditFechaE->setVisible(true);

    lblResponsable->setVisible(true);
    comboBoxResponsable->setVisible(true);

    btnRegistrar->disconnect(this);
    btnRegistrar->setVisible(true);
    btnRegistrar->setText("&Registrar");
    btnRegistrar->setIcon(QIcon(":/images/book.png"));
    btnRegistrar->setGeometry(435,340,75,23);
    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotRegistrar()));

}

void Prestamo::slotCalendar()
{

    calendarWidget->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    calendarWidget->setWindowIcon(QIcon(":/images/calendar.png"));
    calendarWidget->setWindowTitle("Fecha Entrega");
    calendarWidget->setGeometry(685, 290, 220, 150);
    calendarWidget->setMinimumDate(QDate::currentDate());
    calendarWidget->setSelectedDate(QDate::fromString(lineEditFechaE->text(),"dd/MM/yyyy"));
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(slotDate(QDate)));

    calendarWidget->setVisible(true);
}

void Prestamo::slotValidateCota()
{
    if( lineEditCota->text().isEmpty() )
        return;

    lineEditCota->setText(lineEditCota->text().toUpper());

    QString strQuery = "SELECT autor, titulo, ejemplar FROM libros WHERE cota = '"+ lineEditCota->text().toUpper() +"'";
    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "La cota del Libro no existe");
        lineEditCota->setText("");
        lineEditAutor->setText("");
        lineEditTitulo->setText("");
        lineEditCota->setFocus();
    }else {
        lineEditAutor->setText(query.value(0).toString());
        lineEditTitulo->setText(query.value(1).toString());
        cantBook = query.value(2).toInt();
    }

    lineEditCedula->setFocus();

}

void Prestamo::slotValidateCedula()
{
    if( lineEditCedula->text().isEmpty() )
        return;

    QString strQuery = "SELECT tipo FROM personas WHERE cedula = "+ lineEditCedula->text();
    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "La cedula del usuario no existe.");
        lineEditCedula->setText("");
        lineEditCedula->setFocus();
    }else {

        if( (query.value(0).toString() == "Profesor") ) {
            comboBoxTipoPrestamo->removeItem(2);
            comboBoxTipoPrestamo->addItem("Aula - Profesor");
        }
        else {
            if( comboBoxTipoPrestamo->count() == 3)
                comboBoxTipoPrestamo->removeItem(2);
        }
    }
}

void Prestamo::slotTipoPrestamo(int item)
{
    if( item == 0 ) {
        lineEditFechaE->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    }
    else if( item == 1 ) {

        if ( QDate::currentDate().dayOfWeek() == 3 )
            lineEditFechaE->setText(QDate::currentDate().addDays(5).toString("dd/MM/yyyy"));
        else if ( QDate::currentDate().dayOfWeek() == 4 )
            lineEditFechaE->setText(QDate::currentDate().addDays(4).toString("dd/MM/yyyy"));
        else
            lineEditFechaE->setText(QDate::currentDate().addDays(3).toString("dd/MM/yyyy"));
    }
    else {
       lineEditFechaE->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    }

}

void Prestamo::slotDate(QDate date)
{

    lineEditFechaE->setText("");
    lineEditFechaE->setValidator(new QRegExpValidator(QRegExp(expFecha),this));
    lineEditFechaE->setText(date.toString("dd/MM/yyyy"));
    calendarWidget->close();

}

void Prestamo::slotRegistrar()
{
    if( lineEditCota->text().isEmpty() || lineEditAutor->text().isEmpty() || lineEditTitulo->text().isEmpty()
        || lineEditCedula->text().isEmpty() || lineEditFechaP->text().isEmpty()
        || lineEditFechaE->text().isEmpty() ) {

        QMessageBox::warning(this,"Advertencia - Campos Vacios","No debe dejar campos vacios.");

        return;
    }

    QDate fechaP = QDate::fromString(lineEditFechaP->text(),"dd/MM/yyyy");
    QDate fechaE = QDate::fromString(lineEditFechaE->text(),"dd/MM/yyyy");

    if( fechaE < fechaP ) {
        QMessageBox::information(this, "Información", "La fecha de entrega no puede ser menor a la fecha de préstamo.");

        lineEditFechaE->setText("");
        lineEditFechaE->setFocus();

        return;
    }

    QString strQuery;

    if( cantBook > 0 ) {
        strQuery = "UPDATE libros SET ejemplar = " + QString::number(cantBook - 1)
                + " WHERE cota = '" + lineEditCota->text() + "'";
        qDebug() << strQuery;

        query.exec(strQuery);
    }
    else {
        QMessageBox::warning(this, "Advertencia", "No hay disponibilidad del libro.");

        lineEditCota->setText("");
        lineEditAutor->setText("");
        lineEditTitulo->setText("");
        lineEditCota->setFocus();

        return;

    }

    strQuery = "INSERT INTO libroPersona VALUES ( '" + lineEditCota->text()
               + "', '" + lineEditCedula->text() + "', '" + lineEditFechaP->text()
               + "', '" + lineEditFechaE->text() + "', '"
               + comboBoxResponsable->currentText()+ "' )";

    qDebug() << strQuery;

    query.exec(strQuery);

    prestamoWidget();
}

void Prestamo::showEntrega()
{

    lblCota->setVisible(true);
    lineEditCota->setVisible(true);
    lineEditCota->disconnect(this);
    connect(lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotUpperText()));

    lblCedula->setVisible(true);
    lblCedula->move(465,180);
    lineEditCedula->setVisible(true);
    lineEditCedula->move(530,180);
    lineEditCedula->disconnect(this);

    btnRegistrar->setVisible(true);
    btnRegistrar->setText("&Entregar");
    btnRegistrar->setIcon(QIcon(":/images/aceptar.png"));
    btnRegistrar->setGeometry(435,220,75,23);
    btnRegistrar->disconnect(this);
    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotAcceptEntrega()));

}

void Prestamo::slotUpperText()
{
    lineEditCota->setText(lineEditCota->text().toUpper());
}

void Prestamo::slotAcceptEntrega()
{
    if( lineEditCota->text().isEmpty() || lineEditCedula->text().isEmpty() ) {
        QMessageBox::warning(this, "Advertencia", "No debe dejar campos vacios.");
        return;
    }

    lineEditCota->setText(lineEditCota->text().toUpper());

    QString strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + lineEditCota->text().toUpper()
                       + "' AND cedulaFk = " + lineEditCedula->text();

    qDebug() << strQuery;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "Datos no existente en préstamo.");
        return;
    } else {

        strQuery = "SELECT ejemplar FROM libros WHERE cota = '" + lineEditCota->text().toUpper() + "'";

        qDebug() << strQuery;

        query.exec(strQuery);
        int ejemplar;

        if( query.next() ) {
            ejemplar = query.value(0).toInt();
            ejemplar += 1;
        }

        strQuery = "UPDATE libros SET ejemplar = " + QString::number(ejemplar)
                   + " WHERE cota = '" + lineEditCota->text().toUpper() + "'";

        qDebug() << strQuery;
        query.exec(strQuery);

        strQuery = "DELETE FROM libroPersona WHERE cotaFk = '" + lineEditCota->text().toUpper()
                   + "' AND cedulaFk = " + lineEditCedula->text();

        qDebug() << strQuery;


        if( query.exec(strQuery) ) {

            QMessageBox::information(this, "Información", "Se ha realizado la entrega exitosa.");
        }

    }

    clearWidget();
}

void Prestamo::showRenovacion()
{

    lblCota->setVisible(true);
    lineEditCota->setVisible(true);
    lineEditCota->disconnect(this);
    connect(lineEditCota, SIGNAL(editingFinished()), this, SLOT(slotUpperText()));

    lblCedula->setVisible(true);
    lblCedula->move(465,180);
    lineEditCedula->setVisible(true);
    lineEditCedula->move(530,180);
    lineEditCedula->disconnect(this);

    btnRegistrar->setVisible(true);
    btnRegistrar->setText("&Renovación");
    btnRegistrar->setIcon(QIcon(":/images/aceptar.png"));
    btnRegistrar->setGeometry(435,220,95,23);
    btnRegistrar->disconnect(this);
    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotRenovacion()));
}

void Prestamo::slotRenovacion()
{
    if( lineEditCota->text().isEmpty() || lineEditCedula->text().isEmpty() ) {
        QMessageBox::warning(this, "Advertencia", "No debe dejar campos vacios.");
        return;
    }

    lineEditCota->setText(lineEditCota->text().toUpper());

    QString strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + lineEditCota->text().toUpper()
                       + "' AND cedulaFk = " + lineEditCedula->text();

    qDebug() << strQuery;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "Datos no existente en préstamo.");
        return;
    } else {

        QDate fecha;
        fecha = QDate::fromString(query.value(3).toString(),"dd/MM/yyyy");
        qDebug()<< fecha.toString("dd/MM/yyyy");
        QString fechaUpdate;

        if( fecha.dayOfWeek() == 4  )
            fechaUpdate = fecha.addDays(4).toString("dd/MM/yyyy");
        else if( fecha.dayOfWeek() == 5 )
            fechaUpdate = fecha.addDays(3).toString("dd/MM/yyyy");
        else
            fechaUpdate = fecha.addDays(2).toString("dd/MM/yyyy");

        qDebug() << fechaUpdate;

        strQuery = "UPDATE libroPersona SET fechaEntrega = '" + fechaUpdate
                   + "' WHERE cotaFk = '" + lineEditCota->text().toUpper() + "'"
                   + " AND cedulaFk = " + lineEditCedula->text();

        qDebug() << strQuery;

        if( query.exec(strQuery) )
            QMessageBox::information(this, "Información", "Se ha realizado la renovación exitosa.");

    }

    clearWidget();

}

void Prestamo::showTablePrestamo()
{

    QString strQuery = "SELECT * FROM libroPersona";
    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "No existe libros en prestamo.");
        return;
    }
    else {

        lblFiltro->setVisible(true);
        comboBoxFiltro->setVisible(true);
        lineEditFiltro->setVisible(true);
        btnRegistrar->setVisible(true);
        btnRegistrar->setText("&Filtrar");
        btnRegistrar->setIcon(QIcon(":/images/ver.png"));
        btnRegistrar->setGeometry(620,180,75,21);
        btnRegistrar->disconnect(this);
        connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotFiltro()));

        tablePrestamo->setVisible(true);

        rowCount += 1;
        tablePrestamo->setRowCount(rowCount);
        rowCount = tablePrestamo->rowCount();

        if( rowCount < 6 )
            tablePrestamo->setGeometry(225,210,518,175);
        else
            tablePrestamo->setGeometry(212,210,534,173);

        for( int row = rowCount - 1; row < rowCount; row++ ) {

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(0).toString());
            tablePrestamo->setItem(row, 0, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(1).toString());
            tablePrestamo->setItem(row, 1, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(2).toString());
            tablePrestamo->setItem(row, 2, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(3).toString());
            tablePrestamo->setItem(row, 3, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(4).toString());
            tablePrestamo->setItem(row, 4, item);
        }

        while( query.next() ) {

            rowCount += 1;
            tablePrestamo->setRowCount(rowCount);
            rowCount = tablePrestamo->rowCount();

            if( rowCount < 6 )
                tablePrestamo->setGeometry(225,210,518,175);
            else
                tablePrestamo->setGeometry(212,210,534,173);

            for( int row = rowCount - 1; row < rowCount; row++ ) {

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(0).toString());
                tablePrestamo->setItem(row, 0, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(1).toString());
                tablePrestamo->setItem(row, 1, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(2).toString());
                tablePrestamo->setItem(row, 2, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(3).toString());
                tablePrestamo->setItem(row, 3, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(4).toString());
                tablePrestamo->setItem(row, 4, item);

            }
        }
    }

}

void Prestamo::slotRowSelected(int row)
{

    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,0);

    QString strQuery = "SELECT * FROM libros WHERE cota = '"
                       + item->text() + "'";

    qDebug() << strQuery;

    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,1);

    QString strQuery2 = "SELECT * FROM personas WHERE cedula = " + item->text();

    qDebug() << strQuery2;

    QSqlQuery query2;

    query.exec(strQuery);
    query2.exec(strQuery2);

    dialogPrestamo = new DialogPrestamo;

    if( query2.next() ) {

        dialogPrestamo->setNombre(query2.value(1).toString());
        dialogPrestamo->setApellido(query2.value(2).toString());
        dialogPrestamo->setCedula(query2.value(0).toString());
        dialogPrestamo->setTipoUser(query2.value(3).toString());

    }

    QString adquisicion;
    QString estado;

    if( query.next() ) {

        dialogPrestamo->setCota(query.value(0).toString());
        dialogPrestamo->setAutor(query.value(1).toString());
        dialogPrestamo->setTitulo(query.value(2).toString());
        dialogPrestamo->setEditorial(query.value(4).toString());
        dialogPrestamo->setPublicacion(query.value(5).toString());
        dialogPrestamo->setEjemplar(query.value(11).toString());

        if( query.value(7).toString() == "X" )
            adquisicion = "Canjeado";
        else if( query.value(8).toString() == "X" )
            adquisicion = "Donado";
        else if( query.value(9).toString() == "X" )
            adquisicion = "Comprado";
        dialogPrestamo->setAdquisicion(adquisicion);

        if( query.value(12).toString() == "X" )
            estado = "Bueno";
        else if( query.value(13).toString() == "X" )
            estado = "Regular";
        else if( query.value(14).toString() == "X" )
            estado = "Malo";
        dialogPrestamo->setEstado(estado);
    }

    dialogPrestamo->show();
}

void Prestamo::slotTipoFiltro(int item)
{
    if( item  == 0 ){
        lineEditFiltro->setText("");
        lineEditFiltro->setToolTip("");
        lineEditFiltro->setReadOnly(true);

    }
    else if( item == 1 ) {
        lineEditFiltro->setText("");
        lineEditFiltro->setToolTip("");
        lineEditFiltro->setReadOnly(false);
        lineEditFiltro->setValidator(new QRegExpValidator(this));
        connect(lineEditFiltro, SIGNAL(textChanged(QString)), this, SLOT(slotUpperText(QString)));

    }
    else if( item == 2 ) {
        lineEditFiltro->setText("");
        lineEditFiltro->setToolTip("");
        lineEditFiltro->setReadOnly(false);
        lineEditFiltro->setValidator(new QIntValidator(0,99999999,this));
    }
    else if( item == 3 ) {
        lineEditFiltro->setText("");
        lineEditFiltro->setReadOnly(false);
        lineEditFiltro->setToolTip("El formato de fecha es: DD/MM/AAAA");
        lineEditFiltro->setValidator(new QRegExpValidator(expFecha,this));

    }
    else if( item == 4 ) {
        lineEditFiltro->setText("");
        lineEditFiltro->setReadOnly(false);
        lineEditFiltro->setToolTip("El formato de fecha es: DD/MM/AAAA");
        lineEditFiltro->setValidator(new QRegExpValidator(expFecha,this));
    }
    else {
        lineEditFiltro->setText("");
        lineEditFiltro->setToolTip("");
        lineEditFiltro->setReadOnly(false);
        QRegExp expReg("(01|02)");
        lineEditFiltro->setValidator(new QRegExpValidator(expReg,this));
        QStringList list;
        list << "01" << "02" ;
        lineEditFiltro->setCompleter(new QCompleter(list));
    }
}

void Prestamo::slotUpperText(QString str)
{
    lineEditFiltro->setText(str.toUpper());
}

void Prestamo::slotFiltro()
{
    if( (lineEditFiltro->text().isEmpty()) && (comboBoxFiltro->currentIndex() != 0) ) {
        QMessageBox::warning(this,"Advertencia","No debe dejar el campo vacio.");
        lineEditFiltro->setFocus();
        return;
    }

    QString strQuery;

    if( comboBoxFiltro->currentIndex() == 0 ) {
        strQuery = "SELECT * FROM libroPersona";
        filtroTable(strQuery);
    }
    else if( comboBoxFiltro->currentIndex() == 1 ) {
        strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else if( comboBoxFiltro->currentIndex() == 2 ) {
        strQuery = "SELECT * FROM libroPersona WHERE cedulaFk = " + lineEditFiltro->text();
        filtroTable(strQuery);
    }
    else if( comboBoxFiltro->currentIndex() == 3 ) {
        strQuery = "SELECT * FROM libroPersona WHERE fechaPrestamo = '" + lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else if( comboBoxFiltro->currentIndex() == 4 ) {
        strQuery = "SELECT * FROM libroPersona WHERE fechaEntrega = '" + lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else {
        strQuery = "SELECT * FROM libroPersona WHERE responsable = '" + lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }

}

void Prestamo::filtroTable(QString strQuery)
{
    rowCount = 0;

    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "Advertencia", "No existe el filtro realizado.");
        return;
    }
    else {

        tablePrestamo->setVisible(true);

        rowCount += 1;
        tablePrestamo->setRowCount(rowCount);
        rowCount = tablePrestamo->rowCount();

        if( rowCount < 6 )
            tablePrestamo->setGeometry(225,210,518,175);
        else
            tablePrestamo->setGeometry(212,210,534,173);

        for( int row = rowCount - 1; row < rowCount; row++ ) {

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(0).toString());
            tablePrestamo->setItem(row, 0, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(1).toString());
            tablePrestamo->setItem(row, 1, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(2).toString());
            tablePrestamo->setItem(row, 2, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(3).toString());
            tablePrestamo->setItem(row, 3, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(4).toString());
            tablePrestamo->setItem(row, 4, item);
        }

        while( query.next() ) {

            rowCount += 1;
            tablePrestamo->setRowCount(rowCount);
            rowCount = tablePrestamo->rowCount();

            if( rowCount < 6 )
                tablePrestamo->setGeometry(225,210,518,175);
            else
                tablePrestamo->setGeometry(212,210,534,173);

            for( int row = rowCount - 1; row < rowCount; row++ ) {

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(0).toString());
                tablePrestamo->setItem(row, 0, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(1).toString());
                tablePrestamo->setItem(row, 1, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(2).toString());
                tablePrestamo->setItem(row, 2, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(3).toString());
                tablePrestamo->setItem(row, 3, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(4).toString());
                tablePrestamo->setItem(row, 4, item);

            }
        }
    }

}

void Prestamo::prestamoWidget()
{
    lblCota->setVisible(true);
    lineEditCota->setVisible(true);
    lineEditCota->setText("");

    lblAutor->setVisible(true);
    lineEditAutor->setVisible(true);
    lineEditAutor->setText("");

    lblTitulo->setVisible(true);
    lineEditTitulo->setVisible(true);
    lineEditTitulo->setText("");

    lblTipoPrestamo->setVisible(true);
    comboBoxTipoPrestamo->removeItem(2);
    comboBoxTipoPrestamo->setCurrentIndex(0);
    comboBoxTipoPrestamo->setVisible(true);

    lblCedula->setVisible(true);
    lineEditCedula->setVisible(true);
    lineEditCedula->setText("");

    lblFechaP->setVisible(true);
    lineEditFechaP->setVisible(true);
    btnCalendar->setVisible(true);

    lblFechaE->setVisible(true);
    lineEditFechaE->setVisible(true);
    lineEditFechaE->setText("");

    lblResponsable->setVisible(true);
    comboBoxResponsable->setCurrentIndex(0);
    comboBoxResponsable->setVisible(true);

    btnRegistrar->setVisible(true);

}

void Prestamo::clearWidget()
{
    lblCota->setVisible(false);
    lineEditCota->setVisible(false);
    lineEditCota->setText("");

    lblAutor->setVisible(false);
    lineEditAutor->setVisible(false);
    lineEditAutor->setText("");

    lblTitulo->setVisible(false);
    lineEditTitulo->setVisible(false);
    lineEditTitulo->setText("");

    lblTipoPrestamo->setVisible(false);
    comboBoxTipoPrestamo->removeItem(2);
    comboBoxTipoPrestamo->setCurrentIndex(0);
    comboBoxTipoPrestamo->setVisible(false);

    lblCedula->setVisible(false);
    lineEditCedula->setVisible(false);
    lineEditCedula->setText("");

    lblFechaP->setVisible(false);
    lineEditFechaP->setVisible(false);
    btnCalendar->setVisible(false);

    lblFechaE->setVisible(false);
    lineEditFechaE->setVisible(false);
    lineEditFechaE->setText("");

    lblResponsable->setVisible(false);
    comboBoxResponsable->setCurrentIndex(0);
    comboBoxResponsable->setVisible(false);

    btnRegistrar->setVisible(false);

    lblFiltro->setVisible(false);
    comboBoxFiltro->setVisible(false);
    comboBoxFiltro->setCurrentIndex(0);
    lineEditFiltro->setVisible(false);
    lineEditFiltro->setText("");

    tablePrestamo->setVisible(false);
    rowCount = 0;

}

void Prestamo::distroyedCalendar()
{
    calendarWidget->close();
}

