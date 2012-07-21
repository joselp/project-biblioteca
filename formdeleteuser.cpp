#include "formdeleteuser.h"
#include "ui_formdeleteuser.h"

FormDeleteUser::FormDeleteUser(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::FormDeleteUser)
{
    ui->setupUi(this);
    init();
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(acept()));
}

void FormDeleteUser::acept(){
    QSqlQuery query;

    query.exec("select * from personas where cedula='"+ui->leCedula->text()+"'");

    if( query.next() ){

        query.exec("delete from personas where cedula='"+ui->leCedula->text()+"'");

        QMessageBox::information(this,"INFORMACION","Usuario Eliminado");
        ui->leCedula->setText("");
    }

    else{

        QMessageBox::warning(this,"ADVERTENCIA","El usuario no existe");

    }
}

void FormDeleteUser::init(){

    ui->lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->btnAceptar->setIcon(QIcon(":/images/userdelete.png"));

}

void FormDeleteUser::keyPressEvent(QKeyEvent *event){

    if(event->key()== 16777220){
        acept();
    }
}

void FormDeleteUser::clear(){

    ui->leCedula->setText("");
}

FormDeleteUser::~FormDeleteUser()
{
    delete ui;
}
