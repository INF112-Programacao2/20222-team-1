#include "cadastrardoador.h"
#include "ui_cadastrardoador.h"

CadastrarDoador::CadastrarDoador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastrarDoador)
{
    ui->setupUi(this);
}

CadastrarDoador::~CadastrarDoador()
{
    delete ui;
}

void CadastrarDoador::on_buttonAdd_clicked()
{

}

