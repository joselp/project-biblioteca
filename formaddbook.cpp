#include "formaddbook.h"
#include "ui_formaddbook.h"

FormAddBook::FormAddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAddBook)
{
    ui->setupUi(this);
    init();
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(slotAcept()));
}

void FormAddBook::slotAcept(){

    QString bueno,malo,regular,comprado,donado,canjeado;

    if(ui->comboEstado->currentText()=="Bueno"){
        bueno="X";
        regular="";
        malo="";
    }
    if(ui->comboEstado->currentText()=="Regular"){
        bueno="";
        regular="X";
        malo="";
    }
    if(ui->comboEstado->currentText()=="Malo"){
        bueno="";
        regular="";
        malo="X";
    }

    if(ui->comboAdquisicion->currentText()=="Comprado"){
        comprado="X";
        donado="";
        canjeado="";
    }
    if(ui->comboAdquisicion->currentText()=="Donado"){
        comprado="";
        donado="X";
        canjeado="";
    }
    if(ui->comboAdquisicion->currentText()=="Canjeado"){
        comprado="";
        donado="";
        canjeado="X";
    }

    if(  ui->leCota->text().isEmpty() || ui->leTitulo->text().isEmpty() || ui->leAutor->text().isEmpty() || ui->leMateria->text().isEmpty()){
        QMessageBox::warning(this,"Campos Vacios","Por favor inserte todos los obligatorios (*)");
    }

    else{
        QSqlQuery sql;

        sql.exec("select * from libros where cota='"+ui->leCota->text().toUpper()+"'");

        if( sql.next() ){
            QMessageBox::warning(this,"ADVERTENCIA","El Libro ya existe");
        }
        else{
        sql.exec("INSERT INTO libros values('"+ui->leCota->text().toUpper()+"','"+ui->leAutor->text()+"','"+ui->leTitulo->text()
                 +"','"+ui->leMateria->text()+"','"+ui->leEditorial->text()+"','"+ui->leAnhoPublicacion->text()
                 +"','"+ui->leLugar->text()+"','"+canjeado+"','"+donado+"','"+comprado+"','"+ui->leVolumen->text()
                 +"','1','"+bueno+"','"+regular+"','"+malo+"')");

        QMessageBox::information(this,"INFORMACION","Libro creado");
        clear();
        }
    }

}

void FormAddBook::init(){

    ui->lbCota->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbAutor->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbTitulo->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbMateria->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbEditorial->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbAnhoPublicacion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbLugar->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbAdquisicion->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->comboAdquisicion->addItem("");
    ui->comboAdquisicion->addItem("Comprado");
    ui->comboAdquisicion->addItem("Donado");
    ui->comboAdquisicion->addItem("Canjeado");

    ui->lbVolumen->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    ui->lbEstado->setFont(QFont("Baskerville Old Face",10,QFont::Bold));

    ui->comboEstado->addItem("");
    ui->comboEstado->addItem("Bueno");
    ui->comboEstado->addItem("Regular");
    ui->comboEstado->addItem("Malo");

    ui->btnAceptar->setIcon(QIcon(":/images/bookadd.png"));


}

void FormAddBook::keyPressEvent(QKeyEvent *event){

    if(event->key()== 16777220){
        slotAcept();
    }
}

void FormAddBook::clear(){

    ui->leCota->setText("");
    ui->leAutor->setText("");
    ui->leTitulo->setText("");
    ui->leMateria->setText("");
    ui->leEditorial->setText("");
    ui->leAnhoPublicacion->setText("");
    ui->leLugar->setText("");
    ui->leVolumen->setText("");
    ui->comboAdquisicion->setCurrentIndex(0);
    ui->comboEstado->setCurrentIndex(0);

}

FormAddBook::~FormAddBook()
{
    delete ui;
}
