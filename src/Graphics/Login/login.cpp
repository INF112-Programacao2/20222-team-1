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
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonInstituicaoLogin_clicked()
{
    this->isInstituicao = true;
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}

void Login::on_buttonProfissionalSaudeLogin_clicked()
{
    this->isInstituicao = false;
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}

void Login::on_buttonLogin_clicked()
{
    AlertDialog *dialog = new AlertDialog(this);

    if(this->isInstituicao){
        try{
             std::string login = ui->inputDocumento->text().toStdString();
             if(i.isCnpj(login)){
                 Instituicao* user = i.isInstituicao(login);
                 if(user != nullptr){
                     if(user->get_senha() != ui->inputSenha->text().toStdString())
                        throw std::out_of_range("Não foi possível autenticar. Verifique os dados fornecidos e tente novamente.");
                 }else
                     throw std::invalid_argument("Nao existe nenhuma conta com essas credenciais.");
             }

         }catch(std::invalid_argument &e){
            dialog->SetMessage(e.what());
         }catch(std::out_of_range &e){
            dialog->SetMessage(e.what());
         }catch(std::exception &e){
            dialog->SetMessage(e.what());
         }
        dialog->show();
    }
    else{
        try{
            std::string login = ui->inputDocumento->text().toStdString();
            if(i.isCpf(login)){
                ProfissionalSaude* user = i.isProfissional(login);
                if(user != nullptr){
                    if(user->get_senha() != ui->inputSenha->text().toStdString())
                        throw std::out_of_range("Verifique sua senha");
                }else
                    throw std::invalid_argument("Não existe nenhuma conta com essas credenciais.");
            }

        }catch(std::invalid_argument &e){
            AlertDialog a(this);
            a.SetMessage(e.what());
            a.show();
        }catch(std::out_of_range &e){
            AlertDialog a(this);
            a.SetMessage(e.what());
            a.show();
        }catch(std::exception &e){
            AlertDialog a(this);
            a.SetMessage(e.what());
            a.show();
        }
    }
}

void Login::on_buttonRegistrarInstituicao_clicked()
{ 

}

