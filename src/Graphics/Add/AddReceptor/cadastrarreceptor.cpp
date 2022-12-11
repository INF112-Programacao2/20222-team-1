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
