#include "usuario.h"

Usuarios::Usuarios()
{

}

void Usuarios::nuevoUser()
{
    limpiar();
    mostrarNuevo();

}

void Usuarios::aceptar()
{

    if(rbEstu->isChecked())
        aux="Estudiante";
    else
        aux="Profesor";

    if( ( leNombre->text().isEmpty() || leApellido->text().isEmpty() || leCedula->text().isEmpty()) || (!rbEstu->isChecked() && !rbProf->isChecked())){
        QMessageBox::warning(this,"ADVERTENCIA","Por favor inserte todos los campos");
    }

    else{

        QSqlQuery sql;
        sql.exec("select * from personas where cedula='"+leCedula->text()+"'");

        if( sql.next() ){
            QMessageBox::warning(this,"ADVERTENCIA","El Usuario ya existe");
        }
        else{
            sql.exec("INSERT INTO personas values('"+leCedula->text()+"','"+leNombre->text()+"','"+leApellido->text()+"','"+aux+"')");

            QMessageBox::information(this,"INFORMACION","Usuario Creado");
            //limpiar();
            mostrarNuevo();
        }
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

    leCedula->move(450,180);
    lbCedula->move(330,180);
    lbCedula->setText("Ingrese Cedula: ");

    btnCancelar->move(610,178);
    btnCancelar->setText("Buscar");
    btnCancelar->setIcon(QIcon(":/images/ver.png"));
    btnCancelar->setIconSize(QSize(15,15));
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    btnAceptar->move(450,330);
    btnAceptar->setText("Editar");
    btnAceptar->setIcon(QIcon(":/images/useredit.png"));
    btnAceptar->setIconSize(QSize(0,0));
    btnAceptar->setEnabled(false);
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEditar()));

    lbNombre->move(280,240);
    leNombre->move(350,240);

    lbApellido->move(510,240);
    leApellido->move(580,240);

    lbTipo->move(300,270);

    rbProf->move(300,290);
    rbEstu->move(300,310);

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();
    btnCancelar->show();
    lbApellido->show();
    leApellido->show();
    lbNombre->show();
    leNombre->show();
    lbTipo->show();
    rbEstu->show();
    rbProf->show();

}

void Usuarios::btnEditar(){

    QSqlQuery query;
    query.exec("select * from personas where cedula='"+cedula+"'");

    if(rbEstu->isChecked())
        aux="Estudiante";
    else
        aux="Profesor";

    if( query.next() ){

        if((leNombre->text().isEmpty() || leApellido->text().isEmpty() || leCedula->text().isEmpty())){
            QMessageBox::warning(this,"ADVERTENCIA","No deje Campos vacios");

        }
        else{

            query.exec("update personas set nombre='"+leNombre->text()+"', apellido='"+leApellido->text()+"',cedula='"+leCedula->text()+"',tipo='"+aux+"' where cedula='"+cedula+"'");
            QMessageBox::information(this,"INFORMACION","Usuario Actualizado");

            leCedula->setText("");
            leApellido->setText("");
            leCedula->setText("");
            leNombre->setText("");
        }
    }
}


void Usuarios::eliminarUsuario()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbCedula->setText("Ingrese Cedula: ");
    leCedula->move(460,180);
    lbCedula->move(330,180);

    btnAceptar->move(430,270);
    btnAceptar->setText("Eliminar");
    btnAceptar->setIcon(QIcon(":/images/cancel.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnEliminar()));

    leCedula->show();
    lbCedula->show();
    btnAceptar->show();

}

void Usuarios::btnEliminar()
{

    QSqlQuery query;

    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    if( query.next() ){

        query.exec("delete from personas where cedula='"+leCedula->text()+"'");

        QMessageBox::information(this,"INFORMACION","Usuario Eliminado");
        leCedula->setText("");
    }

    else{

        QMessageBox::warning(this,"ADVERTENCIA","El usuario no existe");
        leCedula->setText("");

    }

}

void Usuarios::buscarUsuario()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    leNombre->setReadOnly(true);
    leApellido->setReadOnly(true);

    leCedula->move(450,180);
    lbCedula->move(330,180);
    lbCedula->setText("Ingrese Cedula: ");

    btnAceptar->move(450,320);
    btnAceptar->setText("Buscar");
    btnAceptar->setIcon(QIcon(":/images/ver.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

    lbNombre->move(280,240);
    leNombre->move(350,240);

    lbApellido->move(510,240);
    leApellido->move(580,240);

    lbTipo->move(300,270);

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

    lbTipo2->move(350,270);

    QSqlQuery query;
    query.exec("select * from personas where cedula='"+leCedula->text()+"'");

    lbTipo2->setText("");
    leApellido->setText("");
    leNombre->setText("");

    if( query.next() ){

        leNombre->setText(query.value(1).toString());
        leApellido->setText(query.value(2).toString());
        lbTipo2->setText(query.value(3).toString());
        btnAceptar->setEnabled(true);
        cedula=leCedula->text();
        lbTipo2->show();

        if(lbTipo2->text()=="Profesor")
            rbProf->setChecked(true);
        else
            rbEstu->setChecked(true);
        return true;

    }

    else{

        QMessageBox::warning(this,"ADVERTENCIA","El usuario no existe");
        return false;
    }

}

void Usuarios::inicializar(QWidget *a)
{

    lbNombre = new QLabel(a);
    lbNombre->move(260,180);
    lbNombre->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbNombre->setVisible(false);
    lbNombre->setText("Nombre: ");

    leNombre = new QLineEdit(a);
    leNombre->move(330,180);
    leNombre->setVisible(false);

    lbApellido = new QLabel(a);
    lbApellido->move(480,180);
    lbApellido->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbApellido->setVisible(false);
    lbApellido->setText("Apellido: ");

    leApellido = new QLineEdit(a);
    leApellido->move(550,230);
    leApellido->setVisible(false);

    lbCedula = new QLabel(a);
    lbCedula->move(280,180);
    lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbCedula->setVisible(false);
    lbCedula->setText("Cedula: ");

    leCedula = new QLineEdit(a);
    leCedula->move(330,230);
    leCedula->setVisible(false);
    leCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));

    lbTipo = new QLabel(a);
    lbTipo->move(480,230);
    lbTipo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbTipo->setVisible(false);

    lbTipo2 = new QLabel(a);
    lbTipo2->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lbTipo2->setVisible(false);
    lbTipo2->setGeometry(QRect(QPoint(350,270),QSize(90,18)));

    rbProf = new QRadioButton("Profesor",a);
    rbProf->move(540,230);
    rbProf->setVisible(false);

    rbEstu = new QRadioButton("Estudiante",a);
    rbEstu->move(540,260);
    rbEstu->setVisible(false);

    btnAceptar = new QPushButton("Aceptar",a);
    btnAceptar->move(400,320);
    btnAceptar->setVisible(false);

    btnCancelar = new QPushButton("Cancelar",a);
    btnCancelar->move(500,320);
    btnCancelar->setVisible(false);

}

void Usuarios::mostrarNuevo(){

    lbApellido->setVisible(true);
    lbApellido->move(490,180);
    lbApellido->setText("Apellido: ");

    lbCedula->setVisible(true);
    lbCedula->move(270,230);
    lbCedula->setText("Cedula: ");

    leCedula->move(330,230);

    lbNombre->setVisible(true);
    lbNombre->move(260,180);
    lbNombre->setText("Nombre: ");

    leNombre->setVisible(true);
    leNombre->move(330,180);
    leNombre->setText("");

    leApellido->setVisible(true);
    leApellido->move(560,180);
    leApellido->setText("");

    leCedula->setVisible(true);
    leCedula->setText("");

    btnAceptar->setVisible(true);
    disconnect(btnAceptar, SIGNAL(clicked()), 0, 0);
    btnAceptar->move(450,320);
    btnAceptar->setText("Aceptar");
    btnAceptar->setIcon(QIcon(":/images/aceptar.png"));
    btnAceptar->setIconSize(QSize(15,15));
    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));

    rbEstu->setVisible(true);
    rbEstu->move(540,260);

    rbProf->move(540,230);
    rbProf->setVisible(true);

    lbTipo->setText("Tipo: ");
    lbTipo->move(490,230);
    lbTipo->setVisible(true);

}

void Usuarios::limpiar()
{

    lbApellido->setVisible(false);
    lbCedula->setVisible(false);
    lbNombre->setVisible(false);
    lbTipo2->setVisible(false);
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
    rbEstu->setChecked(false);
    rbEstu->setChecked(false);

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

