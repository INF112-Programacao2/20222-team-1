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
