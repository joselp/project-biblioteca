#include "usuario.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QValidator>

Usuarios::Usuarios(QWidget *a){


    inicializar(a);


}

void Usuarios::nuevoUser(){

    lbApellido->setVisible(true);
    lbApellido->setGeometry(QRect(QPoint(480,140),QSize(71,21)));
    lbApellido->setText("Apellido: ");


    lbCedula->setVisible(true);
    lbCedula->setGeometry(QRect(QPoint(280,190),QSize(56,21)));
    lbCedula->setText("Cedula: ");

    leCedula->setGeometry(QRect(QPoint(330,190),QSize(131,21)));

    lbNombre->setVisible(true);
    lbNombre->setGeometry(QRect(QPoint(270,140),QSize(71,21)));
    lbNombre->setText("Nombre: ");
    leNombre->setVisible(true);


    leApellido->setVisible(true);
    leCedula->setVisible(true);


    btnAceptar->setVisible(true);
    disconnect(btnAceptar, SIGNAL(clicked()), 0, 0);
    btnAceptar->setGeometry(QRect(QPoint(400,280),QSize(75,23)));
    btnAceptar->setText("Aceptar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));

    btnCancelar->setVisible(true);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(cancelar()));

    rbEstu->setVisible(true);
    rbProf->setVisible(true);

    lbTipo->setText("Tipo: ");
    lbTipo->setGeometry(QRect(QPoint(480,190),QSize(71,21)));
    lbTipo->setVisible(true);

}

void Usuarios::aceptar(){

    QString aux;

    if(rbEstu->isChecked())
        aux="Estudiante";
    else
        aux="Profesor";

    if( ( leNombre->text().isEmpty() || leApellido->text().isEmpty() || leCedula->text().isEmpty()) || (!rbEstu->isChecked() && !rbProf->isChecked())){
        QMessageBox::warning(this,"Campos Vacios","Por favor inserte todos los campos");
    }

    else{
    QSqlQuery sql;
    sql.exec("INSERT INTO personas values('"+leCedula->text()+"','"+leNombre->text()+"','"+leApellido->text()+"','"+aux+"')");


    limpiar();

    }

}

void Usuarios::cancelar(){

    limpiar();

}

void Usuarios::editarUsuario(){



    //this->close();

}

void Usuarios::eliminarUsuario(){

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);


    limpiar();


    leCedula->setGeometry(QRect(QPoint(210,40),QSize(131,21)));
    lbCedula->setGeometry(QRect(QPoint(110,40),QSize(131,21)));

    btnAceptar->setGeometry(QRect(QPoint(230,80),QSize(75,23)));
    btnAceptar->setText("Eliminar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEliminar()));

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();


}

void Usuarios::buscarUsuario(){

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    leCedula->setGeometry(QRect(QPoint(210,40),QSize(131,21)));
    lbCedula->setGeometry(QRect(QPoint(110,40),QSize(131,21)));

    btnAceptar->setGeometry(QRect(QPoint(230,80),QSize(75,23)));
    btnAceptar->setText("Buscar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    lbNombre->setGeometry(QRect(QPoint(100,120),QSize(71,21)));
    lbApellido->setGeometry(QRect(QPoint(250,120),QSize(71,21)));
    lbCedula->setText("Ingrese Cedula: ");

    lbTipo->setGeometry(QRect(QPoint(100,140),QSize(71,21)));

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();
    lbApellido->show();
    lbNombre->show();
    lbTipo->show();

}

void Usuarios::btnBuscar(){

    QSqlQuery query;
    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    query.next();
    QString aux = query.value(0).toString();


    if( aux.size() !=0 ){

    lbNombre->setText(query.value(1).toString());
    lbApellido->setText(query.value(2).toString());
    lbTipo->setText(query.value(3).toString());

    }

    else{

        QMessageBox::critical(this,"ERROR","El usuario no existe");

    }

}

void Usuarios::btnEliminar(){

    QSqlQuery query;

    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    query.next();
    QString aux = query.value(0).toString();

    query.exec("delete from personas where cedula='"+leCedula->text()+"'");

    qDebug() << aux;

    if( aux.size() !=0 ){

        QMessageBox msg;
        msg.setModal(true);
        msg.setWindowTitle("Eliminar");
        msg.setText("Usuario Eliminado");
        msg.exec();
    }

    else{

        QMessageBox::critical(this,"ERROR","El usuario no existe");

    }
}

void Usuarios::inicializar(QWidget *a){


    lbNombre = new QLabel(a);
    lbNombre->setGeometry(QRect(QPoint(270,140),QSize(51,21)));
    lbNombre->setVisible(false);

    leNombre = new QLineEdit(a);
    leNombre->setGeometry(QRect(QPoint(330,140),QSize(131,20)));
    leNombre->setVisible(false);

    lbApellido = new QLabel(a);
    lbApellido->setGeometry(QRect(QPoint(480,140),QSize(56,21)));
    lbApellido->setVisible(false);

    leApellido = new QLineEdit(a);
    leApellido->setGeometry(QRect(QPoint(540,140),QSize(131,20)));
    leApellido->setVisible(false);

    lbCedula = new QLabel(a);
    lbCedula->setGeometry(QRect(QPoint(280,190),QSize(51,21)));
    lbCedula->setVisible(false);

    leCedula = new QLineEdit(a);
    leCedula->setGeometry(QRect(QPoint(330,190),QSize(131,20)));
    leCedula->setVisible(false);
    leCedula->setValidator(new QIntValidator(0,9999999,this));

    lbTipo = new QLabel(a);
    lbTipo->setGeometry(QRect(QPoint(480,190),QSize(51,21)));
    lbTipo->setVisible(false);

    rbProf = new QRadioButton("Profesor",a);
    rbProf->setGeometry(QRect(QPoint(540,190),QSize(71,17)));
    rbProf->setVisible(false);

    rbEstu = new QRadioButton("Estudiante",a);
    rbEstu->setGeometry(QRect(QPoint(540,220),QSize(71,17)));
    rbEstu->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",a);
    btnAceptar->setGeometry(QRect(QPoint(400,280),QSize(75,23)));
    btnAceptar->setVisible(false);

    btnCancelar = new QPushButton("Cancelar",a);
    btnCancelar->setGeometry(QRect(QPoint(500,280),QSize(75,23)));
    btnCancelar->setVisible(false);

}

void Usuarios::limpiar(){

    lbApellido->setVisible(false);
    lbCedula->setVisible(false);
    lbNombre->setVisible(false);
    leNombre->setVisible(false);
    leApellido->setVisible(false);
    leCedula->setVisible(false);
    btnAceptar->setVisible(false);
    btnCancelar->setVisible(false);
    rbEstu->setVisible(false);
    rbProf->setVisible(false);
    lbTipo->setVisible(false);
    leCedula->setText("");
    leApellido->setText("");
    leCedula->setText("");
    leNombre->setText("");

}



Usuarios::~Usuarios()
{
    delete us;
}
