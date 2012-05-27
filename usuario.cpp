#include "usuario.h"
#include "ui_Usuarios.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QValidator>

Usuarios::Usuarios(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Usuarios)
{

    ui->setupUi(this);

    inicializar();


}

void Usuarios::nuevoUser(){

    lbApellido->setVisible(true);
    lbApellido->setGeometry(QRect(QPoint(250,40),QSize(71,21)));
    lbApellido->setText("Apellido: ");


    lbCedula->setVisible(true);
    lbCedula->setGeometry(QRect(QPoint(50,90),QSize(56,21)));
    lbCedula->setText("Cedula: ");

    leCedula->setGeometry(QRect(QPoint(100,90),QSize(131,21)));

    lbNombre->setVisible(true);
    lbNombre->setGeometry(QRect(QPoint(50,40),QSize(71,21)));
    lbNombre->setText("Nombre: ");
    leNombre->setVisible(true);


    leApellido->setVisible(true);
    leCedula->setVisible(true);

    ui->label->setText("AGREGAR NUEVO USUARIO");


    btnAceptar->setVisible(true);
    disconnect(btnAceptar, SIGNAL(clicked()), 0, 0);
    btnAceptar->setGeometry(QRect(QPoint(170,180),QSize(75,23)));
    btnAceptar->setText("Aceptar");
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));

    btnCancelar->setVisible(true);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(cancelar()));

    rbEstu->setVisible(true);
    rbProf->setVisible(true);

    lbTipo->setText("Tipo: ");
    lbTipo->setGeometry(QRect(QPoint(250,90),QSize(71,21)));
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
    ui->label->setText("");

}

void Usuarios::editarUsuario(){


    ui->label->setText("EDITAR USUARIO");
    //this->close();

}

void Usuarios::eliminarUsuario(){

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    ui->label->setText("ELIMINAR USUARIO");


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


    ui->label->setText("BUSCAR USUARIO");

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

void Usuarios::inicializar(){

    lbNombre = new QLabel(ui->centralWidget);
    lbNombre->setGeometry(QRect(QPoint(40,40),QSize(51,21)));
    lbNombre->setVisible(false);

    leNombre = new QLineEdit(ui->centralWidget);
    leNombre->setGeometry(QRect(QPoint(100,40),QSize(131,20)));
    leNombre->setVisible(false);

    lbApellido = new QLabel(ui->centralWidget);
    lbApellido->setGeometry(QRect(QPoint(250,40),QSize(56,21)));
    lbApellido->setVisible(false);

    leApellido = new QLineEdit(ui->centralWidget);
    leApellido->setGeometry(QRect(QPoint(310,40),QSize(131,20)));
    leApellido->setVisible(false);

    lbCedula = new QLabel(ui->centralWidget);
    lbCedula->setGeometry(QRect(QPoint(50,90),QSize(51,21)));
    lbCedula->setVisible(false);

    leCedula = new QLineEdit(ui->centralWidget);
    leCedula->setGeometry(QRect(QPoint(100,90),QSize(131,20)));
    leCedula->setVisible(false);
    leCedula->setValidator(new QIntValidator(0,9999999,this));

    lbTipo = new QLabel(ui->centralWidget);
    lbTipo->setGeometry(QRect(QPoint(250,90),QSize(51,21)));
    lbTipo->setVisible(false);

    rbProf = new QRadioButton("Profesor",ui->centralWidget);
    rbProf->setGeometry(QRect(QPoint(310,90),QSize(71,17)));
    rbProf->setVisible(false);

    rbEstu = new QRadioButton("Estudiante",ui->centralWidget);
    rbEstu->setGeometry(QRect(QPoint(310,120),QSize(71,17)));
    rbEstu->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",ui->centralWidget);
    btnAceptar->setGeometry(QRect(QPoint(170,180),QSize(131,20)));
    btnAceptar->setVisible(false);

    btnCancelar = new QPushButton("Cancelar",ui->centralWidget);
    btnCancelar->setGeometry(QRect(QPoint(270,180),QSize(131,20)));
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
    delete ui;
}
