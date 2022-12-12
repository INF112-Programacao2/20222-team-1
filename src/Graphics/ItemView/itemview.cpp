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
}

void ItemView::set_nome(std::string nome)
{
}

void ItemView::set_Rh(Rh rh)
{
}

ItemView::~ItemView()
{
    delete ui;
}
