#ifndef REGISTERINSTITUICAO_H
#define REGISTERINSTITUICAO_H

#include <QMainWindow>

namespace Ui {
class RegisterInstituicao;
}

class RegisterInstituicao : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterInstituicao(QWidget *parent = nullptr);
    ~RegisterInstituicao();

private slots:
    void on_buttonReturn_clicked();

    void on_buttonRegister_clicked();

private:
    Ui::RegisterInstituicao *ui;
};

#endif // REGISTERINSTITUICAO_H
