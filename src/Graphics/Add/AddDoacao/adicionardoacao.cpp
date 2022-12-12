#include "adicionardoacao.h"
#include "ui_adicionardoacao.h"

AdicionarDoacao::AdicionarDoacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarDoacao)
{
    ui->setupUi(this);
}

AdicionarDoacao::~AdicionarDoacao()
{
    delete ui;
}

void AdicionarDoacao::on_buttonReturn_2_clicked()
{
    this->close();
}


void AdicionarDoacao::on_buttonRegister_clicked()
{
    // validar cadastro e passar dados aqui
    this->close();
}

