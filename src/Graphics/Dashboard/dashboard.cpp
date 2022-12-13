#include "dashboard.h"
#include "ui_dashboard.h"

Banco *idashboard;

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
        ui->tabs->removeTab(2);
        ui->tabs->removeTab(2);
        ui->tabDoador->hide();
        ui->tabReceptor->hide();

        ui->txtNomeProfissional->setText(QString::fromStdString(Banco::_iuser->get_nome()));
        ui->txtNomeInstituicao->setText(QString::fromStdString(Banco::_iuser->get_cnpj()));

        QIcon icon;
        icon.addFile("://assets/icons/add.png");

        ui->buttonEditarPerfil->setIcon(icon);
        ui->buttonEditarPerfil->setText("Profissional Saúde");
    }
    else{
        this->isInstituicao = false;

        ui->txtNomeInstituicao->setText(QString::fromStdString(idashboard->getInstituicaoById(Banco::_puser->get_instituicao())->get_nome()));
        ui->txtNomeProfissional->setText(QString::fromStdString(Banco::_puser->get_nome()));
        ui->tabs->removeTab(1);
    }

    std::string contDoadores = std::to_string(idashboard->getDoadores().size())+" doador(es)";
    std::string contAptos = std::to_string(idashboard->getDoadoresDisponiveis().size())+" apt(os) a doar";
    std::string contFora = std::to_string(idashboard->getDoadores().size()-idashboard->getDoadoresDisponiveis().size())+" inapto(s)";
    ui->txtContDoadores->setText(QString::fromStdString(contDoadores));
    ui->txtContAptos->setText(QString::fromStdString(contAptos));
    ui->txtContFora->setText(QString::fromStdString(contFora));

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::populateListDoadores(){

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Doador*> doa = idashboard->getDoadores();
    ui->doadoresList->setUniformItemSizes(true);
    //if(doa.size() == 0)

    //else
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(doa[var]->get_nome());
        if(Sangue().get_sangue_by_id(doa[var]->get_sangue()).get_rh_sangue() == Rh::POSITIVO)
            view->set_Rh(Sangue().get_sangue_by_id(doa[var]->get_sangue()).get_nome()+"+");
        else
            view->set_Rh(Sangue().get_sangue_by_id(doa[var]->get_sangue()).get_nome()+"-");
        ui->doadoresList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->doadoresList->setItemWidget(item, view);
    }
}

void Dashboard::populateListConsumo(){
    Banco *i;

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Consumo*> doa = idashboard->getConsumosByUser();
    ui->consumoList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(idashboard->getReceptorById(doa[var]->get_receptor())->get_nome());
        view->set_Rh("");
        ui->consumoList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->consumoList->setItemWidget(item, view);
    }
}

void Dashboard::populateListDoacao(){

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Doacao*> doa = idashboard->getDoacoesByUser();
    ui->doacoesList->setUniformItemSizes(true);
    for (int var = 0; var < doa.size(); ++var) {
        item = new QListWidgetItem();
        view = new ItemView;
        view->set_id(doa[var]->get_id());
        view->set_nome(idashboard->getDoadorById(doa[var]->get_doador())->get_nome());
        view->set_Rh(std::to_string(doa[var]->get_quantidade()));
        ui->doacoesList->addItem(item);
        item->setSizeHint(view->sizeHint());
        ui->doacoesList->setItemWidget(item, view);
    }
}

void Dashboard::populateListReceptor(){

    QListWidgetItem *item;
    ItemView *view;

    std::vector<Receptor*> doa = idashboard->getReceptores();
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
    int instituicao = 0;
    if (Banco::_puser != nullptr)
        instituicao = Banco::_puser->get_instituicao();
    else
        instituicao = Banco::_iuser->get_id();

    Banco *i;
    //Construir gráfico
    QBarSet *bar1 = new QBarSet("Sangue");

    std::vector<int> aaa =  idashboard->getEstoque(instituicao);
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

