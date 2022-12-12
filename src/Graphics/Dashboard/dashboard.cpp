#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{

    ui->setupUi(this);
    this->generateGrafico();
    this->populateListDoadores();

    if(Banco::_iuser != nullptr){
        this->isInstituicao = true;
        ui->buttonAdicionarDoacao->hide();
        ui->buttonAdicionarConsumo->hide();
        ui->buttonAdicionarReceptor->hide();
        ui->buttonAdicionarDoacao_2->hide();
        ui->buttonAdicionarConsumo_2->hide();
        ui->buttonAdicionarDoador->hide();

        ui->txtNomeProfissional->setText(QString::fromStdString(Banco::_iuser->get_nome()));
        ui->txtNomeInstituicao->setText(QString::fromStdString(Banco::_iuser->get_cnpj()));

        QIcon icon;
        icon.addFile("://assets/icons/add.png");

        ui->buttonEditarPerfil->setIcon(icon);
        ui->buttonEditarPerfil->setText("Profissional Saúde");

    }
    else{
        this->isInstituicao = false;
    }
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::populateListDoadores(){
    Banco *i;

    QListWidgetItem *item;
    ItemView *view;

    ui->doacoesList->setUniformItemSizes(true);
    for (int var = 0; var < 10; ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        ui->doadoresList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->doadoresList->setItemWidget(item, view);
    }

    ui->txtNomeInstituicao->setText(QString::fromStdString(Banco::_iuser->get_nome()));
}

void Dashboard::generateGrafico(){
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
    if(isInstituicao){
        RegisterProfissionalSaude *profissional = new RegisterProfissionalSaude;
        profissional->show();
    }
    else{
        EditProfissional *profissional = new EditProfissional(this);
        profissional->show();
    }
}

void Dashboard::on_buttonAdicionarConsumo_2_clicked()
{
    AdicionarConsumo *consumo = new AdicionarConsumo(this);
    consumo->show();
}


void Dashboard::on_buttonAdicionarDoacao_2_clicked()
{
    AdicionarDoacao *doacao = new AdicionarDoacao(this);
    doacao->show();
}

void Dashboard::on_buttonAdicionarDoador_clicked()
{
    CadastrarDoador *doador = new CadastrarDoador(this);
    doador->show();
}


void Dashboard::on_buttonAdicionarReceptor_clicked()
{
    CadastrarReceptor *receptor = new CadastrarReceptor(this);
    receptor->show();
}
