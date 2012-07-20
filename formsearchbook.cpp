#include "formsearchbook.h"
#include "ui_formsearchbook.h"

FormSearchBook::FormSearchBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSearchBook)
{
    ui->setupUi(this);
    inicializar();
    buscarLibro();

}

void FormSearchBook::buscarLibro()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbBuscar->setVisible(true);
    leBuscar->setVisible(true);
    lbTipoBusqueda->setVisible(true);
    comboTipoBusqueda->setVisible(true);

    btnAceptar->setText("Buscar");
    btnAceptar->setIcon(QIcon(":/images/ver.png"));
    btnAceptar->move(510,12);
    btnAceptar->setVisible(true);

    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    bandera=false;
}

void FormSearchBook::btnBuscar()
{

    rowCount = 0;
    QSqlQuery query;
    leBuscar->setText(leBuscar->text());

    mostrarEditar();
    //btnCancelar->setVisible(true);
    tableBusqueda->setVisible(false);

    if(comboTipoBusqueda->currentText() == "Cota"){

        query.exec("select * from libros where cota= '"+leBuscar->text().toUpper()+"'");

        if(query.next()){

            comboAdquisicion->setEditable(false);
            leCota->setReadOnly(true);
            leAutor->setReadOnly(true);
            leTitulo->setReadOnly(true);
            leMateria->setReadOnly(true);
            leEditorial->setReadOnly(true);
            leAnhoPublicacion->setReadOnly(true);
            leLugar->setReadOnly(true);
            leVolumen->setReadOnly(true);
            leEjemplar->setReadOnly(true);

            if (bandera==true){

                leCota->setReadOnly(false);
                leAutor->setReadOnly(false);
                leTitulo->setReadOnly(false);
                leMateria->setReadOnly(false);
                leEditorial->setReadOnly(false);
                leAnhoPublicacion->setReadOnly(false);
                leLugar->setReadOnly(false);
                leVolumen->setReadOnly(false);
                leEjemplar->setReadOnly(false);
                cota=leBuscar->text();

            }

            leCota->setText(query.value(0).toString());
            leAutor->setText(query.value(1).toString());
            leTitulo->setText(query.value(2).toString());
            leMateria->setText(query.value(3).toString());
            leEditorial->setText(query.value(4).toString());
            leAnhoPublicacion->setText(query.value(5).toString());
            leLugar->setText(query.value(6).toString());
            leVolumen->setText(query.value(10).toString());
            leEjemplar->setText(query.value(11).toString());

            if(query.value(7).toString()=="X")
                comboAdquisicion->setCurrentIndex(3);
            if(query.value(8).toString()=="X")
                comboAdquisicion->setCurrentIndex(2);
            if(query.value(9).toString()=="X")
                comboAdquisicion->setCurrentIndex(1);

            if(query.value(12).toString()=="X")
                comboEstado->setCurrentIndex(1);
            if(query.value(13).toString()=="X")
                comboEstado->setCurrentIndex(2);
            if(query.value(14).toString()=="X")
                comboEstado->setCurrentIndex(3);

        }

        else{

            QMessageBox::warning(this,"ADVERTENCIA","Cota no Existe");
            leCota->setText("");
            leAutor->setText("");
            leTitulo->setText("");
            leMateria->setText("");
            leEditorial->setText("");
            leAnhoPublicacion->setText("");
            leLugar->setText("");
            leVolumen->setText("");
            leEjemplar->setText("");
        }

    }


    if(comboTipoBusqueda->currentText() == "Titulo"){
        tableBusqueda->setVisible(true);
        lbCota->hide();
        leCota->hide();
        lbAutor->hide();
        leAutor->hide();
        lbTitulo->hide();
        leTitulo->hide();


        query.exec("select * from libros where titulo like \"%"+leBuscar->text()+"%\"");


        if( !query.next() ) {
            QMessageBox::warning(this, "ADVERTENCIA", "No existen libros con este titulo.");
            tableBusqueda->clearContents();

        }

        else{

                tableBusqueda->setVisible(true);

                rowCount += 1;
                tableBusqueda->setRowCount(rowCount);
                rowCount = tableBusqueda->rowCount();



                for( int row = rowCount - 1; row < rowCount; row++ ) {

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(0).toString());
                    tableBusqueda->setItem(row, 0, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(1).toString());
                    tableBusqueda->setItem(row, 1, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(2).toString());
                    tableBusqueda->setItem(row, 2, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(3).toString());
                    tableBusqueda->setItem(row, 3, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(4).toString());
                    tableBusqueda->setItem(row, 4, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(5).toString());
                    tableBusqueda->setItem(row, 5, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(6).toString());
                    tableBusqueda->setItem(row, 6, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(7).toString());
                    tableBusqueda->setItem(row, 7, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(8).toString());
                    tableBusqueda->setItem(row, 8, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(9).toString());
                    tableBusqueda->setItem(row, 9, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(10).toString());
                    tableBusqueda->setItem(row, 10, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(11).toString());
                    tableBusqueda->setItem(row, 11, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(12).toString());
                    tableBusqueda->setItem(row, 12, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(13).toString());
                    tableBusqueda->setItem(row, 13, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(14).toString());
                    tableBusqueda->setItem(row, 14, item);

                }

                while( query.next() ) {

                    rowCount += 1;
                    tableBusqueda->setRowCount(rowCount);
                    rowCount = tableBusqueda->rowCount();

                    for( int row = rowCount - 1; row < rowCount; row++ ) {

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(0).toString());
                        tableBusqueda->setItem(row, 0, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(1).toString());
                        tableBusqueda->setItem(row, 1, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(2).toString());
                        tableBusqueda->setItem(row, 2, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(3).toString());
                        tableBusqueda->setItem(row, 3, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(4).toString());
                        tableBusqueda->setItem(row, 4, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(5).toString());
                        tableBusqueda->setItem(row, 5, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(6).toString());
                        tableBusqueda->setItem(row, 6, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(7).toString());
                        tableBusqueda->setItem(row, 7, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(8).toString());
                        tableBusqueda->setItem(row, 8, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(9).toString());
                        tableBusqueda->setItem(row, 9, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(10).toString());
                        tableBusqueda->setItem(row, 10, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(11).toString());
                        tableBusqueda->setItem(row, 11, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(12).toString());
                        tableBusqueda->setItem(row, 12, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(13).toString());
                        tableBusqueda->setItem(row, 13, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(14).toString());
                        tableBusqueda->setItem(row, 14, item);

                    }
                }
        }
    }

    if(comboTipoBusqueda->currentText() == "Autor"){

        tableBusqueda->setVisible(true);
        lbCota->hide();
        leCota->hide();
        lbAutor->hide();
        leAutor->hide();
        lbTitulo->hide();
        leTitulo->hide();

        query.exec("select * from libros where autor like \"%"+leBuscar->text()+"%\"");

        if( !query.next() ) {
            QMessageBox::warning(this, "ADVERTENCIA", "No existen libros con este autor.");
            tableBusqueda->clearContents();

        }

        else{

                tableBusqueda->setVisible(true);

                rowCount += 1;
                tableBusqueda->setRowCount(rowCount);
                rowCount = tableBusqueda->rowCount();



                for( int row = rowCount - 1; row < rowCount; row++ ) {

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(0).toString());
                    tableBusqueda->setItem(row, 0, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(1).toString());
                    tableBusqueda->setItem(row, 1, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(2).toString());
                    tableBusqueda->setItem(row, 2, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(3).toString());
                    tableBusqueda->setItem(row, 3, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(4).toString());
                    tableBusqueda->setItem(row, 4, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(5).toString());
                    tableBusqueda->setItem(row, 5, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(6).toString());
                    tableBusqueda->setItem(row, 6, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(7).toString());
                    tableBusqueda->setItem(row, 7, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(8).toString());
                    tableBusqueda->setItem(row, 8, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(9).toString());
                    tableBusqueda->setItem(row, 9, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(10).toString());
                    tableBusqueda->setItem(row, 10, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(11).toString());
                    tableBusqueda->setItem(row, 11, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(12).toString());
                    tableBusqueda->setItem(row, 12, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(13).toString());
                    tableBusqueda->setItem(row, 13, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(14).toString());
                    tableBusqueda->setItem(row, 14, item);

                }

                while( query.next() ) {

                    rowCount += 1;
                    tableBusqueda->setRowCount(rowCount);
                    rowCount = tableBusqueda->rowCount();

                    for( int row = rowCount - 1; row < rowCount; row++ ) {

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(0).toString());
                        tableBusqueda->setItem(row, 0, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(1).toString());
                        tableBusqueda->setItem(row, 1, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(2).toString());
                        tableBusqueda->setItem(row, 2, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(3).toString());
                        tableBusqueda->setItem(row, 3, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(4).toString());
                        tableBusqueda->setItem(row, 4, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(5).toString());
                        tableBusqueda->setItem(row, 5, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(6).toString());
                        tableBusqueda->setItem(row, 6, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(7).toString());
                        tableBusqueda->setItem(row, 7, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(8).toString());
                        tableBusqueda->setItem(row, 8, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(9).toString());
                        tableBusqueda->setItem(row, 9, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(10).toString());
                        tableBusqueda->setItem(row, 10, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(11).toString());
                        tableBusqueda->setItem(row, 11, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(12).toString());
                        tableBusqueda->setItem(row, 12, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(13).toString());
                        tableBusqueda->setItem(row, 13, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(14).toString());
                        tableBusqueda->setItem(row, 14, item);

                    }
                }
        }
    }


    if(comboTipoBusqueda->currentText() == "Materia"){

        tableBusqueda->setVisible(true);
        lbCota->hide();
        leCota->hide();
        lbAutor->hide();
        leAutor->hide();
        lbTitulo->hide();
        leTitulo->hide();

        query.exec("select * from libros where materia like \"%"+leBuscar->text()+"%\"");

        if( !query.next() ) {
            QMessageBox::warning(this, "ADVERTENCIA", "No existen libros con este titulo.");
            tableBusqueda->clearContents();

        }

        else{

                tableBusqueda->setVisible(true);

                rowCount += 1;
                tableBusqueda->setRowCount(rowCount);
                rowCount = tableBusqueda->rowCount();



                for( int row = rowCount - 1; row < rowCount; row++ ) {

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(0).toString());
                    tableBusqueda->setItem(row, 0, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(1).toString());
                    tableBusqueda->setItem(row, 1, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(2).toString());
                    tableBusqueda->setItem(row, 2, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(3).toString());
                    tableBusqueda->setItem(row, 3, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(4).toString());
                    tableBusqueda->setItem(row, 4, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(5).toString());
                    tableBusqueda->setItem(row, 5, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(6).toString());
                    tableBusqueda->setItem(row, 6, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(7).toString());
                    tableBusqueda->setItem(row, 7, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(8).toString());
                    tableBusqueda->setItem(row, 8, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(9).toString());
                    tableBusqueda->setItem(row, 9, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(10).toString());
                    tableBusqueda->setItem(row, 10, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(11).toString());
                    tableBusqueda->setItem(row, 11, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(12).toString());
                    tableBusqueda->setItem(row, 12, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(13).toString());
                    tableBusqueda->setItem(row, 13, item);

                    item = new QTableWidgetItem;
                    item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                    item->setText(query.value(14).toString());
                    tableBusqueda->setItem(row, 14, item);

                }

                while( query.next() ) {

                    rowCount += 1;
                    tableBusqueda->setRowCount(rowCount);
                    rowCount = tableBusqueda->rowCount();

                    for( int row = rowCount - 1; row < rowCount; row++ ) {

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(0).toString());
                        tableBusqueda->setItem(row, 0, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(1).toString());
                        tableBusqueda->setItem(row, 1, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(2).toString());
                        tableBusqueda->setItem(row, 2, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(3).toString());
                        tableBusqueda->setItem(row, 3, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(4).toString());
                        tableBusqueda->setItem(row, 4, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(5).toString());
                        tableBusqueda->setItem(row, 5, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(6).toString());
                        tableBusqueda->setItem(row, 6, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(7).toString());
                        tableBusqueda->setItem(row, 7, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(8).toString());
                        tableBusqueda->setItem(row, 8, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(9).toString());
                        tableBusqueda->setItem(row, 9, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(10).toString());
                        tableBusqueda->setItem(row, 10, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(11).toString());
                        tableBusqueda->setItem(row, 11, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(12).toString());
                        tableBusqueda->setItem(row, 12, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(13).toString());
                        tableBusqueda->setItem(row, 13, item);

                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                        item->setText(query.value(14).toString());
                        tableBusqueda->setItem(row, 14, item);

                    }
                }
        }
    }

}

void FormSearchBook::inicializar()
{

    lbCota = new QLabel(this);
    lbCota->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbCota->setVisible(false);
    lbCota->setText("Cota: ");

    leCota = new QLineEdit(this);
    leCota->setGeometry(10,10,100,20);

    leCota->setVisible(false);

    lbAutor = new QLabel(this);
    lbAutor->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAutor->setVisible(false);
    lbAutor->setText("Autor: ");

    leAutor = new QLineEdit(this);
    leAutor->setGeometry(10,10,100,20);
    leAutor->setVisible(false);

    lbTitulo = new QLabel(this);
    lbTitulo->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbTitulo->setVisible(false);
    lbTitulo->setText("Titulo: ");

    leTitulo = new QLineEdit(this);
    leTitulo->setGeometry(10,10,100,20);
    leTitulo->setVisible(false);

    lbMateria = new QLabel(this);
    lbMateria->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbMateria->setVisible(false);
    lbMateria->setText("Materia: ");

    leMateria = new QLineEdit(this);
    leMateria->setGeometry(270,220,100,20);
    leMateria->setVisible(false);

    lbEditorial = new QLabel(this);
    lbEditorial->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEditorial->setVisible(false);
    lbEditorial->setText("Editorial: ");

    leEditorial = new QLineEdit(this);
    leEditorial->setGeometry(460,220,100,20);
    leEditorial->setVisible(false);

    lbAnhoPublicacion = new QLabel(this);
    lbAnhoPublicacion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAnhoPublicacion->setVisible(false);
    lbAnhoPublicacion->setText("Año Public.: ");

    leAnhoPublicacion = new QLineEdit(this);
    leAnhoPublicacion->setGeometry(690,220,70,20);
    leAnhoPublicacion->setVisible(false);

    lbLugar = new QLabel(this);
    lbLugar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbLugar->setVisible(false);
    lbLugar->setText("Lugar: ");

    leLugar = new QLineEdit(this);
    leLugar->setGeometry(270,270,100,20);
    leLugar->setVisible(false);

    lbAdquisicion = new QLabel(this);
    lbAdquisicion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAdquisicion->setVisible(false);
    lbAdquisicion->setText("Adquisición: ");

    comboAdquisicion = new QComboBox(this);
    comboAdquisicion->addItem("");
    comboAdquisicion->addItem("Comprado");
    comboAdquisicion->addItem("Donado");
    comboAdquisicion->addItem("Canjeado");
    comboAdquisicion->setGeometry(480,270,80,20);
    comboAdquisicion->setVisible(false);

    lbVolumen = new QLabel(this);
    lbVolumen->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbVolumen->setVisible(false);
    lbVolumen->setText("Tomo: ");

    leVolumen = new QLineEdit(this);
    leVolumen->setGeometry(670,270,90,20);
    leVolumen->setVisible(false);

    lbEjemplar = new QLabel(this);
    lbEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEjemplar->setVisible(false);
    lbEjemplar->setText("Ejemplares: ");

    leEjemplar = new QLineEdit(this);
    leEjemplar->setGeometry(290,320,80,20);
    leEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    leEjemplar->setVisible(false);


    lbEstado = new QLabel(this);
    lbEstado->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEstado->setVisible(false);
    lbEstado->setText("Estado: ");

    comboEstado = new QComboBox(this);
    comboEstado->addItem("");
    comboEstado->addItem("Bueno");
    comboEstado->addItem("Regular");
    comboEstado->addItem("Malo");
    comboEstado->setGeometry(480,320,80,20);
    comboEstado->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",this);
    btnAceptar->move(180,90);
    btnAceptar->setVisible(false);

    lbBuscar = new QLabel(this);
    lbBuscar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbBuscar->move(60,15);
    lbBuscar->setText("Buscar:");
    lbBuscar->setVisible(false);

    leBuscar = new QLineEdit(this);
    leBuscar->setGeometry(110,15,270,20);
    leBuscar->setVisible(false);

    lbTipoBusqueda = new QLabel(this);
    lbTipoBusqueda->setFont(QFont("Baskerville Old Face",9,QFont::Bold));
    lbTipoBusqueda->move(390,0);
    lbTipoBusqueda->setText("Tipo de Busqueda");
    lbTipoBusqueda->setVisible(false);

    comboTipoBusqueda = new QComboBox(this);
    comboTipoBusqueda->addItem("Cota");
    comboTipoBusqueda->addItem("Autor");
    comboTipoBusqueda->addItem("Titulo");
    comboTipoBusqueda->addItem("Materia");
    comboTipoBusqueda->move(412,15);
    comboTipoBusqueda->setVisible(false);

    tableBusqueda = new QTableWidget(this);
    tableBusqueda->setGeometry(10,70,621,321);
    tableBusqueda->setColumnCount(15);
    QStringList listHeader;
    listHeader << "Cota" << "Autor" << "Titulo" << "Materia" << "Editorial" << "Año Public." << "Lugar"
                << "Canjeado" << "Donado" << "Comprado" << "Volumen" << "Ejemplar" << "Bueno" << "Malo" << "Regular";
    tableBusqueda->setHorizontalHeaderLabels(listHeader);
    tableBusqueda->setVisible(false);

    bandera=false;

}

void FormSearchBook::mostrarEditar(){

    lbBuscar->setVisible(true);

    leBuscar->setVisible(true);

    lbTipoBusqueda->setVisible(true);

    lbCota->setText("Cota: ");
    lbCota->move(50,60);
    lbCota->setVisible(true);

    leCota->move(120,60);
    leCota->setVisible(true);

    lbAutor->setText("Autor: ");
    lbAutor->move(250,60);
    lbAutor->setVisible(true);

    leAutor->move(320,60);
    leAutor->setVisible(true);

    lbTitulo->setText("Titulo: ");
    lbTitulo->move(450,60);
    lbTitulo->setVisible(true);

    leTitulo->move(510,60);
    leTitulo->setVisible(true);

    lbMateria->setText("Materia: ");
    lbMateria->move(50,110);
    lbMateria->setVisible(true);

    leMateria->move(120,110);
    leMateria->setVisible(true);

    lbEditorial->move(250,110);
    lbEditorial->setVisible(true);

    leEditorial->move(320,110);
    leEditorial->setVisible(true);

    lbAnhoPublicacion->move(450,110);
    lbAnhoPublicacion->setVisible(true);

    leAnhoPublicacion->move(540,110);
    leAnhoPublicacion->setVisible(true);

    lbLugar->move(50,160);
    lbLugar->setVisible(true);

    leLugar->move(120,160);
    leLugar->setVisible(true);

    lbAdquisicion->move(250,160);
    lbAdquisicion->setVisible(true);

    comboAdquisicion->move(340,160);
    comboAdquisicion->setCurrentIndex(0);
    comboAdquisicion->setVisible(true);

    lbVolumen->setText("Tomo: ");
    lbVolumen->move(450,160);
    lbVolumen->setVisible(true);

    leVolumen->move(520,160);
    leVolumen->setVisible(true);

    lbEstado->move(50,205);
    lbEstado->setVisible(true);

    comboEstado->move(140,205);
    comboEstado->setCurrentIndex(0);
    comboEstado->setVisible(true);

}

void FormSearchBook::limpiar()
{

    lbCota->setVisible(false);
    lbAutor->setVisible(false);
    lbTitulo->setVisible(false);
    lbMateria->setVisible(false);
    lbEditorial->setVisible(false);
    lbAnhoPublicacion->setVisible(false);
    lbLugar->setVisible(false);
    lbAdquisicion->setVisible(false);
    lbVolumen->setVisible(false);
    lbEjemplar->setVisible(false);
    lbEstado->setVisible(false);
    lbBuscar->setVisible(false);
    lbTipoBusqueda->setVisible(false);

    leCota->setVisible(false);
    leAutor->setVisible(false);
    leTitulo->setVisible(false);
    leMateria->setVisible(false);
    leEditorial->setVisible(false);
    leAnhoPublicacion->setVisible(false);
    leLugar->setVisible(false);
    leVolumen->setVisible(false);
    leEjemplar->setVisible(false);
    leBuscar->setVisible(false);

    leCota->setText("");
    leAutor->setText("");
    leTitulo->setText("");
    leMateria->setText("");
    leEditorial->setText("");
    leAnhoPublicacion->setText("");
    leLugar->setText("");
    leVolumen->setText("");
    leEjemplar->setText("");
    leBuscar->setText("");

    comboEstado->setVisible(false);
    comboAdquisicion->setVisible(false);
    comboTipoBusqueda->setVisible(false);

    btnAceptar->setVisible(false);
    tableBusqueda->setVisible(false);

}

FormSearchBook::~FormSearchBook()
{
    delete ui;
}
