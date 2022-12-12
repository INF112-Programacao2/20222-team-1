#include "adicionarconsumo.h"
#include "ui_adicionarconsumo.h"

#include "../../../Receptor/receptor.h"
#include "../../../Doacao/doacao.h"


AdicionarConsumo::AdicionarConsumo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdicionarConsumo)
{
    ui->setupUi(this);
}

AdicionarConsumo::~AdicionarConsumo()
{
    delete ui;
}

void AdicionarConsumo::on_buttonAdd_clicked()
{

}

