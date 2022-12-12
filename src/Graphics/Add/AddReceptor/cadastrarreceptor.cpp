#include "cadastrarreceptor.h"
#include "ui_cadastrarreceptor.h"

#include "../../../Banco/Banco.h"
#include "../../../Receptor/receptor.h"

#include <QString>
#include "../../AlertDialog/alertdialog.h"
#include <string>
#include <exception>

CadastrarReceptor::CadastrarReceptor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastrarReceptor)
{
    ui->setupUi(this);

    QString tipos[8] = {"A +","A -", "B +", "B -", "AB +", "AB -", "O +", "O -"};
    for(int i=0; i<8; i++) {
        ui->comboTipoSangue->addItem(tipos[i]);
    }

    ui->dateNascimento->setMaximumDate(QDate::currentDate());
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
    AlertDialog *dialog = new AlertDialog(this);

    // validar e cadastrar dados
    std::string nome = ui->inputNome->text().toStdString();
    std::string cpf = ui->inputCPF->text().toStdString();
    int tipo = ui->comboTipoSangue->currentIndex();

    int dia = ui->dateNascimento->date().day();
    int mes = ui->dateNascimento->date().day();
    int ano = ui->dateNascimento->date().year();

    Banco* i;
    try {
        if(ui->comboTipoSangue->currentIndex() == -1) throw std::invalid_argument("Selecione um tipo sanguínio!");
        if(i->isCpf(cpf)) throw std::invalid_argument("CPF inválido!");
        if(nome.size() < 2) throw std::invalid_argument("O nome deve ter pelo menos 2 caracteres.");
    } catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    ;
    i->setReceptor(new Receptor(nome, cpf, i->criaStructTm(dia, mes, ano), tipo));

    this->close();
}
