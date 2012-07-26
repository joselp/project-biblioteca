#include "formsearchprestamo.h"
#include "ui_formsearchprestamo.h"

FormSearchPrestamo::FormSearchPrestamo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSearchPrestamo)
{
    ui->setupUi(this);

    initGUI();
}

FormSearchPrestamo::~FormSearchPrestamo()
{
    delete ui;
}

void FormSearchPrestamo::initGUI()
{
    connect(ui->comboBoxFiltro, SIGNAL(currentIndexChanged(int)), this, SLOT(slotTipoFiltro(int)));
    ui->lineEditFiltro->setReadOnly(true);
    connect(ui->btnFiltrar, SIGNAL(clicked()), this, SLOT(slotFiltro()));

    tablePrestamo = new QTableWidget(this);
    tablePrestamo->setColumnCount(5);
    tablePrestamo->setGeometry(55,80,518,175);

    QStringList listHeader;
    listHeader << "Cota" << "Cédula" << "Fecha Préstamo" << "Fecha Entrega" <<"Responsable";
    int rowCount = tablePrestamo->rowCount();
    tablePrestamo->setHorizontalHeaderLabels(listHeader);

    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), tablePrestamo, SLOT(selectRow(int)));
    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), this, SLOT(slotRowSelected(int)));

    QString strQuery = "SELECT * FROM libroPersona";
    qDebug() << strQuery;

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No existe libros en prestamo.");

        ui->comboBoxFiltro->setEnabled(false);
        ui->btnFiltrar->setEnabled(false);
        tablePrestamo->setEnabled(false);

        return;
    }
    else {
        rowCount += 1;
        tablePrestamo->setRowCount(rowCount);
        rowCount = tablePrestamo->rowCount();

        if( rowCount < 6 )
            tablePrestamo->setGeometry(55,80,518,175);
        else
            tablePrestamo->setGeometry(42,80,534,173);

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
                tablePrestamo->setGeometry(55,80,518,175);
            else
                tablePrestamo->setGeometry(42,80,534,173);

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

void FormSearchPrestamo::slotTipoFiltro(int item)
{
    if( item  == 0 ){
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setToolTip("");
        ui->lineEditFiltro->setReadOnly(true);

    }
    else if( item == 1 ) {
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setToolTip("");
        ui->lineEditFiltro->setReadOnly(false);
        ui->lineEditFiltro->setValidator(new QRegExpValidator());
        connect(ui->lineEditFiltro, SIGNAL(textChanged(QString)), this, SLOT(slotUpperText(QString)));

    }
    else if( item == 2 ) {
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setToolTip("");
        ui->lineEditFiltro->setReadOnly(false);
        ui->lineEditFiltro->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));
    }
    else if( item == 3 ) {
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setReadOnly(false);
        ui->lineEditFiltro->setToolTip("El formato de fecha es: DD/MM/AAAA");

        QString expDia("([0-2]\\d|[3][0-1])/");
        QString expMes("([0]\\d|[1][0-2])/");
        QString expAnho("([0-9]{4})");
        QRegExp expFecha;
        expFecha.setPattern(expDia.append(expMes.append(expAnho)));
        ui->lineEditFiltro->setValidator(new QRegExpValidator(expFecha,this));

    }
    else if( item == 4 ) {
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setReadOnly(false);
        ui->lineEditFiltro->setToolTip("El formato de fecha es: DD/MM/AAAA");

        QString expDia("([0-2]\\d|[3][0-1])/");
        QString expMes("([0]\\d|[1][0-2])/");
        QString expAnho("([0-9]{4})");
        QRegExp expFecha;
        expFecha.setPattern(expDia.append(expMes.append(expAnho)));
        ui->lineEditFiltro->setValidator(new QRegExpValidator(expFecha,this));
    }
    else {
        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setToolTip("");
        ui->lineEditFiltro->setReadOnly(false);
        QRegExp expReg("(01|02)");
        ui->lineEditFiltro->setValidator(new QRegExpValidator(expReg,this));
        QStringList list;
        list << "01" << "02" ;
        ui->lineEditFiltro->setCompleter(new QCompleter(list));
    }
}

void FormSearchPrestamo::slotUpperText(QString str)
{
    ui->lineEditFiltro->setText(str.toUpper());
}

void FormSearchPrestamo::slotFiltro()
{
    if( (ui->lineEditFiltro->text().isEmpty()) && (ui->comboBoxFiltro->currentIndex() != 0) ) {
        QMessageBox::warning(this,"ADVERTENCIA","No debe dejar el campo vacio.");
        ui->lineEditFiltro->setFocus();
        return;
    }

    QString strQuery;

    if( ui->comboBoxFiltro->currentIndex() == 0 ) {
        strQuery = "SELECT * FROM libroPersona";
        filtroTable(strQuery);
    }
    else if( ui->comboBoxFiltro->currentIndex() == 1 ) {
        strQuery = "SELECT * FROM libroPersona WHERE cotaFk = '" + ui->lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else if( ui->comboBoxFiltro->currentIndex() == 2 ) {
        strQuery = "SELECT * FROM libroPersona WHERE cedulaFk = " + ui->lineEditFiltro->text();
        filtroTable(strQuery);
    }
    else if( ui->comboBoxFiltro->currentIndex() == 3 ) {
        strQuery = "SELECT * FROM libroPersona WHERE fechaPrestamo = '" + ui->lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else if( ui->comboBoxFiltro->currentIndex() == 4 ) {
        strQuery = "SELECT * FROM libroPersona WHERE fechaEntrega = '" + ui->lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
    else {
        strQuery = "SELECT * FROM libroPersona WHERE responsable = '" + ui->lineEditFiltro->text() + "'";
        filtroTable(strQuery);
    }
}

void FormSearchPrestamo::filtroTable(QString strQuery)
{
    int rowCount = 0;

    qDebug() << strQuery;

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No existe el filtro realizado.");

        ui->lineEditFiltro->setText("");
        ui->lineEditFiltro->setFocus();

        return;
    }
    else {

        rowCount += 1;
        tablePrestamo->setRowCount(rowCount);
        rowCount = tablePrestamo->rowCount();

        if( rowCount < 6 )
            tablePrestamo->setGeometry(55,80,518,175);
        else
            tablePrestamo->setGeometry(42,80,534,173);

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
                tablePrestamo->setGeometry(55,80,518,175);
            else
                tablePrestamo->setGeometry(42,80,534,173);

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

void FormSearchPrestamo::slotRowSelected(int row)
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
    query2.exec(strQuery2);

    dialogPrestamo = new DialogPrestamo;
    ptr=dialogPrestamo;

    if( query2.next() ) {

        dialogPrestamo->setNombre(query2.value(1).toString());
        dialogPrestamo->setApellido(query2.value(2).toString());
        dialogPrestamo->setCedula(query2.value(0).toString());
        dialogPrestamo->setTipoUser(query2.value(3).toString());

    }

    QString adquisicion;
    QString estado;

    QSqlQuery query;
    query.exec(strQuery);

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

void FormSearchPrestamo::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == 16777220 )
        slotFiltro();
}
