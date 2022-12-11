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
};

#endif // ADICIONARDOACAO_H
