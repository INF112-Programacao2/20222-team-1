#include "registerprofissionalsaude.h"
#include "ui_registerprofissionalsaude.h"

RegisterProfissionalSaude::RegisterProfissionalSaude(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterProfissionalSaude)
{
    ui->setupUi(this);
}

RegisterProfissionalSaude::~RegisterProfissionalSaude()
{
    delete ui;
}

void RegisterProfissionalSaude::on_buttonReturn_clicked()
{
    this->close();
}


void RegisterProfissionalSaude::on_buttonRegistrar_clicked()
{   // validacao
    this.close();

}

