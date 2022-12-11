#include "adicionarconsumo.h"
#include "ui_adicionarconsumo.h"

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
