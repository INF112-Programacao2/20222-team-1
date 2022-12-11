#include "registerinstituicao.h"
#include "ui_registerinstituicao.h"

RegisterInstituicao::RegisterInstituicao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterInstituicao)
{
    ui->setupUi(this);
}

RegisterInstituicao::~RegisterInstituicao()
{
    delete ui;
}

void RegisterInstituicao::on_buttonReturn_clicked()
{

}


void RegisterInstituicao::on_buttonRegister_clicked()
{

}

