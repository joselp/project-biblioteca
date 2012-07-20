#include "formsearchuser.h"
#include "ui_formsearchuser.h"

FormSearchUser::FormSearchUser(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::FormSearchUser)
{
    ui->setupUi(this);
    init();
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(acept()));
}

void FormSearchUser::acept(){


    QSqlQuery query;
    query.exec("select * from personas where cedula='"+ui->leCedula->text()+"'");

//    ui->lbTipo2->setText("");
//    ui->leApellido->setText("");
//    ui->leNombre->setText("");

    if( query.next() ){

        ui->leNombre->setText(query.value(1).toString());
        ui->leApellido->setText(query.value(2).toString());
        ui->lbTipo2->setText(query.value(3).toString());
        ui->btnAceptar->setEnabled(true);
        //ui->cedula=leCedula->text();

    }

    else{
        QMessageBox::warning(this,"ADVERTENCIA","El usuario no existe");
    }
}

void FormSearchUser::init(){

    ui->leApellido->setReadOnly(true);
    ui->leNombre->setReadOnly(true);

    ui->lbNombre->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->lbApellido->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->leCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));
    ui->lbTipo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->lbTipo2->setFont(QFont("Baskerville Old Face",12,QFont::Bold));

    ui->btnAceptar->setIcon(QIcon(":/images/usersearch.png"));

}

FormSearchUser::~FormSearchUser()
{
    delete ui;
}
