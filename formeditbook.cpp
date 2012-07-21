#include "formeditbook.h"
#include "ui_formeditbook.h"

FormEditBook::FormEditBook(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::FormEditBook)
{
    ui->setupUi(this);
    inicializar();
    buscarLibro();
}


void FormEditBook::buscarLibro()
{

    disconnect(btnAceptar, SIGNAL(clicked()),0, 0);

    limpiar();

    lbBuscar->setVisible(true);
    leBuscar->setVisible(true);

    btnAceptar->setText("Buscar");
    btnAceptar->setIcon(QIcon(":/images/booksearch.png"));
    btnAceptar->move(510,12);
    btnAceptar->setVisible(true);

    connect(btnAceptar,SIGNAL(clicked()),this,SLOT(btnBuscar()));

}

void FormEditBook::btnBuscar()
{

    QSqlQuery query;
    leBuscar->setText(leBuscar->text());
    mostrarEditar();
    btnCancelar->setVisible(true);

    query.exec("select * from libros where cota= '"+leBuscar->text().toUpper()+"'");

    if(query.next()){


        btnCancelar->setVisible(true);
        btnCancelar->setEnabled(true);
        btnCancelar->setText("Editar");

        cota=leBuscar->text();

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

void FormEditBook::btnEditar(){


        QSqlQuery query;
        query.exec("select * from libros where cota='"+cota.toUpper()+"'");

        if( query.next() ){

            if(  leCota->text().isEmpty() || leTitulo->text().isEmpty() || leAutor->text().isEmpty()){
                QMessageBox::warning(this,"ADVERTENCIA","Por favor inserte todos los obligatorios (*)");
            }
            else{

                QString bueno,malo,regular,comprado,donado,canjeado;

                if(comboEstado->currentText()=="Bueno"){
                    bueno="X";
                    regular="";
                    malo="";
                }
                if(comboEstado->currentText()=="Regular"){
                    bueno="";
                    regular="X";
                    malo="";
                }
                if(comboEstado->currentText()=="Malo"){
                    bueno="";
                    regular="";
                    malo="X";
                }

                if(comboAdquisicion->currentText()=="Comprado"){
                    comprado="X";
                    donado="";
                    canjeado="";
                }
                if(comboAdquisicion->currentText()=="Donado"){
                    comprado="";
                    donado="X";
                    canjeado="";
                }
                if(comboAdquisicion->currentText()=="Canjeado"){
                    comprado="";
                    donado="";
                    canjeado="X";
                }

                query.exec("update libros set cota=\""+leCota->text().toUpper()+"\", autor=\""+leAutor->text()+"\", titulo=\""+leTitulo->text()
                       +"\", materia=\""+leMateria->text()+"\", editorial=\""+leEditorial->text()+"\", anhoPublicacion=\""+leAnhoPublicacion->text()
                       +"\", lugar=\""+leLugar->text()+"\", canjeado=\""+canjeado+"\", donado=\""+donado+"\", comprado=\""+comprado+"\", volumen=\""+leVolumen->text()
                       +"\", ejemplar='1', bueno=\""+bueno+"\", regular=\""+regular+"\", malo=\""+malo+"\" where cota=\""+cota.toUpper()+"\"");


                QMessageBox::information(this,"INFORMACION","Libro Actualizado");

                leCota->setText("");
                leAutor->setText("");
                leTitulo->setText("");
                leMateria->setText("");
                leEditorial->setText("");
                leAnhoPublicacion->setText("");
                leLugar->setText("");
                leVolumen->setText("");
                leEjemplar->setText("");
                comboAdquisicion->setCurrentIndex(0);
                comboEstado->setCurrentIndex(0);
                leBuscar->setText("");
                btnCancelar->setEnabled(false);
            }
        }
}

void FormEditBook::inicializar()
{

    lbCota = new QLabel(this);
    lbCota->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbCota->setText("Cota: ");

    leCota = new QLineEdit(this);
    leCota->setGeometry(10,10,100,20);

    lbAutor = new QLabel(this);
    lbAutor->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAutor->setText("Autor: ");

    leAutor = new QLineEdit(this);
    leAutor->setGeometry(10,10,100,20);

    lbTitulo = new QLabel(this);
    lbTitulo->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbTitulo->setText("Titulo: ");

    leTitulo = new QLineEdit(this);
    leTitulo->setGeometry(10,10,100,20);

    lbMateria = new QLabel(this);
    lbMateria->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbMateria->setText("Materia: ");

    leMateria = new QLineEdit(this);
    leMateria->setGeometry(270,220,100,20);

    lbEditorial = new QLabel(this);
    lbEditorial->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEditorial->setText("Editorial: ");

    leEditorial = new QLineEdit(this);
    leEditorial->setGeometry(460,220,100,20);

    lbAnhoPublicacion = new QLabel(this);
    lbAnhoPublicacion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAnhoPublicacion->setText("Año Public.: ");

    leAnhoPublicacion = new QLineEdit(this);
    leAnhoPublicacion->setGeometry(690,220,70,20);

    lbLugar = new QLabel(this);
    lbLugar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbLugar->setText("Lugar: ");

    leLugar = new QLineEdit(this);
    leLugar->setGeometry(270,270,100,20);

    lbAdquisicion = new QLabel(this);
    lbAdquisicion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbAdquisicion->setText("Adquisición: ");

    comboAdquisicion = new QComboBox(this);
    comboAdquisicion->addItem("");
    comboAdquisicion->addItem("Comprado");
    comboAdquisicion->addItem("Donado");
    comboAdquisicion->addItem("Canjeado");
    comboAdquisicion->setGeometry(480,270,80,20);

    lbVolumen = new QLabel(this);
    lbVolumen->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbVolumen->setText("Tomo: ");

    leVolumen = new QLineEdit(this);
    leVolumen->setGeometry(670,270,90,20);

    lbEjemplar = new QLabel(this);
    lbEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEjemplar->setText("Ejemplares: ");

    leEjemplar = new QLineEdit(this);
    leEjemplar->setGeometry(290,320,80,20);
    leEjemplar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));

    lbEstado = new QLabel(this);
    lbEstado->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbEstado->setText("Estado: ");

    comboEstado = new QComboBox(this);
    comboEstado->addItem("");
    comboEstado->addItem("Bueno");
    comboEstado->addItem("Regular");
    comboEstado->addItem("Malo");
    comboEstado->setGeometry(480,320,80,20);

    btnAceptar = new QPushButton("Aceptar",this);
    btnAceptar->move(180,90);

    lbBuscar = new QLabel(this);
    lbBuscar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    lbBuscar->move(60,15);
    lbBuscar->setText("Buscar:");

    leBuscar = new QLineEdit(this);
    leBuscar->setGeometry(110,15,270,20);

    btnCancelar = new QPushButton("Editar",this);
    connect(btnCancelar,SIGNAL(clicked()),this,SLOT(btnEditar()));

}

void FormEditBook::mostrarEditar(){

    lbBuscar->setVisible(true);
    leBuscar->setVisible(true);

    lbCota->setText("Cota: ");
    lbCota->move(50,70);
    lbCota->setVisible(true);

    leCota->move(120,70);
    leCota->setVisible(true);

    lbAutor->setText("Autor: ");
    lbAutor->move(250,70);
    lbAutor->setVisible(true);

    leAutor->move(320,70);
    leAutor->setVisible(true);

    lbTitulo->setText("Titulo: ");
    lbTitulo->move(450,70);
    lbTitulo->setVisible(true);

    leTitulo->move(510,70);
    leTitulo->setVisible(true);

    lbMateria->setText("Materia: ");
    lbMateria->move(50,120);
    lbMateria->setVisible(true);

    leMateria->move(120,120);
    leMateria->setVisible(true);

    lbEditorial->move(250,120);
    lbEditorial->setVisible(true);

    leEditorial->move(320,120);
    leEditorial->setVisible(true);

    lbAnhoPublicacion->move(450,120);
    lbAnhoPublicacion->setVisible(true);

    leAnhoPublicacion->move(540,120);
    leAnhoPublicacion->setVisible(true);

    lbLugar->move(50,170);
    lbLugar->setVisible(true);

    leLugar->move(120,170);
    leLugar->setVisible(true);

    lbAdquisicion->move(250,170);
    lbAdquisicion->setVisible(true);

    comboAdquisicion->move(340,170);
    comboAdquisicion->setCurrentIndex(0);
    comboAdquisicion->setVisible(true);

    lbVolumen->setText("Tomo: ");
    lbVolumen->move(450,170);
    lbVolumen->setVisible(true);

    leVolumen->move(520,170);
    leVolumen->setVisible(true);

    lbEstado->move(50,215);
    lbEstado->setVisible(true);

    comboEstado->move(140,215);
    comboEstado->setCurrentIndex(0);
    comboEstado->setVisible(true);

    btnCancelar->move(250,270);
    btnCancelar->setText("Editar");
    btnCancelar->setVisible(true);
    btnCancelar->setEnabled(false);
    btnCancelar->setIcon(QIcon(":/images/bookedit.png"));

}

void FormEditBook::limpiar()
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

    btnAceptar->setVisible(false);
    btnCancelar->setVisible(false);


}

FormEditBook::~FormEditBook()
{
    delete ui;
}
