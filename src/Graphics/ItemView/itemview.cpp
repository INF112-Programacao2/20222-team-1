#include "itemview.h"
#include "ui_itemview.h"

ItemView::ItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemView)
{
    ui->setupUi(this);
}

ItemView::~ItemView()
{
    delete ui;
}
