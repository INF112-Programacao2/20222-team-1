#include "cadastrardoador.h"
#include "ui_cadastrardoador.h"

#include "../../AlertDialog/alertdialog.h"
#include "../../../Banco/Banco.h"
#include "../../Dashboard/dashboard.h"

#import <ctime>
#include <string>
#include <QIntValidator>

CadastrarDoador::CadastrarDoador(Doador doador, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::CadastrarDoador)
{
    ui->setupUi(this);
}

CadastrarDoador::CadastrarDoador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadastrarDoador)
{
    ui->setupUi(this);

    QString tipos[8] = {"A +","A -", "B +", "B -", "AB +", "AB -", "O +", "O -"};
    for(int i=0; i<8; i++) {
        ui->comboTipoSangue->addItem(tipos[i]);
    }

    QString sexo[2] = {"Masculino", "Feminino"};
    ui->comboSexo->addItem(sexo[0]);
    ui->comboSexo->addItem(sexo[1]);

    ui->dateNascimento->setMaximumDate(QDate::currentDate());
    //ui->inputAltura->setValidator(new QIntValidator(50, 300, this));
    //ui->inputPeso->setValidator(new QIntValidator(1000, 1000000, this));
}

CadastrarDoador::~CadastrarDoador()
{
    delete ui;
}

void CadastrarDoador::on_buttonAdd_clicked()
{
    AlertDialog *dialog = new AlertDialog(this);

    // validar e cadastrar dados
    std::string nome = ui->inputNome->text().toStdString();
    std::string cpf = ui->inputCPF->text().toStdString();
    int tipo = ui->comboTipoSangue->currentIndex();
    int sexo = ui->comboSexo->currentIndex();
    std::string altura = ui->inputAltura->text().toStdString();
    std::string peso = ui->inputPeso->text().toStdString();

    int diaNascimento = ui->dateNascimento->date().day();
    int mesNascimento = ui->dateNascimento->date().day();
    int anoNascimento = ui->dateNascimento->date().year();

    Banco* i;
    try {
        if(ui->comboTipoSangue->currentIndex() == -1) throw std::invalid_argument("Selecione um tipo sanguínio!");
        if(!i->isCpf(cpf)) throw std::invalid_argument("CPF inválido!");
        if(i->isDoador(cpf)!= nullptr) throw std::invalid_argument("Credenciais ja cadastradas!");
        if(nome.size() < 2) throw std::invalid_argument("O nome deve ter pelo menos 2 caracteres.");
        if(ui->inputAltura->text() == "") throw std::invalid_argument("Digite a altura do doador.");
        else if(i->isNumber(altura) && std::stoi(altura) <300 && std::stoi(altura) >50) throw std::invalid_argument("Digite a altura do doador.");
        if(ui->inputPeso->text() == "") throw std::invalid_argument("Digite o peso do doador.");
        else if(i->isNumber(peso) && std::stoi(peso) <1000000 && std::stoi(altura) >1000) throw std::invalid_argument("Digite a altura do doador.");
    } catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    double altAux, pesAux;
    try {
        if(!i->isNumber(altura)) throw std::invalid_argument("A altura precisa ser um numero.");
        if(!i->isNumber(peso)) throw std::invalid_argument("O peso precisa ser um numero.");

        altAux = std::stod(altura);
        pesAux = std::stod(peso);
    } catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    i->setDoador(new Doador(nome, cpf, i->criaStructTm(diaNascimento, mesNascimento, anoNascimento), pesAux/1000.00, altAux/100.00, nullptr, tipo, ((sexo) ? Sexo::FEMININO : Sexo::MASCULINO)));

    Dashboard *dashboard = new Dashboard;
    dashboard->show();

    this->close();
}


void CadastrarDoador::on_buttonReturn_clicked()
{
    Dashboard *dashboard = new Dashboard;
    dashboard->show();
    this->close();
}

