#include "usuario.h"

Usuarios::Usuarios()
{

}

void Usuarios::nuevoUser()
{
    limpiar();

    lbApellido->setVisible(true);
    lbApellido->move(490,140);
    lbApellido->setText("Apellido: ");

    lbCedula->setVisible(true);
    lbCedula->move(270,190);
    lbCedula->setText("Cedula: ");

    leCedula->move(330,190);

    lbNombre->setVisible(true);
    lbNombre->move(260,140);
    lbNombre->setText("Nombre: ");

    leNombre->setVisible(true);
    leNombre->move(330,140);

    leApellido->setVisible(true);
    leApellido->move(560,140);

    leCedula->setVisible(true);

    btnAceptar->setVisible(true);
    disconnect(btnAceptar, SIGNAL(clicked()), 0, 0);
    btnAceptar->move(400,280);
    btnAceptar->setText("Aceptar");
    btnAceptar->setIcon(QIcon(":/images/aceptar.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));

    btnCancelar->setVisible(true);
    btnCancelar->setText("Cancelar");
    btnCancelar->setIcon(QIcon(":/images/cancel.png"));
    btnCancelar->setIconSize(QSize(15,15));
    disconnect(btnCancelar,SIGNAL(clicked()),0,0);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(cancelar()));
    btnCancelar->move(500,280);

    rbEstu->setVisible(true);
    rbProf->setVisible(true);

    lbTipo->setText("Tipo: ");
    lbTipo->move(490,190);
    lbTipo->setVisible(true);

}

void Usuarios::aceptar()
{

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

void Usuarios::cancelar()
{

    limpiar();

}

void Usuarios::editarUsuario()
{


    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);
    disconnect(btnCancelar,SIGNAL(clicked()),0,0);

    limpiar();

    leCedula->move(450,130);
    lbCedula->move(330,130);
    lbCedula->setText("Ingrese Cedula: ");

    btnCancelar->move(610,128);
    btnCancelar->setText("Buscar");
    btnCancelar->setIcon(QIcon(":/images/ver.png"));
    btnCancelar->setIconSize(QSize(15,15));
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    btnAceptar->move(450,280);
    btnAceptar->setText("Editar");
    btnAceptar->setIconSize(QSize(0,0));
    btnAceptar->setEnabled(false);
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEditar()));

    lbNombre->move(280,190);
    leNombre->move(350,190);

    lbApellido->move(510,190);
    leApellido->move(580,190);

    lbTipo->move(300,220);

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();
    btnCancelar->show();
    lbApellido->show();
    leApellido->show();
    lbNombre->show();
    leNombre->show();
    lbTipo->show();

}

void Usuarios::btnEditar(){


        QSqlQuery query;
        query.exec("select * from personas where cedula='"+cedula+"'");

        if( query.next() ){

            if((leNombre->text().isEmpty() || leApellido->text().isEmpty() || leCedula->text().isEmpty())){
                QMessageBox::warning(this,"Atencion","No deje Campos vacios");

            }
            else{

            query.exec("update personas set nombre='"+leNombre->text()+"', apellido='"+leApellido->text()+"',cedula='"+leCedula->text()+"' where cedula='"+cedula+"'");
            QMessageBox::about(this,"Correcto","Usuario Actualizado");

            limpiar();
            }
        }
}


void Usuarios::eliminarUsuario()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbCedula->setText("Ingrese Cedula: ");
    leCedula->move(460,130);
    lbCedula->move(330,130);

    btnAceptar->move(430,220);
    btnAceptar->setText("Eliminar");
    btnAceptar->setIcon(QIcon(":/images/cancel.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEliminar()));

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();


}

void Usuarios::buscarUsuario()
{



    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);


    limpiar();

    leNombre->setReadOnly(true);
    leApellido->setReadOnly(true);

    leCedula->move(450,130);
    lbCedula->move(330,130);
    lbCedula->setText("Ingrese Cedula: ");

    btnAceptar->move(450,280);
    btnAceptar->setText("Buscar");
    btnAceptar->setIcon(QIcon(":/images/ver.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    lbNombre->move(280,190);
    leNombre->move(350,190);

    lbApellido->move(510,190);
    leApellido->move(580,190);


    lbTipo->move(300,220);



    leCedula->show();
    lbCedula->show();
    btnAceptar->show();
    lbApellido->show();
    leApellido->show();
    lbNombre->show();
    leNombre->show();
    lbTipo->show();

}

bool Usuarios::btnBuscar()
{

    QSqlQuery query;
    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    if( query.next() ){

        leNombre->setText(query.value(1).toString());
        leApellido->setText(query.value(2).toString());
        lbTipo->setText(query.value(3).toString());
        btnAceptar->setEnabled(true);
        cedula=leCedula->text();
        return true;

    }

    else{

        QMessageBox::warning(this,"ATENCION","El usuario no existe");
        return false;
    }

}

void Usuarios::btnEliminar()
{

    QSqlQuery query;

    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    if( query.next() ){

        query.exec("delete from personas where cedula='"+leCedula->text()+"'");

        QMessageBox msg;
        msg.setModal(true);
        msg.setWindowTitle("Eliminar");
        msg.setText("Usuario Eliminado");
        msg.exec();
    }

    else{

        QMessageBox::warning(this,"ATENCION","El usuario no existe");

    }
}

void Usuarios::inicializar(QWidget *a)
{

    lbNombre = new QLabel(a);
    lbNombre->move(260,140);
    lbNombre->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbNombre->setVisible(false);
    lbNombre->setText("Nombre: ");

    leNombre = new QLineEdit(a);
    leNombre->move(330,140);
    leNombre->setVisible(false);

    lbApellido = new QLabel(a);
    lbApellido->move(480,140);
    lbApellido->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbApellido->setVisible(false);
    lbApellido->setText("Apellido: ");

    leApellido = new QLineEdit(a);
    leApellido->move(550,140);
    leApellido->setVisible(false);

    lbCedula = new QLabel(a);
    lbCedula->move(280,190);
    lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbCedula->setVisible(false);
    lbCedula->setText("Cedula: ");

    leCedula = new QLineEdit(a);
    leCedula->move(330,190);
    leCedula->setVisible(false);
    leCedula->setValidator(new QIntValidator(0,9999999,this));

    lbTipo = new QLabel(a);
    lbTipo->move(480,190);
    lbTipo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbTipo->setVisible(false);

    rbProf = new QRadioButton("Profesor",a);
    rbProf->move(540,190);
    rbProf->setVisible(false);

    rbEstu = new QRadioButton("Estudiante",a);
    rbEstu->move(540,220);
    rbEstu->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",a);
    btnAceptar->move(400,280);
    btnAceptar->setVisible(false);

    btnCancelar = new QPushButton("Cancelar",a);
    btnCancelar->move(500,280);
    btnCancelar->setVisible(false);

}

void Usuarios::limpiar()
{

    lbApellido->setVisible(false);
    lbCedula->setVisible(false);
    lbNombre->setVisible(false);
    leNombre->setVisible(false);
    leApellido->setVisible(false);
    leCedula->setVisible(false);
    leCedula->setEnabled(true);
    btnAceptar->setVisible(false);
    btnAceptar->setEnabled(true);
    btnCancelar->setVisible(false);
    rbEstu->setVisible(false);
    rbProf->setVisible(false);
    lbTipo->setVisible(false);
    lbTipo->setText("Tipo: ");
    leCedula->setText("");
    leApellido->setText("");
    leCedula->setText("");
    leNombre->setText("");
    leNombre->setReadOnly(false);
    leApellido->setReadOnly(false);
    //btnAceptar->setIconSize(QSize(0,0));

}

void Usuarios::removeall(){

    delete btnAceptar;
    delete btnCancelar;
    delete lbNombre;
    delete lbApellido;
    delete lbCedula;
    delete lbTipo;
    delete rbProf;
    delete rbEstu;
    delete leNombre;
    delete leApellido;
    delete leCedula;

}

Usuarios::~Usuarios()
{


}
