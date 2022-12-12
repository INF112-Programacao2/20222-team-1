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
    // vaidacao e cadastrar dados aqui
    this->close();
}


void CadastrarDoador::on_buttonReturn_clicked()
{
    this->close();
}

