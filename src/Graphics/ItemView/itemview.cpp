#include "itemview.h"
#include "ui_itemview.h"

ItemView::ItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemView)
{
    ui->setupUi(this);
}

void ItemView::set_id(int id)
{
    ui->txtId->setText(QString::fromStdString(std::to_string(id)));
}

void ItemView::set_nome(std::string nome)
{
    ui->txtNome->setText(QString::fromStdString(nome));
}

void ItemView::set_Rh(std::string rh)
{
    ui->txtSangue->setText(QString::fromStdString(rh));
}

ItemView::~ItemView()
{
    delete ui;
}
