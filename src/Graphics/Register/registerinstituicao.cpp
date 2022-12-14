#include "registerinstituicao.h"
#include "ui_registerinstituicao.h"

Banco* j;

RegisterInstituicao::RegisterInstituicao(Instituicao instituicao, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::RegisterInstituicao)
{
    ui->setupUi(this);
}

RegisterInstituicao::RegisterInstituicao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterInstituicao)
{
    ui->setupUi(this);
}

RegisterInstituicao::~RegisterInstituicao()
{
    delete ui;
}

void RegisterInstituicao::on_buttonReturn_clicked()
{
    Login *login = new Login;
    login->show();
    this->close();
}

void RegisterInstituicao::on_buttonRegister_clicked()
{
    AlertDialog *dialog = new AlertDialog(this);
    try{
        std::string login = ui->inputCnpj->text().toStdString();
        if(j->isCnpj(login)){
            Instituicao* user = j->isInstituicao(login);
            if(user != nullptr)
                throw std::invalid_argument("Ja existe conta com essas credenciais.");
            std::string senha = ui->inputSenha->text().toStdString();
            if(senha.size() <5)
                throw std::out_of_range("A senha precisa ter no minimo 5 caracteres.");
            std::string nome = ui->inputNomeEntidade->text().toStdString();
            if(nome.size() <2)
                throw std::out_of_range("O nome precisa ter no minimo 2 caracteres.");
            std::string endereco = ui->inputEndereco->text().toStdString();
            if(endereco.size() <5)
                throw std::out_of_range("O endereco precisa ter no minimo 5 caracteres.");
            j->setInstituicao(new Instituicao(nome, endereco, login, senha));
        }
        else{
            throw std::invalid_argument("Insira um CNPJ válido!");
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

    delete dialog;
    Login *login = new Login;
    login->show();
    this->close();
}

