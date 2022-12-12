#include "adicionarconsumo.h"
#include "ui_adicionarconsumo.h"

#include "../../../Receptor/receptor.h"
#include "../../../Doacao/doacao.h"
#include "../../../Receptor/receptor.h"
#include "../../../Banco/Banco.h"
#include "../../../Doador/Doador.h"

Banco* iAux;

AdicionarConsumo::AdicionarConsumo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarConsumo)
{
    ui->setupUi(this);

    Doador* aux;
    std::vector<Doacao*> doacoes = iAux->getDoacoesByUser();
    if(doacoes.size()>0){
        for (int i = 0; i < doacoes.size(); i++){
            aux = iAux->getDoadorById(doacoes[i]->getDoador());
            /*ui->comboDoacao->insertItem(doacoes[i]->get_id(),  A Consertar: QString::fromStdString(iAux->get aux->get_sangue()));*/
        }
    } else {
        throw std::out_of_range("Nao ha doacoes disponiveis. ");
    }

    std::vector<Receptor*> receptores = iAux->getReceptoresByUser();
    if(receptores.size()>0){
        for (int i = 0; i < receptores.size(); i++){
            /*ui->comboReceptor->insertItem(receptores[i]->get_nome(), " ", A Consertar: QString::fromStdString(receptores[i]->get_sangue()));*/
        }
    } else {
        throw std::out_of_range("Nao ha ninguem precisando de uma doacao. ");
    }

}

AdicionarConsumo::~AdicionarConsumo()
{
    delete ui;
}

void AdicionarConsumo::on_buttonAdd_clicked()
{
    // validar cadastro aqui
    this->close();
}


void AdicionarConsumo::on_buttonReturn_clicked()
{
    this->close();
}

