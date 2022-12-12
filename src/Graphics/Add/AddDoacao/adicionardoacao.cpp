#include "adicionardoacao.h"
#include "ui_adicionardoacao.h"
#include "../../../Banco/Banco.h"
#include <QString>
#include <vector>

Banco* iDoacao;

AdicionarDoacao::AdicionarDoacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarDoacao)
{
    ui->setupUi(this);
    std::vector<Doador*> doadores = iDoacao->getDoadoresDisponiveis();
    for (int i = 0; i < doadores.size(); i++)
    {
        ui->comboDoador->setItemText(doadores[i]->get_id(), QString::fromStdString(doadores[i]->get_nome()));
    }

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

