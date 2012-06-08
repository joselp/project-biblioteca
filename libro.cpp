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
        sql.exec("INSERT INTO libros values('"+leCota->text()+"','"+leTitulo->text()+"','"+leAutor->text()
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


}

void Libro::btnEditar(){


        QSqlQuery query;
//        query.exec("select * from personas where cedula='"+cedula+"'");

//        if( query.next() ){

//            if((leNombre->text().isEmpty() || leApellido->text().isEmpty() || leCedula->text().isEmpty())){
//                QMessageBox::warning(this,"Atencion","No deje Campos vacios");

//            }
//            else{

//            query.exec("update personas set nombre='"+leNombre->text()+"', apellido='"+leApellido->text()+"',cedula='"+leCedula->text()+"' where cedula='"+cedula+"'");
//            QMessageBox::about(this,"Correcto","Usuario Actualizado");

//            limpiar();
//            }
//        }
}


void Libro::eliminarLibro()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

//    limpiar();

//    lbCedula->setText("Ingrese Cedula: ");
//    leCedula->move(460,130);
//    lbCedula->move(330,130);

//    btnAceptar->move(430,220);
//    btnAceptar->setText("Eliminar");
//    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEliminar()));

//    leCedula->show();
//    lbCedula->show();
//    btnAceptar->show();


}

void Libro::buscarLibro()
{



    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);


//    limpiar();

//    leNombre->setReadOnly(true);
//    leApellido->setReadOnly(true);

//    leCedula->move(450,130);
//    lbCedula->move(330,130);
//    lbCedula->setText("Ingrese Cedula: ");

//    btnAceptar->move(450,280);
//    btnAceptar->setText("Buscar");
//    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

//    lbNombre->move(280,190);
//    leNombre->move(350,190);

//    lbApellido->move(510,190);
//    leApellido->move(580,190);


//    lbTipo->move(300,220);



//    leCedula->show();
//    lbCedula->show();
//    btnAceptar->show();
//    lbApellido->show();
//    leApellido->show();
//    lbNombre->show();
//    leNombre->show();
//    lbTipo->show();

}

bool Libro::btnBuscar()
{

    QSqlQuery query;
//    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

//    if( query.next() ){

//        leNombre->setText(query.value(1).toString());
//        leApellido->setText(query.value(2).toString());
//        lbTipo->setText(query.value(3).toString());
//        btnAceptar->setEnabled(true);
//        cedula=leCedula->text();
//        return true;

//    }

//    else{

//        QMessageBox::warning(this,"ATENCION","El usuario no existe");
//        return false;
//    }
return true;
}

void Libro::btnEliminar()
{

    QSqlQuery query;

//    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

//    if( query.next() ){

//        query.exec("delete from personas where cedula='"+leCedula->text()+"'");

//        QMessageBox msg;
//        msg.setModal(true);
//        msg.setWindowTitle("Eliminar");
//        msg.setText("Usuario Eliminado");
//        msg.exec();
//    }

//    else{

//        QMessageBox::warning(this,"ATENCION","El usuario no existe");

//    }
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

    leCota->setVisible(false);
    leAutor->setVisible(false);
    leTitulo->setVisible(false);
    leMateria->setVisible(false);
    leEditorial->setVisible(false);
    leAnhoPublicacion->setVisible(false);
    leLugar->setVisible(false);
    leVolumen->setVisible(false);
    leEjemplar->setVisible(false);

    leCota->setText("");
    leAutor->setText("");
    leTitulo->setText("");
    leMateria->setText("");
    leEditorial->setText("");
    leAnhoPublicacion->setText("");
    leLugar->setText("");
    leVolumen->setText("");
    leEjemplar->setText("");

    comboEstado->setVisible(false);
    comboAdquisicion->setVisible(false);

    btnAceptar->setVisible(false);
    btnCancelar->setVisible(false);

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

