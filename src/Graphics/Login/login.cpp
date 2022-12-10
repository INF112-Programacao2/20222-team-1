#include "login.h"
#include "ui_login.h"
#include "../Banco/Banco.h"

Banco i;

bool isWord(std::string palavra){
    for(int i =0; i< palavra.size(); i++){    
        if(isdigit(palavra[i]))
               throw std::invalid_argument("/!\\A palavra digitada deve conter apenas letras. ");    
    }
    return true;
}

bool isCpf(std::string palavra){
    if(palavra.size()==14){
        for(int i=0; i< palavra.size(); i++){     
            if(palavra[i]!='.' && (i==3 || i==7))
                throw std::invalid_argument("/!\\Formato invalido de CPF. Verifique os '.'. "); 
            else if(palavra[i]!='-' && i== 11 )
                throw std::invalid_argument("/!\\Formato invalido de CPF. Verifique os '-'. ");    
            else if(!isdigit(palavra[i]) && palavra[i]!='-' && palavra[i]!='.' && palavra[i]!='/'){
                std::cout<<i<<":"<<palavra[i]<<std::endl;
                throw std::invalid_argument("/!\\O CPF e composto apenas de numeros. Nao possui letras. "); 

            } 
        }
    }
    else
        throw std::out_of_range("/!\\O CPF deve possui 14 caracteres( verifique a pontuação). "); 
    return 0;   
}


Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->frSelectTypeUser->setVisible(true);
    ui->frLogarForm->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::on_homeButton_clicked()
{

}


void Login::on_btInstituicaoLogin_clicked()
{
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}


void Login::on_btProfissionalSaudeLogin_clicked()
{
    try{
        std::string login = ui->lineEdit->text();
        if(isCpf(login)){
            ProfissionalSaude* user = i.isProfissional(login);
            if(user != nullptr){
                if(user->get_senha() == ui->lineEdit2->text())
                    std::cout<<"bonaceta natasha";
                else
                    throw std::out_of_range("Verifique sua senha");
            }else
                throw std::exception("Não existe nenhuma conta com essas credenciais.");
        }

    }catch(std::invalid_argument &e){
        QMessageBox::information(this, "Atencao", e,what());
    }catch(std::out_of_range &e){
        QMessageBox::information(this, "Atencao", e,what());
    }catch(std::exception &e){
        QMessageBox::information(this, "Atencao", e,what());
    }

    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}


void Login::on_btLogin_clicked()
{

}

