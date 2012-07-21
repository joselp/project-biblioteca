#include "formadduser.h"
#include "ui_formadduser.h"

FormAddUser::FormAddUser(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::FormAddUser)
{

    ui->setupUi(this);
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(acept()));
    init();
    clear();
}

void FormAddUser::acept(){


    if(ui->rbEstu->isChecked())
        aux="Estudiante";
    else
        aux="Profesor";

    if( ( ui->leNombre->text().isEmpty() || ui->leApellido->text().isEmpty() || ui->leCedula->text().isEmpty()) || (!ui->rbEstu->isChecked() && !ui->rbProf->isChecked())){
        QMessageBox::warning(this,"ADVERTENCIA","Por favor inserte todos los campos");
    }

    else{

        QSqlQuery sql;
        sql.exec("select * from personas where cedula='"+ui->leCedula->text()+"'");

        if( sql.next() ){
            QMessageBox::warning(this,"ADVERTENCIA","El Usuario ya existe");
        }
        else{
            sql.exec("INSERT INTO personas values('"+ui->leCedula->text()+"','"+ui->leNombre->text()+"','"+ui->leApellido->text()+"','"+aux+"')");

            QMessageBox::information(this,"INFORMACION","Usuario Creado");
            clear();
        }
    }

}

void FormAddUser::init(){

    ui->lbNombre->setFont(QFont("Baskerville Old Face",12,QFont::Bold));

    ui->lbApellido->setFont(QFont("Baskerville Old Face",12,QFont::Bold));

    ui->lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));

    ui->leCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));

    ui->lbTipo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));

    ui->btnAceptar->setIcon(QIcon(":/images/aceptar.png"));
}

void FormAddUser::keyPressEvent(QKeyEvent *event){

    if(event->key()== 16777220){
        acept();
    }
}

void FormAddUser::clear(){

    ui->leApellido->setText("");
    ui->leCedula->setText("");
    ui->leNombre->setText("");

}

FormAddUser::~FormAddUser()
{
    delete ui;
}
