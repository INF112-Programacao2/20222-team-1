#include "adicionarconsumo.h"
#include "ui_adicionarconsumo.h"

#include "../../../Receptor/receptor.h"
#include "../../../Doacao/doacao.h"
#include "../../../Receptor/receptor.h"
#include "../../../Banco/Banco.h"
#include "../../../Doador/Doador.h"
#include "../../../Sangue/sangue.h"
#include "../../Dashboard/dashboard.h"

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
            aux = iAux->getDoadorById(doacoes[i]->get_doador());
            sangueAux = sangue->get_sangue_by_id(aux->get_sangue());
            QString s;
            s.push_back(QString::fromStdString(aux->get_nome()));
            s.push_back(' ');
            s.push_back('-');
            s.push_back(' ');
            s.push_back(QString::fromStdString(sangueAux.get_nome()));
            s.push_back(' ');
            s.push_back((sangueAux.get_rh_sangue() == Rh::POSITIVO) ? '+' : '-');
            ui->comboDoacao->insertItem(sangueAux.get_id(), s);
        }
    } else {
        throw std::out_of_range("Nao ha doacoes disponiveis. ");
    }

    std::vector<Receptor*> receptores = iAux->getReceptores();
    if(receptores.size()>0){
        for (int i = 0; i < (int) receptores.size(); i++){
            sangueAux = sangue->get_sangue_by_id(receptores[i]->get_sangue());
            if(sangueAux.get_rh_sangue() == Rh::POSITIVO)
                ui->comboReceptor->insertItem(sangueAux.get_id(), QString::fromStdString(receptores[i]->get_nome()+" - "+sangueAux.get_nome()+"+"));
            else
                ui->comboReceptor->insertItem(sangueAux.get_id(), QString::fromStdString(receptores[i]->get_nome()+" - "+sangueAux.get_nome()+"-"));
        }
    } else {
        throw std::out_of_range("Nao ha ninguem precisando de uma doacao. ");
    }

    ui->dateConsumo->setDateTime(QDateTime::currentDateTime());
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

    iAux->setConsumo(new Consumo(receptor, Banco::_puser->get_instituicao(), doacao, iAux->criaStructTm(dia, mes, ano)));

    Dashboard *dashboard = new Dashboard;
    dashboard->show();
    this->close();
}


void AdicionarConsumo::on_buttonReturn_clicked()
{
    Dashboard *dashboard = new Dashboard;
    dashboard->show();
    this->close();
}

