#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    QListWidgetItem *item;
    ItemView *view;

    ui->listWidget->setUniformItemSizes(true);
    for (int var = 0; var < 10; ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        ui->listWidget->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->listWidget->setItemWidget(item, view);
    }

    //Construir gráfico
    QBarSet *bar1 = new QBarSet("Sangue");


    *bar1 << 5 << 0<< 8 << 25<< 5 << 0<< 8 << 25;
    bar1->setColor(QColor("#ff0000"));
    QBarSeries *series = new QBarSeries;
    series->append(bar1);

    QChart *chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Estoque de Sangue");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "A+" << "B+" << "AB+" << "O+" << "A-" << "B-" << "AB-" << "O-";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,30);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    auto layout = new QVBoxLayout();
    layout->addWidget(chartView);
    this->ui->graphicsFrame->setLayout(layout);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_buttonAdicionarConsumo_clicked()
{
    AdicionarConsumo *consumo = new AdicionarConsumo(this);
    consumo->show();
}


void Dashboard::on_buttonAdicionarDoacao_clicked()
{
    AdicionarDoacao *doacao = new AdicionarDoacao(this);
    doacao->show();
}


void Dashboard::on_buttonConsultarBanco_clicked()
{
}


void Dashboard::on_buttonEditarPerfil_clicked()
{
    EditProfissional *profissional = new EditProfissional(this);
    profissional->show();
}
