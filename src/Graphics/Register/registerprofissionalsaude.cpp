#include "registerprofissionalsaude.h"
#include "ui_registerprofissionalsaude.h"

#include <QString>
#include "../AlertDialog/alertdialog.h"
#include "../../ProfissionalSaude/profissionalSaude.h"
#include "../../Banco/Banco.h"
#include <string>
#include <exception>

RegisterProfissionalSaude::RegisterProfissionalSaude(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterProfissionalSaude)
{
    ui->setupUi(this);

    ui->inputDataNascimento->setMaximumDate(QDate::currentDate());

    QString cargo[2] = {"Medicx", "Enfermeirx"};
    ui->inputCargo->addItem(cargo[0]);
    ui->inputCargo->addItem(cargo[1]);

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
{
    AlertDialog *dialog = new AlertDialog(this);

    // validar e cadastrar dados
    std::string nome = ui->inputNomeCompleto->text().toStdString();
    std::string cpf = ui->inputCpf->text().toStdString();
    std::string senha = ui->inputSenha->text().toStdString();
    int cargo = ui->inputCargo->currentIndex();

    int dia = ui->inputDataNascimento->date().day();
    int mes = ui->inputDataNascimento->date().day();
    int ano = ui->inputDataNascimento->date().year();

    Banco* i;
    try {
        if(!i->isCpf(cpf)) throw std::invalid_argument("CPF inválido!");
        if(nome.size() < 2) throw std::invalid_argument("O nome deve ter pelo menos 2 caracteres.");
    } catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    i->setProfissional(new ProfissionalSaude(nome, cpf, i->criaStructTm(dia, mes, ano), senha, ((cargo) ? Cargo::MEDICX : Cargo::ENFERMEIRX), Banco::_iuser->get_id()));

    this->close();

}

