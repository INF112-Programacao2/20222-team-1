#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include "../../Sangue/sangue.h"
#include <string>

namespace Ui {
class ItemView;
}

class ItemView : public QWidget
{
    Q_OBJECT

public:
    explicit ItemView(QWidget *parent = nullptr);
    ~ItemView();
    void set_id(int id);
    void set_nome(std::string nome);
    void set_Rh(std::string rh);

private:
    Ui::ItemView *ui;
};

#endif // ITEMVIEW_H
