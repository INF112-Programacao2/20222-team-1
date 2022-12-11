#ifndef ADICIONARCONSUMO_H
#define ADICIONARCONSUMO_H

#include <QMainWindow>

namespace Ui {
class AdicionarConsumo;
}

class AdicionarConsumo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdicionarConsumo(QWidget *parent = nullptr);
    ~AdicionarConsumo();

private:
    Ui::AdicionarConsumo *ui;
};

#endif // ADICIONARCONSUMO_H
