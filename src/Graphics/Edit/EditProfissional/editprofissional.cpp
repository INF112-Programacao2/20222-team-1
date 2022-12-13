#include "editprofissional.h"
#include "ui_editprofissional.h"
#include <QString>
#include "../../AlertDialog/alertdialog.h"
#include "../../../ProfissionalSaude/profissionalSaude.h"
#include "../../../Banco/Banco.h"
#include "../../Dashboard/dashboard.h"

Banco* iProfissional;

EditProfissional::EditProfissional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfissional)
{
    ui->setupUi(this);
    ProfissionalSaude* profissional = Banco::_puser;
    ui->inputNome->setText(QString::fromStdString((profissional->get_nome())));
    ui->inputSenha->setText(QString::fromStdString((profissional->get_senha())));
}

EditProfissional::~EditProfissional()
{
    delete ui;
}

void EditProfissional::on_buttonReturn_clicked()
{  
    
    Dashboard *dashboard = new Dashboard;
    dashboard->show();
    this->close();
}


void EditProfissional::on_buttonAdd_clicked()
{
    AlertDialog *dialog = new AlertDialog(this);

    //validar e cadastrar aquiAlertDialog *dialog = new AlertDialog(this);
    try{
        std::string nome = ui->inputNome->text().toStdString();
        if( nome.size() >1){
        std::string senha = ui->inputSenha->text().toStdString();
            if(senha.size()<5)
                throw std::invalid_argument("A senha precisa ter no minimo 2 caracteres. ");
            
            Banco::_puser->set_nome(nome);
            Banco::_puser->set_senha(senha);
        }
        else{
            throw std::invalid_argument("O nome precisa ter no minimo 2 caracteres. ");
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

