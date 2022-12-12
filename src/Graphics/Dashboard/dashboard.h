#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include <QVBoxLayout>
#include <QColor>
#include <QString>

#include "../ItemView/itemview.h"
#include "../Add/AddConsumo/adicionarconsumo.h"
#include "../Add/AddReceptor/cadastrarreceptor.h"
#include "../Add/AddDoacao/adicionardoacao.h"
#include "../Add/AddDoador/cadastrardoador.h"
#include "../Edit/EditProfissional/editprofissional.h"
#include "../Add/AddReceptor/cadastrarreceptor.h"
#include "../Add/AddDoador/cadastrardoador.h"
#include "../../Banco/Banco.h"
#include "../Register/registerprofissionalsaude.h"
#include "../Login/login.h"
#include "../AlertDialog/alertdialog.h"
#include "../../Sangue/sangue.h"

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

    void on_buttonAdicionarConsumo_2_clicked();

    void on_buttonAdicionarDoacao_2_clicked();

    void on_buttonAdicionarDoador_clicked();

    void on_buttonAdicionarReceptor_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dashboard *ui;
    bool isInstituicao;

    void generateGrafico();
    void populateListDoadores();
    void populateListConsumo();
    void populateListReceptor();
    void populateListDoacao();
};

#endif // DASHBOARD_H
