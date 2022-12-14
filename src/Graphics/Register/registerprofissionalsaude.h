#ifndef REGISTERPROFISSIONALSAUDE_H
#define REGISTERPROFISSIONALSAUDE_H

#include <QMainWindow>
#include "../../ProfissionalSaude/profissionalSaude.h"

namespace Ui {
class RegisterProfissionalSaude;
}

class RegisterProfissionalSaude : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterProfissionalSaude(QWidget *parent = nullptr);
    RegisterProfissionalSaude(ProfissionalSaude profissional, QWidget *parent = nullptr);
    ~RegisterProfissionalSaude();

private slots:
    void on_buttonReturn_clicked();

    void on_buttonRegistrar_clicked();

private:
    Ui::RegisterProfissionalSaude *ui;
};

#endif // REGISTERPROFISSIONALSAUDE_H
