#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->frSelectTypeUser->setVisible(false);
    ui->frLogarForm->setVisible(true);
}

Login::~Login()
{
    delete ui;
}
