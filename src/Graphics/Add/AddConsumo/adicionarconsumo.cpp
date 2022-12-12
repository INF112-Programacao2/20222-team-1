#include "adicionarconsumo.h"
#include "ui_adicionarconsumo.h"

#include "../../../Receptor/receptor.h"
#include "../../../Doacao/doacao.h"
#include "../../../Receptor/receptor.h"
#include "../../../Banco/Banco.h"
#include "../../../Doador/Doador.h"
#include "../../../Sangue/sangue.h"

Banco* iAux;

AdicionarConsumo::AdicionarConsumo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarConsumo)
{
    ui->setupUi(this);

    Sangue* sangue = nullptr;
    Sangue sangueAux;
    Doador* aux;

    std::vector<Doacao*> doacoes = iAux->getDoacoesByUser();
    if(doacoes.size()>0){
        for (int i = 0; i < (int) doacoes.size(); i++){
            aux = iAux->getDoadorById(doacoes[i]->getDoador());
            sangueAux = sangue->get_sangue_by_id(aux->get_sangue());
            ui->comboDoacao->insertItem(sangueAux.get_id(), QString::fromStdString(sangueAux.get_nome()));
        }
    } else {
        throw std::out_of_range("Nao ha doacoes disponiveis. ");
    }

    std::vector<Receptor*> receptores = iAux->getReceptoresByUser();
    if(receptores.size()>0){
        for (int i = 0; i < (int) receptores.size(); i++){
            sangueAux = sangue->get_sangue_by_id(receptores[i]->get_sangue());
            ui->comboReceptor->insertItem(sangueAux.get_id(), QString::fromStdString(sangueAux.get_nome()));
        }
    } else {
        throw std::out_of_range("Nao ha ninguem precisando de uma doacao. ");
    }

    ui->dateConsumo->setMaximumDate(QDate::currentDate());

}

AdicionarConsumo::~AdicionarConsumo()
{
    delete ui;
}

void AdicionarConsumo::on_buttonAdd_clicked()
{
    // validar cadastro aqui
    int receptor = ui->comboReceptor->currentIndex();
    int doacao = ui->comboDoacao->currentIndex();

    int dia = ui->dateConsumo->date().day();
    int mes = ui->dateConsumo->date().day();
    int ano = ui->dateConsumo->date().year();

    iAux->setConsumo(new Consumo(receptor, Banco::_puser->get_idInstituicao(), doacao, iAux->criaStructTm(dia, mes, ano)));

    this->close();
}


void AdicionarConsumo::on_buttonReturn_clicked()
{
    this->close();
}

