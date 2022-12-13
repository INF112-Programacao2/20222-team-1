#ifndef ADICIONARCONSUMO_H
#define ADICIONARCONSUMO_H

#include <QMainWindow>
#include "../../../Consumo/consumo.h"

namespace Ui {
class AdicionarConsumo;
}

class AdicionarConsumo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdicionarConsumo(QWidget *parent = nullptr);
    AdicionarConsumo(Consumo consumo, QWidget *parent2 = nullptr);
    ~AdicionarConsumo();

private slots:
    void on_buttonAdd_clicked();

    void on_buttonReturn_clicked();

private:
    Ui::AdicionarConsumo *ui;
};

#endif // ADICIONARCONSUMO_H
