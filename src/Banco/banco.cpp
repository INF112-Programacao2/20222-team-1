#include <iostream>
#include "Banco.h"
#include <vector>
#include <fstream>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/Doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

Banco *Banco::_instance = nullptr;

Banco::Banco()
{
}

Banco::Banco(int n){
    getInstance();
}

// verificar se ja existe
Banco *Banco::getInstance()
{
     if(_instance ==  nullptr){
        Banco::_instance = new Banco();
        leArquivoConsumo();
        leArquivoDoacao();
        leArquivoDoador();
        leArquivoInstituicao();
        leArquivoProfissional();
        leArquivoReceptor();
    }
}

void Banco::leArquivoDoador()
{
    std::ifstream doador_txt("doador.txt");

    if(doador_txt.tellg() != -1)
        while (!doador_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        double peso, altura;
        struct tm *dataUltimaDoacao = new struct tm;
        int idSangue;

        int dia, mes, ano;
        std::string aux;

        doador_txt >> idPessoa;
        std::getline(doador_txt, nome);
        doador_txt >> cpf;
        doador_txt >> dia >> mes >> ano;
        dataNascimento->tm_mday = dia;
        dataNascimento->tm_mon = mes;
        dataNascimento->tm_year = ano;
        dataNascimento->tm_hour = 0;
        dataNascimento->tm_min = 0;
        dataNascimento->tm_sec = 0;
        doador_txt >> peso >> altura;
        doador_txt >> dia >> mes >> ano;
        dataUltimaDoacao->tm_mday = dia;
        dataUltimaDoacao->tm_mon = mes - 1;
        dataUltimaDoacao->tm_year = ano - 1900;
        dataUltimaDoacao->tm_hour = 0;
        dataUltimaDoacao->tm_min = 0;
        dataUltimaDoacao->tm_sec = 0;
        doador_txt >> idSangue;
        doador_txt >> aux;

        Banco::_instance->setDoador((new Doador(idPessoa, nome, cpf, dataNascimento, peso, altura, dataUltimaDoacao, idSangue)));
    }

    doador_txt.close();
}

void Banco::leArquivoReceptor()
{
    std::ifstream receptor_txt("receptor.txt");

    if(receptor_txt.tellg() != -1)
        while (!receptor_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        int idSangue;

        int dia, mes, ano;
        std::string aux;

        receptor_txt >> idPessoa;
        std::getline(receptor_txt, nome);
        receptor_txt >> cpf;
        receptor_txt >> dia >> mes >> ano;
        dataNascimento->tm_mday = dia;
        dataNascimento->tm_mon = mes - 1;
        dataNascimento->tm_year = ano - 1900;
        dataNascimento->tm_hour = 0;
        dataNascimento->tm_min = 0;
        dataNascimento->tm_sec = 0;
        receptor_txt >> idSangue >> aux;

        Banco::_instance->setReceptor((new Receptor(idPessoa, nome, cpf, dataNascimento, idSangue)));
    }

    receptor_txt.close();
}

void Banco::leArquivoProfissional()
{
    std::ifstream profissional_txt("profissional.txt");
    
    if(profissional_txt.tellg() != -1)
        while (!profissional_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        std::string senha;
        int cargo;
        int idInstituicao;

        int dia, mes, ano;
        std::string aux;

        profissional_txt >> idPessoa;
        std::getline(profissional_txt, nome);
        profissional_txt >> cpf;
        profissional_txt >> dia >> mes >> ano;
        dataNascimento->tm_mday = dia;
        dataNascimento->tm_mon = mes - 1;
        dataNascimento->tm_year = ano - 1900;
        dataNascimento->tm_hour = 0;
        dataNascimento->tm_min = 0;
        dataNascimento->tm_sec = 0;
        profissional_txt >> senha >> cargo >> idInstituicao >> aux;

        if (cargo == 0)
            Banco::_instance->setProfissional((new ProfissionalSaude(idPessoa, nome, cpf, dataNascimento, senha, Cargo::MEDICX, idInstituicao)));
        else if (cargo == 1)
            Banco::_instance->setProfissional((new ProfissionalSaude(idPessoa, nome, cpf, dataNascimento, senha, Cargo::ENFERMEIRX, idInstituicao)));
    }

    profissional_txt.close();
}

void Banco::leArquivoDoacao()
{
    std::ifstream doacao_txt("doacao.txt");
    //std::cout<<doacao_txt.tellg()<<std::endl;
    if(doacao_txt.tellg() != -1)
        while (!doacao_txt.eof())
    {
        int idDoacao;
        struct tm *dataColeta = new struct tm;
        double quantidade;
        int idInstituicao, idProfissional, idDoador;
        bool situacao;

        int dia, mes, ano;
        std::string aux;

        doacao_txt >> idDoacao;
        doacao_txt >> dia >> mes >> ano;
        dataColeta->tm_mday = dia;
        dataColeta->tm_mon = mes - 1;
        dataColeta->tm_year = ano - 1900;
        dataColeta->tm_hour = 0;
        dataColeta->tm_min = 0;
        dataColeta->tm_sec = 0;
        doacao_txt >> quantidade >> idInstituicao >> idProfissional >> idDoador >> situacao >> aux;

        Banco::_instance->setDoacao((new Doacao(idDoacao, dataColeta, quantidade, idInstituicao, idProfissional, idDoador, situacao)));
    }

    doacao_txt.close();
}

void Banco::leArquivoConsumo()
{
    std::ifstream consumo_txt("consumo.txt");
    //std::cout<<consumo_txt.tellg()<<std::endl;
    if(consumo_txt.tellg() != -1)
        while (!consumo_txt.eof() )
    {
        int idConsumo, idReceptor, idInstituicao, idDoacao;
        struct tm *dataConsumo = new struct tm;

        int dia, mes, ano;
        std::string aux;

        consumo_txt >> idConsumo >> idReceptor >> idInstituicao >> idDoacao;
        consumo_txt >> dia >> mes >> ano;
        dataConsumo->tm_mday = dia;
        dataConsumo->tm_mon = mes - 1;
        dataConsumo->tm_year = ano - 1900;
        dataConsumo->tm_hour = 0;
        dataConsumo->tm_min = 0;
        dataConsumo->tm_sec = 0;
        consumo_txt >> aux;

        Banco::_instance->setConsumo((new Consumo(idConsumo, idReceptor, idInstituicao, idDoacao, dataConsumo)));
    }

    consumo_txt.close();
}

void Banco::leArquivoInstituicao()
{
    std::ifstream instituicao_txt("instituicao.txt");
    
    if(instituicao_txt.tellg() != -1)
        while (!instituicao_txt.eof())
    {
        int idInstituicao;
        std::string nome, endereco, cnpj, senha;

        std::string aux;

        instituicao_txt >> idInstituicao;
        std::getline(instituicao_txt, nome);
        std::getline(instituicao_txt, endereco);
        instituicao_txt >> cnpj;
        std::getline(instituicao_txt, senha);
        instituicao_txt >> aux;

        Banco::_instance->setInstituicao((new Instituicao(idInstituicao, nome, endereco, cnpj, senha)));
    }

    instituicao_txt.close();
}

void Banco::fechaArquivoDoador()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _doadores.size(); i++)
    {
        resposta.push_back(std::to_string(_doadores[i]->get_id()));
        resposta.push_back(_doadores[i]->get_nome());
        resposta.push_back(_doadores[i]->get_cpf());
        resposta.push_back(std::to_string(_doadores[i]->get_dataNascimento()->tm_mday));
        resposta.push_back(std::to_string(_doadores[i]->get_dataNascimento()->tm_mon));
        resposta.push_back(std::to_string(_doadores[i]->get_dataNascimento()->tm_year));
        resposta.push_back(std::to_string(_doadores[i]->get_peso()));
        resposta.push_back(std::to_string(_doadores[i]->get_altura()));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_mday));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_mon));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_year));
        resposta.push_back(std::to_string(_doadores[i]->get_sangue()));
        resposta.push_back("------------------------------");
    }

    std::ofstream doador_txt("doador.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            doador_txt << resposta[i];
        else
            doador_txt << resposta[i] << std::endl;

    doador_txt.close();
}

void Banco::fechaArquivoReceptor()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _receptores.size(); i++)
    {
        resposta.push_back(std::to_string(_receptores[i]->get_id()));
        resposta.push_back(_receptores[i]->get_nome());
        resposta.push_back(_receptores[i]->get_cpf());
        resposta.push_back(std::to_string(_receptores[i]->get_dataNascimento()->tm_mday));
        resposta.push_back(std::to_string(_receptores[i]->get_dataNascimento()->tm_mon));
        resposta.push_back(std::to_string(_receptores[i]->get_dataNascimento()->tm_year));
        resposta.push_back(std::to_string(_receptores[i]->get_sangue()));
        resposta.push_back("------------------------------");
    }

    std::ofstream receptor_txt("receptor.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            receptor_txt << resposta[i];
        else
            receptor_txt << resposta[i] << std::endl;

    receptor_txt.close();
}

void Banco::fechaArquivoProfissional()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _profissionais.size(); i++)
    {
        resposta.push_back(std::to_string(_profissionais[i]->get_id()));
        resposta.push_back(_profissionais[i]->get_nome());
        resposta.push_back(_profissionais[i]->get_cpf());
        resposta.push_back(std::to_string(_profissionais[i]->get_dataNascimento()->tm_mday));
        resposta.push_back(std::to_string(_profissionais[i]->get_dataNascimento()->tm_mon));
        resposta.push_back(std::to_string(_profissionais[i]->get_dataNascimento()->tm_year));
        resposta.push_back(_profissionais[i]->get_senha());
        resposta.push_back(std::to_string(_profissionais[i]->get_cargo()));
        resposta.push_back(std::to_string(_profissionais[i]->get_idInstituicao()));
        resposta.push_back("------------------------------");
    }

    std::ofstream profissional_txt("profissional.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            profissional_txt << resposta[i];
        else
            profissional_txt << resposta[i] << std::endl;

    profissional_txt.close();
}

void Banco::fechaArquivoDoacao()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _doacao.size(); i++)
    {
        resposta.push_back(std::to_string(_doacao[i]->get_id()));
        resposta.push_back(std::to_string(_doacao[i]->getDataColeta()->tm_mday));
        resposta.push_back(std::to_string(_doacao[i]->getDataColeta()->tm_mon));
        resposta.push_back(std::to_string(_doacao[i]->getDataColeta()->tm_year));
        resposta.push_back(std::to_string(_doacao[i]->getQuantidade()));
        resposta.push_back(std::to_string(_doacao[i]->getInstituicao()));
        resposta.push_back(std::to_string(_doacao[i]->getProfissional()));
        resposta.push_back(std::to_string(_doacao[i]->getDoador()));
        resposta.push_back(std::to_string(_doacao[i]->getSituacao()));
        resposta.push_back("------------------------------");
    }

    std::ofstream doacao_txt("doacao.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            doacao_txt << resposta[i];
        else
            doacao_txt << resposta[i] << std::endl;

    doacao_txt.close();
}

void Banco::fechaArquivoConsumo()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _consumo.size(); i++)
    {
        resposta.push_back(std::to_string(_consumo[i]->get_id()));
        resposta.push_back(std::to_string(_consumo[i]->get_idReceptor()));
        resposta.push_back(std::to_string(_consumo[i]->get_idInstituicao()));
        resposta.push_back(std::to_string(_consumo[i]->get_idDoacao()));
        resposta.push_back(std::to_string(_consumo[i]->getData()->tm_mday));
        resposta.push_back(std::to_string(_consumo[i]->getData()->tm_mon));
        resposta.push_back(std::to_string(_consumo[i]->getData()->tm_year));
        resposta.push_back("------------------------------");
    }

    std::ofstream consumo_txt("consumo.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            consumo_txt << resposta[i];
        else
            consumo_txt << resposta[i] << std::endl;

    consumo_txt.close();
}

void Banco::fechaArquivoInstituicao()
{
    std::vector<std::string> resposta;

    for (int i = 0; i < _instituicao.size(); i++)
    {
        resposta.push_back(std::to_string(_instituicao[i]->get_id()));
        resposta.push_back(_instituicao[i]->get_nome());
        resposta.push_back(_instituicao[i]->get_endereco());
        resposta.push_back(_instituicao[i]->get_cnpj());
        resposta.push_back(_instituicao[i]->get_senha());
        resposta.push_back("------------------------------");
    }

    std::ofstream instituicao_txt("instituicao.txt");

    for (int i = 0; i < resposta.size(); i++)
        if (i == resposta.size() - 1)
            instituicao_txt << resposta[i];
        else
            instituicao_txt << resposta[i] << std::endl;

    instituicao_txt.close();
}

Banco::~Banco()
{
}

void Banco::setReceptor(Receptor *receptor)
{
    _receptores.push_back(receptor);
}

void Banco::setDoador(Doador *doador)
{
    _doadores.push_back(doador);
}

void Banco::setProfissional(ProfissionalSaude *profissional)
{
    _profissionais.push_back(profissional);
}

void Banco::setConsumo(Consumo *consumo)
{
    _consumo.push_back(consumo);
}

void Banco::setDoacao(Doacao *doacao)
{
    _doacao.push_back(doacao);
}

void Banco::setInstituicao(Instituicao *instituicao)
{
    _instituicao.push_back(instituicao);
}

Receptor *Banco::getReceptorById(int id)
{
   for (int i = 0; i < _receptores.size(); i++)
   {
        if(_receptores[i]->get_id() == id)
            return _receptores[i];
   }
   return nullptr;
}

Doador *Banco::getDoadorById(int id)
{
    return nullptr;
}

ProfissionalSaude *Banco::getProfissionalById(int id)
{
    return nullptr;
}

Consumo *Banco::getConsumoById(int id)
{
    return nullptr;
}

Instituicao *Banco::getInstituicaoById(int id)
{
    return nullptr;
}

ProfissionalSaude *Banco::isProfissional(std::string cpf)
{
    return nullptr;
}

Doador *Banco::isDoador(std::string cpf)
{
    return nullptr;
}

Receptor *Banco::isReceptor(std::string cpf)
{
    return nullptr;
}

Instituicao *Banco::isInstituicao(std::string cnpj)
{
    return nullptr;
}

std::vector<Doacao> Banco::getDoacoesCompativeis(int idSangue)
{
    return {};
}

bool Banco::isCpf(std::string palavra)
{
    int aux = 10;
    int num;
    int soma = 0;

    for (int i = 0; i < 9; i++)
    {
        num = palavra[i] - '0';
        soma += (num * aux);
        aux--;
    }

    int dig1, dig2;

    dig1 = soma % 11;
    dig1 = 11 - dig1;

    if (dig1 >= 10)
        dig1 = 0;

    aux = 11;
    soma = 0;

    for (int i = 0; i < 9; i++)
    {
        num = palavra[i] - '0';
        soma += (num * aux);
        aux--;
    }

    soma += dig1 * 2;

    dig2 = soma % 11;
    dig2 = 11 - dig2;

    if (dig2 >= 10)
        dig2 = 0;

    std::string cpfaux = palavra.substr(0, 9);
    cpfaux += std::to_string(dig1);
    cpfaux += std::to_string(dig2);

    if (palavra != cpfaux)
        return false;
    else
        return true;
}

bool Banco::isCnpj(std::string palavra)
{
    return true;
}

void Banco::cadastrarProfissional(ProfissionalSaude *profissional)
{
    _profissionais.push_back(profissional);
}