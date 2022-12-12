#include "login.h"
#include "ui_login.h"

Banco i;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->frSelectTypeUser->setVisible(true);
    ui->frLogarForm->setVisible(false);

    this->isInstituicao = false;
    this->isSelect = true;
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonInstituicaoLogin_clicked()
{
    this->isInstituicao = true;
    this->isSelect = false;

    QIcon icon;
    icon.addFile("://assets/icons/return.png");

    ui->buttonRegistrarInstituicao->setIcon(icon);
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);

}

void Login::on_buttonProfissionalSaudeLogin_clicked()
{
    this->isInstituicao = false;
    this->isSelect = false;

    QIcon icon;
    icon.addFile("://assets/icons/return.png");

    ui->buttonRegistrarInstituicao->setIcon(icon);
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}

void Login::on_buttonLogin_clicked()
{
    AlertDialog *dialog = new AlertDialog(this);

    //Autentica instituicao
    if(this->isInstituicao){
        try{
             std::string login = ui->inputDocumento->text().toStdString();
             if(!i.isCnpj(login)){
                 Instituicao* user = i.isInstituicao(login);
                 if(user != nullptr){
                     if(user->get_senha() != ui->inputSenha->text().toStdString())
                        throw std::out_of_range("Senha incorreta.");
                 }else
                     throw std::invalid_argument("Nao existe nenhuma conta com essas credenciais.");
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
    }
    //Autentica instituição
    else{
        try{
            std::string login = ui->inputDocumento->text().toStdString();
            if(!i.isCpf(login)){
                ProfissionalSaude* user = i.isProfissional(login);
                if(user != nullptr){
                    if(user->get_senha() != ui->inputSenha->text().toStdString())
                        throw std::out_of_range("Verifique sua senha");
                }else
                    throw std::invalid_argument("Não existe nenhuma conta com essas credenciais.");
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
    }

    delete dialog;

    Dashboard *dashboard = new Dashboard;
    dashboard->show();

    this->hide();
}

void Login::on_buttonRegistrarInstituicao_clicked()
{ 
    if(!this->isSelect){
        this->isInstituicao = false;
        this->isSelect = true;

        QIcon icon;
        icon.addFile("://assets/icons/home.png");

        ui->buttonRegistrarInstituicao->setIcon(icon);
        ui->frSelectTypeUser->setVisible(true);
        ui->frLogarForm->setVisible(false);

        return;
    }

    RegisterInstituicao *resInstituicao = new RegisterInstituicao;
    resInstituicao->show();

    this->hide();
}

