#ifndef CADASTRARRECEPTOR_H
#define CADASTRARRECEPTOR_H

#include <QMainWindow>

namespace Ui {
class CadastrarReceptor;
}

class CadastrarReceptor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CadastrarReceptor(QWidget *parent = nullptr);
    CadastrarReceptor(Receptor receptor, Qwidget *parent = nullptr);
    ~CadastrarReceptor();

private slots:
    void on_buttonReturn_clicked();

    void on_buttonAdd_clicked();

private:
    Ui::CadastrarReceptor *ui;
};

#endif // CADASTRARRECEPTOR_H
