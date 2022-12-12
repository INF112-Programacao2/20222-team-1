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

private slots:
    void on_buttonReturn_clicked();

    void on_buttonAdd_clicked();

private:
    Ui::EditProfissional *ui;
};

#endif // EDITPROFISSIONAL_H
