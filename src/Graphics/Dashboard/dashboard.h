#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_buttonAdicionarConsumo_clicked();

    void on_buttonAdicionarDoacao_clicked();

    void on_buttonConsultarBanco_clicked();

    void on_buttonEditarPerfil_clicked();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
