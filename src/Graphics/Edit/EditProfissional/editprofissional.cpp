#include "editprofissional.h"
#include "ui_editprofissional.h"
#include <QString>
#include "../../../ProfissionalSaude/profissionalSaude.h"
#include "../../../Banco/Banco.h"

Banco* iProfissional;

EditProfissional::EditProfissional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProfissional)
{
    ui->setupUi(this);
    ProfissionalSaude* profissional = Banco::_puser;
    ui->inputNome->setText(QString::fromStdString((profissional->get_nome())));
    ui->inputSenha->setText(QString::fromStdString((profissional->get_senha())));
}

EditProfissional::~EditProfissional()
{
    delete ui;
}

void EditProfissional::on_buttonReturn_clicked()
{
    this->close();
}


void EditProfissional::on_buttonAdd_clicked()
{
    //validar e cadastrar aqui
    this->close();
}

