#include "formdeletebook.h"
#include "ui_formdeletebook.h"

FormDeleteBook::FormDeleteBook(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::FormDeleteBook)
{
    ui->setupUi(this);
    init();
}

void FormDeleteBook::deleteBook(){

    QSqlQuery query;
    ui->leCota->setText(ui->leCota->text().toUpper());

    query.exec("select * from libros where cota='"+ui->leCota->text()+"'");

    if( query.next() ){

        query.exec("delete from libros where cota='"+ui->leCota->text()+"'");

        QMessageBox::information(this,"INFORMACION","Libro Eliminado");

    }

    else{

        QMessageBox::warning(this,"ADVERTENCIA","El libro no existe");

    }
    ui->leCota->setText("");


}

void FormDeleteBook::init(){

    ui->label->setFont(QFont("Baskerville Old Face",10,QFont::Bold));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(deleteBook()));
    ui->pushButton->setIcon(QIcon(":/images/bookdelete.png"));


}

FormDeleteBook::~FormDeleteBook()
{
    delete ui;
}
