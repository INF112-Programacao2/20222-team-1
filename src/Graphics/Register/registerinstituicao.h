#ifndef REGISTERINSTITUICAO_H
#define REGISTERINSTITUICAO_H

#include <QMainWindow>
#include <QMessageBox>
#include "../Login/login.h"
#include "../../Instituicao/instituicao.h"
#include "../../Banco/Banco.h"

namespace Ui {
class RegisterInstituicao;
}

class RegisterInstituicao : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterInstituicao(QWidget *parent = nullptr);
    RegisterInstituicao(Instituicao instituicao, QWidget *parent = nullptr);
    ~RegisterInstituicao();

private slots:
    void on_buttonReturn_clicked();

    void on_buttonRegister_clicked();

private:
    Ui::RegisterInstituicao *ui;
};

#endif // REGISTERINSTITUICAO_H
