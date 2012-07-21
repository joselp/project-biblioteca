#include "formhome.h"
#include "ui_formhome.h"

FormHome::FormHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome)
{
    ui->setupUi(this);
}

FormHome::~FormHome()
{
    delete ui;
}
