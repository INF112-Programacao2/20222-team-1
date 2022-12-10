#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

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
    void on_homeButton_clicked();

    void on_btInstituicaoLogin_clicked();

    void on_btProfissionalSaudeLogin_clicked();

    void on_btLogin_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
