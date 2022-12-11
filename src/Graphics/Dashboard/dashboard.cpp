#include "dashboard.h"
#include "ui_dashboard.h"
#include "../ItemView/itemview.h"
#include <QListWidgetItem>
Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    QListWidgetItem *item;
    ItemView *view;

    ui->listWidget->setUniformItemSizes(true);
    for (int var = 0; var < 10; ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        ui->listWidget->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->listWidget->setItemWidget(item, view);

    }


}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_buttonAdicionarConsumo_clicked()
{

}


void Dashboard::on_buttonAdicionarDoacao_clicked()
{

}


void Dashboard::on_buttonConsultarBanco_clicked()
{

}


void Dashboard::on_buttonEditarPerfil_clicked()
{

}
