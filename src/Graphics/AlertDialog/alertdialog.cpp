#include "alertdialog.h"
#include "ui_alertdialog.h"

AlertDialog::AlertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlertDialog)
{
    ui->setupUi(this);
}

AlertDialog::~AlertDialog()
{
    delete ui;
}

void AlertDialog::SetMessage(std::string message){
    this->ui->label->setText(QString::fromStdString(message));
}
