#include "adicionardoacao.h"
#include "ui_adicionardoacao.h"
#include "../../../Banco/Banco.h"
#include "../../AlertDialog/alertdialog.h"
#include "../../../Doacao/doacao.h"
#include "../../Dashboard/dashboard.h"
#include <iostream>
#include <QString>
#include <QDateTime>
#include <vector>

Banco* iDoacao;

AdicionarDoacao::AdicionarDoacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarDoacao)
{
    ui->setupUi(this);
    std::vector<Doador*> doadores = iDoacao->getDoadoresDisponiveis();
    if(doadores.size()>0)
        for (int i = 0; i < doadores.size(); i++)
    {
        ui->comboDoador->insertItem(doadores[i]->get_id(), QString::fromStdString(doadores[i]->get_nome()));
    }
    else{
        throw std::out_of_range("Nao ha doadores aptos a usar. ");
    }
    ui->dateColeta->setDateTime(QDateTime::currentDateTime());
}

AdicionarDoacao::~AdicionarDoacao()
{
    delete ui;
}

void AdicionarDoacao::on_buttonReturn_2_clicked()
{
    Dashboard *dashboard = new Dashboard;
    dashboard->show();
    this->close();
}


void AdicionarDoacao::on_buttonRegister_clicked()
{
    // validar cadastro e passar dados aqui
    AlertDialog *dialog = new AlertDialog(this);
    try{
        int id  = ui->comboDoador->currentIndex();
        if( id != -1){
            time_t dataDoacao, now;
            time(&now);
            dataDoacao = mktime(iDoacao->criaStructTm(ui->dateColeta->date().day(), ui->dateColeta->date().month(), ui->dateColeta->date().year()));
            if(now >= dataDoacao)
                if(ui->inputQuantidade->text().toDouble() > 0 && ui->inputQuantidade->text().toDouble() < 100000)
                    iDoacao->setDoacao(new Doacao(iDoacao->criaStructTm(ui->dateColeta->date().day(), ui->dateColeta->date().month(), ui->dateColeta->date().year()),ui->inputQuantidade->text().toDouble(), Banco::_puser->get_instituicao(), Banco::_puser->get_id(), id));
                else
                    throw std::invalid_argument("A quantidade precisa se maior que o e menor que 1. ");
            else 
                throw std::invalid_argument("Data precisa ser menor igual a atual. ");
        }
        else{
            throw std::invalid_argument("Selecione um doador. ");
        }

    }catch(std::invalid_argument &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }catch(std::out_of_range &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }catch(std::exception &e){
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    Dashboard *dashboard = new Dashboard;
    dashboard->show();

    this->close();
}

