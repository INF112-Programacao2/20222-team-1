#include "login.h"
#include "ui_login.h"

/*Banco i;

bool isWord(std::string palavra){
    for(int i =0; i< palavra.size(); i++){    
        if(isdigit(palavra[i]))
               throw std::invalid_argument("/!\\A palavra digitada deve conter apenas letras. ");    
    }
    return true;
}

bool isCnpj(std::string palavra){
    if(palavra.size()==11){
        int soma1 = 0;
        int soma2 = 0;
        for(int i=0, int j = 10, int y= 11; i< palavra.size(), j>0, y>0; i++, j--, y--){     
            if(palavra[i]!='.' && (i==3 || i==7))
                throw std::invalid_argument("/!\\Formato invalido de CPF. Verifique os '.'. "); 
            else if(palavra[i]!='-' && i== 11 )
                throw std::invalid_argument("/!\\Formato invalido de CPF. Verifique os '-'. ");    
            else if(!isdigit(palavra[i]) && palavra[i]!='-' && palavra[i]!='.' && palavra[i]!='/'){
                std::cout<<i<<":"<<palavra[i]<<std::endl;
                throw std::invalid_argument("/!\\O CPF e composto apenas de numeros. Nao possui letras. "); 

            } 
            soma1 += std::stoi(palavra[i])*j;
            soma2 += std::stoi(palavra[i])*y;
        }
        if((soma1%11 <2) && (soma2%11 < 2)){
            if(palavra[10] !=0 && palavra[11] !=0)
                throw std::out_of_range("CPF invalido. ")
        }else if!(palavra[10] == 11-soma1%11 && palavra[11] == 11-soma2%11){
            if(palavra[10] >1 && palavra[11]>1)
            throw std::out_of_range("CPF invalido. ")
        }

    }
    else
        throw std::out_of_range("/!\\O CPF deve possui 11 caracteres. "); 
    return 0;   
}
*/
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->frSelectTypeUser->setVisible(true);
    ui->frLogarForm->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonInstituicaoLogin_clicked()
{
   /* try{
        std::string login = ui->inputDocumento->text().toStdString();
        if(isCnpj(login)){
            Instituicao* user = i.isInstituicao(login);
            if(user != nullptr){
                if(user->get_senha() == ui->inputSenha->text().toStdString())
                    std::cout<<"bonaceta natasha";
                else
                    throw std::out_of_range("Verifique sua senha");
            }else
                throw std::exception("Não existe nenhuma conta com essas credenciais.");
        }

    }catch(std::invalid_argument &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::out_of_range &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::exception &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);*/
}

void Login::on_buttonProfissionalSaudeLogin_clicked()
{ /*
    try{
        std::string login = ui->inputDocumento->text().toStdString();
        if(isCpf(login)){
            ProfissionalSaude* user = i.isProfissional(login);
            if(user != nullptr){
                if(user->get_senha() == ui->inputSenha->text().toStdString())
                    std::cout<<"bonaceta natasha";
                else
                    throw std::out_of_range("Verifique sua senha");
            }else
                throw std::exception("Não existe nenhuma conta com essas credenciais.");
        }

    }catch(std::invalid_argument &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::out_of_range &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::exception &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);*/
}

void Login::on_buttonLogin_clicked()
{
   
}

void Login::on_buttonRegistrarInstituicao_clicked()
{ 
    try{
        std::string login = ui->inputDocumento->text().toStdString();
        if(isCnpj(login)){
            ProfissionalSaude* user = i.isProfissional(login);
            if(user != nullptr){
                if(user->get_senha() == ui->inputSenha->text().toStdString())
                    std::cout<<"bonaceta natasha";
                else
                    throw std::out_of_range("Verifique sua senha");
            }else
                throw std::exception("Não existe nenhuma conta com essas credenciais.");
        }

    }catch(std::invalid_argument &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::out_of_range &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }catch(std::exception &e){
        QMessageBox::information(this, "Atencao!", e.what());
    }
}

