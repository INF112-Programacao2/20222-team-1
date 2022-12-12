#include "cadastrarreceptor.h"
#include "ui_cadastrarreceptor.h"

#include <string>
#include "../../../Receptor/receptor.h"

#include <QString>

CadastrarReceptor::CadastrarReceptor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastrarReceptor)
{
    ui->setupUi(this);

    QString tipos[8] = {"A +","A -", "B +", "B -", "AB +", "AB -", "O +", "O -"};
    for(int i=0; i<8; i++) {
        ui->comboTipoSangue->addItem(tipos[i]);
    }
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
    std::string nome = ui->inputNome->text().toStdString();
    std::string cpf = ui->inputCPF->text().toStdString();


    this->close();
}

