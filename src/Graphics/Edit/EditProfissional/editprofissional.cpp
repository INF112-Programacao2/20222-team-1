#include "editprofissional.h"
#include "ui_editprofissional.h"

EditProfissional::EditProfissional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfissional)
{
    ui->setupUi(this);
}

EditProfissional::~EditProfissional()
{
    delete ui;
}

void EditProfissional::on_buttonReturn_clicked()
{
    this->close();
}


void EditProfissional::on_buttonAdd_clicked()
{
    //validar e cadastrar aqui
    this->close();
}

