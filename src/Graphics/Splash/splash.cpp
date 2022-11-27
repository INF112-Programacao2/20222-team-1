#include "splash.h"
#include "./ui_splash.h"

Splash::Splash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Splash)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Splash::~Splash()
{
    delete ui;
}

