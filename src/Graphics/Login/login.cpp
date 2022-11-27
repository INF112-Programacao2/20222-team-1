#include "login.h"
#include "ui_login.h"
#include <QPixmap>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //QPixmap logo("./assets/doesangue_splash_logo.png");
    //ui->logo_img->setPixmap(logo);
}

Login::~Login()
{
    delete ui;
}
