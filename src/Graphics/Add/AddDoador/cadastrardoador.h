#ifndef CADASTRARDOADOR_H
#define CADASTRARDOADOR_H

#include <QMainWindow>

namespace Ui {
class CadastrarDoador;
}

class CadastrarDoador : public QMainWindow
{
    Q_OBJECT

public:
    explicit CadastrarDoador(QWidget *parent = nullptr);
    ~CadastrarDoador();

private slots:
    void on_buttonAdd_clicked();

    void on_buttonReturn_clicked();

private:
    Ui::CadastrarDoador *ui;
};

#endif // CADASTRARDOADOR_H
