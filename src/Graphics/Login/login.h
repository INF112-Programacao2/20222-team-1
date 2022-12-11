#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <exception>
#include <iostream>
#include <QMessageBox>
#include <QIcon>
#include "../Dashboard/dashboard.h"
#include "../AlertDialog/alertdialog.h"
#include "../Register/registerinstituicao.h"
#include "../../Banco/Banco.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_buttonInstituicaoLogin_clicked();

    void on_buttonProfissionalSaudeLogin_clicked();

    void on_buttonLogin_clicked();

    void on_buttonRegistrarInstituicao_clicked();

private:
    Ui::Login *ui;
    bool isInstituicao;
    bool isSelect;
};

#endif // LOGIN_H
