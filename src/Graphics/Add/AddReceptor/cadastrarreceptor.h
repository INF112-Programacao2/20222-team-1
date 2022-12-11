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
    ~CadastrarReceptor();

private:
    Ui::CadastrarReceptor *ui;
};

#endif // CADASTRARRECEPTOR_H
