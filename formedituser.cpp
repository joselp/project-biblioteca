#include "formedituser.h"
#include "ui_formedituser.h"

FormEditUser::FormEditUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEditUser)
{
    ui->setupUi(this);
    clear();
    init();
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(acept()));
    connect(ui->btnCancelar,SIGNAL(clicked()),this,SLOT(buscar()));
}

void FormEditUser::buscar(){


    QSqlQuery query;
    query.exec("select * from personas where cedula='"+ui->leCedula->text()+"'");

    if( query.next() ){

        ui->leNombre->setText(query.value(1).toString());
        ui->leApellido->setText(query.value(2).toString());
        ui->btnAceptar->setEnabled(true);
        cedula=ui->leCedula->text();

        if(query.value(3).toString()=="Profesor")
            ui->rbProf->setChecked(true);
        else
            ui->rbEstu->setChecked(true);


    }
    else
        QMessageBox::warning(this,"ADVERTENCIA","El usuario no existe");
}

void FormEditUser::acept(){

    QSqlQuery query;
    query.exec("select * from personas where cedula='"+cedula+"'");

    if(ui->rbEstu->isChecked())
        aux="Estudiante";
    else
        aux="Profesor";

    if( query.next() ){

        if((ui->leNombre->text().isEmpty() || ui->leApellido->text().isEmpty() || ui->leCedula->text().isEmpty())){
            QMessageBox::warning(this,"ADVERTENCIA","No deje Campos vacios");

        }
        else{

            query.exec("update personas set nombre='"+ui->leNombre->text()+"', apellido='"+ui->leApellido->text()+"',cedula='"+ui->leCedula->text()+"',tipo='"+aux+"' where cedula='"+cedula+"'");
            QMessageBox::information(this,"INFORMACION","Usuario Actualizado");
            clear();
        }
    }
}

void FormEditUser::clear(){

    ui->leCedula->setText("");
    ui->leApellido->setText("");
    ui->leCedula->setText("");
    ui->leNombre->setText("");

}

void FormEditUser::init(){

    ui->lbNombre->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->lbApellido->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->lbCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->leCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));
    ui->lbTipo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    ui->btnAceptar->setIcon(QIcon(":/images/aceptar.png"));

    ui->btnCancelar->setIcon(QIcon(":/images/usersearch.png"));
    ui->btnAceptar->setIcon(QIcon(":/images/useredit.png"));

}

FormEditUser::~FormEditUser()
{
    delete ui;
}
