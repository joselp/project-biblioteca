#include "libro.h"

Libro::Libro()
{
}

void Libro::nuevoLibro()
{

    limpiar();
    mostrarNuevo();

    disconnect(btnAceptar, SIGNAL(clicked()), 0, 0);
    btnAceptar->setText("Aceptar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));

    disconnect(btnCancelar,SIGNAL(clicked()),0,0);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(cancelar()));

    bandera=false;
}

void Libro::aceptar()
{

    QString bueno,malo,regular,comprado,donado,canjeado;

    if(comboEstado->currentText()=="Bueno"){
        bueno="X";
        regular="";
        malo="";
    }
    if(comboEstado->currentText()=="regular"){
        bueno="";
        regular="X";
        malo="";
    }
    if(comboEstado->currentText()=="malo"){
        bueno="";
        regular="";
        malo="X";
    }

    if(comboAdquisicion->currentText()=="Comprado"){
        comprado="X";
        donado="";
        canjeado="";
    }
    if(comboAdquisicion->currentText()=="donado"){
        comprado="";
        donado="X";
        canjeado="";
    }
    if(comboAdquisicion->currentText()=="canjeado"){
        comprado="";
        donado="";
        canjeado="X";
    }

    if(  leCota->text().isEmpty() || leTitulo->text().isEmpty() || leAutor->text().isEmpty() || leEjemplar->text().isEmpty() ){
        QMessageBox::warning(this,"Campos Vacios","Por favor inserte todos los obligatorios (*)");
    }

    else{
        QSqlQuery sql;
        sql.exec("INSERT INTO libros values('"+leCota->text().toUpper()+"','"+leAutor->text()+"','"+leTitulo->text()
                 +"','"+leMateria->text()+"','"+leEditorial->text()+"','"+leAnhoPublicacion->text()
                 +"','"+leLugar->text()+"','"+canjeado+"','"+donado+"','"+comprado+"','"+leVolumen->text()
                 +"','"+leEjemplar->text()+"','"+bueno+"','"+regular+"','"+malo+"')");


        limpiar();

    }

}

void Libro::cancelar()
{

    limpiar();

}

void Libro::editarLibro()
{


    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);
    disconnect(btnCancelar,SIGNAL(clicked()),0,0);

    limpiar();

    mostrarNuevo();

    lbCota->setText("Cota:");
    lbBuscar->setVisible(true);
    leBuscar->setVisible(true);
    lbTipoBusqueda->setVisible(false);
    comboTipoBusqueda->setCurrentIndex(0);

    btnAceptar->setText("Buscar");
    btnAceptar->move(630,98);
    btnAceptar->setVisible(true);


    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    btnCancelar->setText("Editar");
    btnCancelar->move(380,390);
    btnCancelar->setEnabled(false);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(btnEditar()));

    bandera=true;

}

void Libro::btnEditar(){


        QSqlQuery query;
        query.exec("select * from libros where cota='"+cota.toUpper()+"'");

        qDebug()<<cota;

        if( query.next() ){

            if(  leCota->text().isEmpty() || leTitulo->text().isEmpty() || leAutor->text().isEmpty() || leEjemplar->text().isEmpty() ){
                QMessageBox::warning(this,"Campos Vacios","Por favor inserte todos los obligatorios (*)");
            }
            else{

                QString bueno,malo,regular,comprado,donado,canjeado;

                if(comboEstado->currentText()=="Bueno"){
                    bueno="X";
                    regular="";
                    malo="";
                }
                if(comboEstado->currentText()=="regular"){
                    bueno="";
                    regular="X";
                    malo="";
                }
                if(comboEstado->currentText()=="malo"){
                    bueno="";
                    regular="";
                    malo="X";
                }

                if(comboAdquisicion->currentText()=="Comprado"){
                    comprado="X";
                    donado="";
                    canjeado="";
                }
                if(comboAdquisicion->currentText()=="donado"){
                    comprado="";
                    donado="X";
                    canjeado="";
                }
                if(comboAdquisicion->currentText()=="canjeado"){
                    comprado="";
                    donado="";
                    canjeado="X";
                }

                query.exec("update libros set cota=\""+leCota->text().toUpper()+"\", autor=\""+leAutor->text()+"\", titulo=\""+leTitulo->text()
                       +"\", materia=\""+leMateria->text()+"\", editorial=\""+leEditorial->text()+"\", anhoPublicacion=\""+leAnhoPublicacion->text()
                       +"\", lugar=\""+leLugar->text()+"\", canjeado=\""+canjeado+"\", donado=\""+donado+"\", comprado=\""+comprado+"\", volumen=\""+leVolumen->text()
                       +"\", ejemplar=\""+leEjemplar->text()+"\", bueno=\""+bueno+"\", regular=\""+regular+"\", malo=\""+malo+"\" where cota=\""+cota.toUpper()+"\"");


                QMessageBox::about(this,"Correcto","Libro Actualizado");

            limpiar();
            }
        }
}

void Libro::buscarLibro()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbBuscar->setVisible(true);
    leBuscar->setVisible(true);
    lbTipoBusqueda->setVisible(true);
    comboTipoBusqueda->setVisible(true);

    btnAceptar->setText("Buscar");
    btnAceptar->move(630,98);
    btnAceptar->setVisible(true);

    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    bandera=false;
}

void Libro::btnBuscar()
{

    rowCount = 0;
    QSqlQuery query;
    leBuscar->setText(leBuscar->text());



    if(comboTipoBusqueda->currentText() == "Cota"){

        mostrarNuevo();
        btnCancelar->setVisible(false);
        tableBusqueda->setVisible(false);
        btnAceptar->move(630,98);

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
                btnCancelar->setVisible(true);
                btnCancelar->setEnabled(true);
                btnCancelar->move(380,390);
                btnCancelar->setText("Editar");
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

            QMessageBox::about(this,"Advertencia","Cota no Existe");
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


        query.exec("select * from libros where titulo like '"+leBuscar->text()+"%'");


        if( !query.next() ) {
            QMessageBox::warning(this, "Advertencia", "No existen libros con este titulo.");

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

        query.exec("select * from libros where autor like \""+leBuscar->text()+"%\"");

        if( !query.next() ) {
            QMessageBox::warning(this, "Advertencia", "No existen libros con este autor.");

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

        query.exec("select * from libros where materia like \""+leBuscar->text()+"%\"");

        if( !query.next() ) {
            QMessageBox::warning(this, "Advertencia", "No existen libros con este titulo.");

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

void Libro::eliminarLibro()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbCota->setText("Ingrese Cota: ");
    lbCota->move(360,180);
    leCota->move(450,180);

    btnAceptar->move(430,230);
    btnAceptar->setText("Eliminar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEliminar()));

    leCota->show();
    lbCota->show();
    btnAceptar->show();

    bandera=false;

}

void Libro::btnEliminar()
{

    QSqlQuery query;
    leCota->setText(leCota->text().toUpper());

    query.exec("select * from libros where cota='"+leCota->text()+"'");

    if( query.next() ){

        query.exec("delete from personas where cedula='"+leCota->text()+"'");

        QMessageBox msg;
        msg.setModal(true);
        msg.setWindowTitle("Eliminar");
        msg.setText("Usuario Eliminado");
        msg.exec();
    }

    else{

        QMessageBox::warning(this,"ATENCION","El libro no existe");

    }
}

void Libro::inicializar(QWidget *a)
{

    lbCota = new QLabel(a);
    lbCota->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbCota->setVisible(false);
    lbCota->setText("Cota: ");

    leCota = new QLineEdit(a);
    leCota->setGeometry(270,170,100,20);

    leCota->setVisible(false);

    lbAutor = new QLabel(a);
    lbAutor->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAutor->setVisible(false);
    lbAutor->setText("Autor: ");

    leAutor = new QLineEdit(a);
    leAutor->setGeometry(600,170,100,20);
    leAutor->setVisible(false);

    lbTitulo = new QLabel(a);
    lbTitulo->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbTitulo->setVisible(false);
    lbTitulo->setText("Titulo: ");

    leTitulo = new QLineEdit(a);
    leTitulo->setGeometry(660,170,100,20);
    leTitulo->setVisible(false);

    lbMateria = new QLabel(a);
    lbMateria->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbMateria->setVisible(false);
    lbMateria->setText("Materia: ");

    leMateria = new QLineEdit(a);
    leMateria->setGeometry(270,220,100,20);
    leMateria->setVisible(false);

    lbEditorial = new QLabel(a);
    lbEditorial->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEditorial->setVisible(false);
    lbEditorial->setText("Editorial: ");

    leEditorial = new QLineEdit(a);
    leEditorial->setGeometry(460,220,100,20);
    leEditorial->setVisible(false);

    lbAnhoPublicacion = new QLabel(a);
    lbAnhoPublicacion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAnhoPublicacion->setVisible(false);
    lbAnhoPublicacion->setText("Año Public.: ");

    leAnhoPublicacion = new QLineEdit(a);
    leAnhoPublicacion->setGeometry(690,220,100,20);
    leAnhoPublicacion->setVisible(false);

    lbLugar = new QLabel(a);
    lbLugar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbLugar->setVisible(false);
    lbLugar->setText("Lugar: ");

    leLugar = new QLineEdit(a);
    leLugar->setGeometry(270,270,100,20);
    leLugar->setVisible(false);

    lbAdquisicion = new QLabel(a);
    lbAdquisicion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAdquisicion->setVisible(false);
    lbAdquisicion->setText("Adquisición: ");

    comboAdquisicion = new QComboBox(a);
    comboAdquisicion->addItem("");
    comboAdquisicion->addItem("Comprado");
    comboAdquisicion->addItem("Donado");
    comboAdquisicion->addItem("Canjeado");
    comboAdquisicion->move(480,270);
    comboAdquisicion->setVisible(false);

    lbVolumen = new QLabel(a);
    lbVolumen->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbVolumen->setVisible(false);
    lbVolumen->setText("Volumen: ");

    leVolumen = new QLineEdit(a);
    leVolumen->setGeometry(670,270,90,20);
    leVolumen->setVisible(false);

    lbEjemplar = new QLabel(a);
    lbEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEjemplar->setVisible(false);
    lbEjemplar->setText("Ejemplares: ");

    leEjemplar = new QLineEdit(a);
    leEjemplar->setGeometry(290,320,90,20);
    leEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    leEjemplar->setVisible(false);


    lbEstado = new QLabel(a);
    lbEstado->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEstado->setVisible(false);
    lbEstado->setText("Estado: ");

    comboEstado = new QComboBox(a);
    comboEstado->addItem("");
    comboEstado->addItem("Bueno");
    comboEstado->addItem("Regular");
    comboEstado->addItem("Malo");
    comboEstado->move(480,320);
    comboEstado->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",a);
    btnAceptar->move(360,390);
    btnAceptar->setVisible(false);

    btnCancelar = new QPushButton("Cancelar",a);
    btnCancelar->move(490,390);
    btnCancelar->setVisible(false);

    lbBuscar = new QLabel(a);
    lbBuscar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbBuscar->move(190,100);
    lbBuscar->setText("Buscar:");
    lbBuscar->setVisible(false);

    leBuscar = new QLineEdit(a);
    leBuscar->setGeometry(240,100,270,20);
    leBuscar->setVisible(false);

    lbTipoBusqueda = new QLabel(a);
    lbTipoBusqueda->setFont(QFont("Baskerville Old Face",9,QFont::Bold));
    lbTipoBusqueda->move(515,80);
    lbTipoBusqueda->setText("Tipo de Busqueda");
    lbTipoBusqueda->setVisible(false);

    comboTipoBusqueda = new QComboBox(a);
    comboTipoBusqueda->addItem("Cota");
    comboTipoBusqueda->addItem("Autor");
    comboTipoBusqueda->addItem("Titulo");
    comboTipoBusqueda->addItem("Materia");
    comboTipoBusqueda->move(535,100);
    comboTipoBusqueda->setVisible(false);

    tableBusqueda = new QTableWidget(a);
    tableBusqueda->setGeometry(170,200,621,321);
    tableBusqueda->setColumnCount(15);
    QStringList listHeader;
    listHeader << "Cota" << "Autor" << "Titulo" << "Materia" << "Editorial" << "Año Public." << "Lugar"
                << "Canjeado" << "Donado" << "Comprado" << "Volumen" << "Ejemplar" << "Bueno" << "Malo" << "Regular";
    tableBusqueda->setHorizontalHeaderLabels(listHeader);
    tableBusqueda->setVisible(false);

    bandera=false;

}

void Libro::mostrarNuevo(){

    lbCota->move(200,170);
    lbCota->setVisible(true);

    leCota->move(270,170);
    leCota->setVisible(true);

    lbAutor->move(400,170);
    lbAutor->setVisible(true);

    leAutor->move(460,170);
    leAutor->setVisible(true);

    lbTitulo->move(600,170);
    lbTitulo->setVisible(true);

    leTitulo->move(660,170);
    leTitulo->setVisible(true);

    lbMateria->move(200,220);
    lbMateria->setVisible(true);

    leMateria->move(270,220);
    leMateria->setVisible(true);

    lbEditorial->move(400,220);
    lbEditorial->setVisible(true);

    leEditorial->move(460,220);
    leEditorial->setVisible(true);

    lbAnhoPublicacion->move(600,220);
    lbAnhoPublicacion->setVisible(true);

    leAnhoPublicacion->move(690,220);
    leAnhoPublicacion->setVisible(true);

    lbLugar->move(200,270);
    lbLugar->setVisible(true);

    leLugar->move(270,270);
    leLugar->setVisible(true);

    lbAdquisicion->move(400,270);
    lbAdquisicion->setVisible(true);

    comboAdquisicion->setVisible(true);

    lbVolumen->move(600,270);
    lbVolumen->setVisible(true);

    leVolumen->move(670,270);
    leVolumen->setVisible(true);

    lbEjemplar->move(200,320);
    lbEjemplar->setVisible(true);

    leEjemplar->move(290,320);
    leEjemplar->setVisible(true);

    lbEstado->move(400,320);
    lbEstado->setVisible(true);

    comboEstado->setVisible(true);

    btnAceptar->move(360,390);
    btnAceptar->setVisible(true);

    btnCancelar->move(490,390);
    btnCancelar->setText("Cancelar");
    btnCancelar->setEnabled(true);
    btnCancelar->setVisible(true);


}

void Libro::limpiar()
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
    btnCancelar->setVisible(false);

    tableBusqueda->setVisible(false);

}

void Libro::removeAll(){

    delete lbCota;
    delete lbAutor;
    delete lbTitulo;
    delete lbMateria;
    delete lbEditorial;
    delete lbAnhoPublicacion;
    delete lbLugar;
    delete lbAdquisicion;
    delete lbVolumen;
    delete lbEjemplar;
    delete lbEstado;

    delete leCota;
    delete leAutor;
    delete leTitulo;
    delete leMateria;
    delete leEditorial;
    delete leAnhoPublicacion;
    delete leLugar;
    delete leVolumen;
    delete leEjemplar;

    delete comboEstado;
    delete comboAdquisicion;

    delete btnAceptar;
    delete btnCancelar;

}

Libro::~Libro()
{

}

