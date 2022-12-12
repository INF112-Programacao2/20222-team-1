#include "editprofissional.h"
#include "ui_editprofissional.h"

EditProfissional::EditProfissional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfissional)
{
    ui->setupUi(this);
}

EditProfissional::~EditProfissional()
{
    delete ui;
}
