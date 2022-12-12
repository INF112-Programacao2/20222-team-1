#include "cadastrardoador.h"
#include "ui_cadastrardoador.h"

#include "../../AlertDialog/alertdialog.h"
#include "../../../Banco/Banco.h"

#import <ctime>
#include <string>
#include <QIntValidator>

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
    ui->inputAltura->setValidator(new QIntValidator(50, 300, this));
    ui->inputPeso->setValidator(new QIntValidator(1000, 1000000, this));
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
    double altura = (double) ui->inputAltura->text().toInt() / 100.00;
    double peso = (double) ui->inputPeso->text().toInt() / 100.00;

    int diaNascimento = ui->dateNascimento->date().day();
    int mesNascimento = ui->dateNascimento->date().day();
    int anoNascimento = ui->dateNascimento->date().year();

    int diaUltimo = ui->dataUltimaDoacao->date().day();
    int mesUltimo = ui->dataUltimaDoacao->date().month();
    int anoUltimo = ui->dataUltimaDoacao->date().dayOfYear();

    Banco* i;
    try {
        if(ui->comboTipoSangue->currentIndex() == -1) throw std::invalid_argument("Selecione um tipo sanguínio!");
        if(!i->isCpf(cpf)) throw std::invalid_argument("CPF inválido!");
        if(nome.size() < 2) throw std::invalid_argument("O nome deve ter pelo menos 2 caracteres.");
        if(ui->inputAltura->text() == "") throw std::invalid_argument("Digite a altura do doador.");
        if(ui->inputPeso->text() == "") throw std::invalid_argument("Digite o peso do doador.");
    } catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    i->setDoador(new Doador(nome, cpf, i->criaStructTm(diaNascimento, mesNascimento, anoNascimento), peso, altura, i->criaStructTm(diaUltimo, mesUltimo, anoUltimo), tipo, ((sexo) ? Sexo::FEMININO : Sexo::MASCULINO)));

    this->close();
}


void CadastrarDoador::on_buttonReturn_clicked()
{
    this->close();
}

