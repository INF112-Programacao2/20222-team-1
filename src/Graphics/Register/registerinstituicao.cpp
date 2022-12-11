#include "registerinstituicao.h"
#include "ui_registerinstituicao.h"

Banco j(0);

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

}


void RegisterInstituicao::on_buttonRegister_clicked()
{
    try{
        std::string login = ui->inputCnpj->text().toStdString();
        if(j.isCnpj(login)){
            Instituicao* user = j.isInstituicao(login);
            if(user != nullptr)
                throw std::invalid_argument("Ja existe conta com essas credenciais.");
        }

    }catch(std::invalid_argument &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::out_of_range &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::exception &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }
}

