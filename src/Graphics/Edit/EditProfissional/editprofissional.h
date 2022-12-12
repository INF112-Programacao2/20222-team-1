#ifndef EDITPROFISSIONAL_H
#define EDITPROFISSIONAL_H

#include <QMainWindow>

namespace Ui {
class EditProfissional;
}

class EditProfissional : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditProfissional(QWidget *parent = nullptr);
    ~EditProfissional();

private:
    Ui::EditProfissional *ui;
};

#endif // EDITPROFISSIONAL_H
