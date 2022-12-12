#include "cadastrarreceptor.h"
#include "ui_cadastrarreceptor.h"

CadastrarReceptor::CadastrarReceptor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastrarReceptor)
{
    ui->setupUi(this);
}

CadastrarReceptor::~CadastrarReceptor()
{
    delete ui;
}

void CadastrarReceptor::on_buttonReturn_clicked()
{
    this->close();
}


void CadastrarReceptor::on_buttonAdd_clicked()
{
    // validar e cadastrar dados
    this->close();
}

