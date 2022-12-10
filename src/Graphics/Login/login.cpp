#include "login.h"
#include "ui_login.h"

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
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}


void Login::on_btLogin_clicked()
{

}

