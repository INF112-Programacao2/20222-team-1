#include "registerinstituicao.h"
#include "ui_registerinstituicao.h"

Banco j;

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
        if(j.isCnpj(login)){
            Instituicao* user = j.isInstituicao(login);
            if(user != nullptr)
                throw std::invalid_argument("Ja existe conta com essas credenciais.");
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

