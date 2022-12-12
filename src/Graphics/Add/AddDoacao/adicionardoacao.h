#ifndef ADICIONARDOACAO_H
#define ADICIONARDOACAO_H

#include <QMainWindow>

namespace Ui {
class AdicionarDoacao;
}

class AdicionarDoacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdicionarDoacao(QWidget *parent = nullptr);
    ~AdicionarDoacao();

private:
    Ui::AdicionarDoacao *ui;

private slots:
    void on_buttonReturn_2_clicked();
    void on_buttonRegister_clicked();
};

#endif // ADICIONARDOACAO_H
