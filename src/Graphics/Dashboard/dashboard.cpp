#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    this->generateGrafico();
    this->populateListDoadores();
    this->populateListDoacao();
    this->populateListConsumo();
    this->populateListReceptor();

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
        ui->txtNomeInstituicao->setText(QString::fromStdString(Banco::_iuser->get_nome()));
    }
    else{
        this->isInstituicao = false;
          Banco *i;

        ui->txtNomeInstituicao->setText(QString::fromStdString(i->getInstituicaoById(Banco::_puser->get_idInstituicao())->get_nome()));
        ui->txtNomeProfissional->setText(QString::fromStdString(Banco::_puser->get_nome()));
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

    std::vector<Doador*> doa = i->getDoadoresByUser();
    ui->doadoresList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(doa[var]->get_nome());
        view->set_Rh(Sangue().get_sangue_by_id(doa[var]->get_sangue()).get_nome());
        ui->doadoresList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->doadoresList->setItemWidget(item, view);
    }
}

void Dashboard::populateListConsumo(){
    Banco *i;

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Consumo*> doa = i->getConsumosByUser();
    ui->consumoList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(i->getReceptorById(doa[var]->get_idReceptor())->get_nome());
        view->set_Rh("");
        ui->consumoList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->consumoList->setItemWidget(item, view);
    }
}

void Dashboard::populateListDoacao(){
    Banco *i;

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Doacao*> doa = i->getDoacoesByUser();
    ui->doacoesList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(i->getInstituicaoById(doa[var]->getInstituicao())->get_nome());
        view->set_Rh(std::to_string(doa[var]->getQuantidade()));
        ui->doacoesList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->doacoesList->setItemWidget(item, view);
    }
}

void Dashboard::populateListReceptor(){
    Banco *i;

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Receptor*> doa = i->getReceptoresByUser();
    ui->receptoresList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(doa[var]->get_nome());
        view->set_Rh("");
        ui->receptoresList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->receptoresList->setItemWidget(item, view);
    }
}

void Dashboard::generateGrafico(){
    if (Banco::_puser != nullptr){
        Banco *i;
        //Construir gráfico
        QBarSet *bar1 = new QBarSet("Sangue");

        std::vector<int> aaa =  i->getEstoque(Banco::_puser->get_idInstituicao());
        *bar1 << aaa[0] << aaa[1] << aaa[2] << aaa[3] << aaa[4] << aaa[5]<< aaa[6] << aaa[7];
        bar1->setColor(QColor("#ff0000"));
        QBarSeries *series = new QBarSeries;
        series->append(bar1);

        QChart *chart = new QChart;
        chart->addSeries(series);
        chart->setTitle("Estoque de Sangue");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "A+" << "A-" << "B+" << "B-" << "O+" << "0-" << "AB+" << "AB-";
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

}

void Dashboard::on_buttonAdicionarConsumo_clicked()
{
    AlertDialog *dialog  = new AlertDialog(this);
    AdicionarConsumo *consumo;
    try {
        consumo = new AdicionarConsumo;
    } catch (const std::out_of_range &e) {
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    consumo->show();
    this->close();
}


void Dashboard::on_buttonAdicionarDoacao_clicked()
{
    AlertDialog *dialog  = new AlertDialog(this);
    AdicionarDoacao *doacao;
    try {
        doacao = new AdicionarDoacao;
    } catch (const std::out_of_range &e) {
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    doacao->show();
    this->close();
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
        EditProfissional *profissional = new EditProfissional;
        profissional->show();
    }
}

void Dashboard::on_buttonAdicionarConsumo_2_clicked()
{
    AlertDialog *dialog  = new AlertDialog(this);
    AdicionarConsumo *consumo;
    try {
        consumo = new AdicionarConsumo;
    } catch (const std::out_of_range &e) {
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }

    consumo->show();
    this->close();
}


void Dashboard::on_buttonAdicionarDoacao_2_clicked()
{
    AlertDialog *dialog  = new AlertDialog(this);
    AdicionarDoacao *doacao;
    try {
        doacao = new AdicionarDoacao;
    } catch (const std::out_of_range &e) {
        dialog->SetMessage(e.what());
        dialog->exec();
        return;
    }
    doacao->show();
    this->close();
}

void Dashboard::on_buttonAdicionarDoador_clicked()
{
    CadastrarDoador *doador = new CadastrarDoador;
    doador->show();
    this->close();
}


void Dashboard::on_buttonAdicionarReceptor_clicked()
{
    CadastrarReceptor *receptor = new CadastrarReceptor;
    receptor->show();
    this->close();
}

void Dashboard::on_pushButton_clicked()
{
    Login *login = new Login;
    Banco::_iuser = nullptr;
    Banco::_puser = nullptr;
    login->show();
    this->close();
}

