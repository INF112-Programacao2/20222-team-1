#include <iostream>
#include "Banco.h"
#include <vector>
#include <fstream>
#include <filesystem>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/Doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

std::vector<Doador *> Banco::_doadores = std::vector<Doador *>();
std::vector<Receptor *> Banco::_receptores = std::vector<Receptor *>();
std::vector<ProfissionalSaude *> Banco::_profissionais = std::vector<ProfissionalSaude *>();
std::vector<Sangue *> Banco::_sangue = std::vector<Sangue *>();
std::vector<Doacao *> Banco::_doacao = std::vector<Doacao *>();
std::vector<Consumo *> Banco::_consumo = std::vector<Consumo *>();
std::vector<Instituicao *> Banco::_instituicao = std::vector<Instituicao *>();
ProfissionalSaude*Banco:: _puser = nullptr;
Instituicao* Banco::_iuser = nullptr;

Banco::Banco()
{
    if (Banco::_consumo.size() == 0)
        leArquivoConsumo();
    if (Banco::_doacao.size() == 0)
        leArquivoDoacao();
    if (Banco::_doadores.size() == 0)
        leArquivoDoador();
    if (Banco::_instituicao.size() == 0)
        leArquivoInstituicao();
    if (Banco::_profissionais.size() == 0)
        leArquivoProfissional();
    if (Banco::_receptores.size() == 0)
        leArquivoReceptor();
}

void Banco::leArquivoDoador()
{
    std::ifstream doador_txt("doador.txt");

    while (!doador_txt.eof())
    {
        std::string idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        double peso, altura;
        struct tm *dataUltimaDoacao = new struct tm;
        int idSangue, sexo;

        int dia, mes, ano;
        std::string aux;

        doador_txt >> idPessoa;
        if(idPessoa == "")
            break;
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
        doador_txt >> idSangue >> sexo;
        doador_txt >> aux;

        if (sexo == 0)
            setDoador((new Doador(stoi(idPessoa), nome, cpf, dataNascimento, peso, altura, dataUltimaDoacao, idSangue, Sexo::MASCULINO)));
        else if (sexo == 1)
            setDoador((new Doador(stoi(idPessoa), nome, cpf, dataNascimento, peso, altura, dataUltimaDoacao, idSangue, Sexo::FEMININO)));
        
        _doadores[0]->set_static(stoi(idPessoa)+1);
    }

    doador_txt.close();
}

void Banco::leArquivoReceptor()
{
    std::ifstream receptor_txt("receptor.txt");

    while (!receptor_txt.eof())
    {
        std::string idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        int idSangue;

        int dia, mes, ano;
        std::string aux;

        receptor_txt >> idPessoa;
        if(idPessoa == "")
            break;
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

        setReceptor((new Receptor(stoi(idPessoa), nome, cpf, dataNascimento, idSangue)));

        _receptores[0]->set_static(stoi(idPessoa)+1);
    }

    receptor_txt.close();
}

void Banco::leArquivoProfissional()
{
    std::ifstream profissional_txt("profissional.txt");

    while (!profissional_txt.eof())
    {
        std::string idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento = new struct tm;
        std::string senha;
        int cargo;
        int idInstituicao;

        int dia, mes, ano;
        std::string aux;

        profissional_txt >> idPessoa;
        if(idPessoa == "")
            break;
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
            setProfissional((new ProfissionalSaude(stoi(idPessoa), nome, cpf, dataNascimento, senha, Cargo::MEDICX, idInstituicao)));
        else if (cargo == 1)
            setProfissional((new ProfissionalSaude(stoi(idPessoa), nome, cpf, dataNascimento, senha, Cargo::ENFERMEIRX, idInstituicao)));

        _profissionais[0]->set_static(stoi(idPessoa)+1);
    }

    profissional_txt.close();
}

void Banco::leArquivoDoacao()
{
    std::ifstream doacao_txt("doacao.txt");
    
    while (!doacao_txt.eof())
    {
        std::string idDoacao;
        struct tm *dataColeta = new struct tm;
        double quantidade;
        int idInstituicao, idProfissional, idDoador;
        bool situacao;

        int dia, mes, ano;
        std::string aux;

        doacao_txt >> idDoacao;
        if(idDoacao == "")
            break;
        doacao_txt >> dia >> mes >> ano;
        dataColeta->tm_mday = dia;
        dataColeta->tm_mon = mes - 1;
        dataColeta->tm_year = ano - 1900;
        dataColeta->tm_hour = 0;
        dataColeta->tm_min = 0;
        dataColeta->tm_sec = 0;
        doacao_txt >> quantidade >> idInstituicao >> idProfissional >> idDoador >> situacao >> aux;

        setDoacao((new Doacao(stoi(idDoacao), dataColeta, quantidade, idInstituicao, idProfissional, idDoador, situacao)));

        _doacao[0]->setStatic(stoi(idDoacao)+1);
    }

    doacao_txt.close();
}

void Banco::leArquivoConsumo()
{
    std::ifstream consumo_txt("consumo.txt");
    
    while (!consumo_txt.eof())
    {
        std::string idConsumo;
        int idReceptor, idInstituicao, idDoacao;
        struct tm *dataConsumo = new struct tm;

        int dia, mes, ano;
        std::string aux;

        consumo_txt >> idConsumo;
        if(idConsumo == "")
            break;
        consumo_txt >> idReceptor >> idInstituicao >> idDoacao;
        consumo_txt >> dia >> mes >> ano;
        dataConsumo->tm_mday = dia;
        dataConsumo->tm_mon = mes - 1;
        dataConsumo->tm_year = ano - 1900;
        dataConsumo->tm_hour = 0;
        dataConsumo->tm_min = 0;
        dataConsumo->tm_sec = 0;
        consumo_txt >> aux;

        setConsumo((new Consumo(stoi(idConsumo), idReceptor, idInstituicao, idDoacao, dataConsumo)));

        _consumo[0]->setStatic(stoi(idConsumo)+1);
    }

    consumo_txt.close();
}

void Banco::leArquivoInstituicao()
{
    std::ifstream instituicao_txt("instituicao.txt");

    while (!instituicao_txt.eof())
    {
        std::string idInstituicao;
        std::string nome, endereco, cnpj, senha;

        std::string aux;

        instituicao_txt >> idInstituicao;
        if(idInstituicao == "")
            break;
        std::getline(instituicao_txt, nome);
        std::getline(instituicao_txt, endereco);
        instituicao_txt >> cnpj;
        std::getline(instituicao_txt, senha);
        instituicao_txt >> aux;

        setInstituicao((new Instituicao(stoi(idInstituicao), nome, endereco, cnpj, senha)));

        _instituicao[0]->set_static(stoi(idInstituicao)+1);
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
        resposta.push_back(std::to_string(_doadores[i]->get_dataNascimento()->tm_mon+1));
        resposta.push_back(std::to_string(_doadores[i]->get_dataNascimento()->tm_year+1900));
        resposta.push_back(std::to_string(_doadores[i]->get_peso()));
        resposta.push_back(std::to_string(_doadores[i]->get_altura()));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_mday));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_mon+1));
        resposta.push_back(std::to_string(_doadores[i]->get_dataUltimaDoacao()->tm_year+1900));
        resposta.push_back(std::to_string(_doadores[i]->get_sangue()));
        resposta.push_back(std::to_string(_doadores[i]->get_sexo()));
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
        resposta.push_back(std::to_string(_receptores[i]->get_dataNascimento()->tm_mon+1));
        resposta.push_back(std::to_string(_receptores[i]->get_dataNascimento()->tm_year+1900));
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
        resposta.push_back(std::to_string(_profissionais[i]->get_dataNascimento()->tm_mon+1));
        resposta.push_back(std::to_string(_profissionais[i]->get_dataNascimento()->tm_year+1900));
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
        resposta.push_back(std::to_string(_doacao[i]->getDataColeta()->tm_mon+1));
        resposta.push_back(std::to_string(_doacao[i]->getDataColeta()->tm_year+1900));
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
        resposta.push_back(std::to_string(_consumo[i]->getData()->tm_mon+1));
        resposta.push_back(std::to_string(_consumo[i]->getData()->tm_year+1900));
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
    fechaArquivoConsumo();
    fechaArquivoDoacao();
    fechaArquivoDoador();
    fechaArquivoInstituicao();
    fechaArquivoProfissional();
    fechaArquivoReceptor();
}

void Banco::setReceptor(Receptor *receptor)
{
    Banco::_receptores.push_back(receptor);
}

void Banco::setDoador(Doador *doador)
{
    Banco::_doadores.push_back(doador);
}

void Banco::setProfissional(ProfissionalSaude *profissional)
{
    Banco::_profissionais.push_back(profissional);
}

void Banco::setConsumo(Consumo *consumo)
{
    Banco::_consumo.push_back(consumo);
}

void Banco::setDoacao(Doacao *doacao)
{
    Banco::_doacao.push_back(doacao);
}

void Banco::setInstituicao(Instituicao *instituicao)
{
    Banco::_instituicao.push_back(instituicao);
}

Receptor *Banco::getReceptorById(int id)
{
    for (int i = 0; i < Banco::_receptores.size(); i++)
    {
        if (Banco::_receptores[i]->get_id() == id)
            return Banco::_receptores[i];
    }
    return nullptr;
}

Doador *Banco::getDoadorById(int id)
{
    for (int i = 0; i < _doadores.size(); i++)
    {
        if (Banco::_doadores[i]->get_id() == id)
            return Banco::_doadores[i];
    }
    return nullptr;
}

ProfissionalSaude *Banco::getProfissionalById(int id)
{
    for (int i = 0; i < Banco::_profissionais.size(); i++)
    {
        if (Banco::_profissionais[i]->get_id() == id)
            return Banco::_profissionais[i];
    }
    return nullptr;
}

Consumo *Banco::getConsumoById(int id)
{
    for (int i = 0; i < Banco::_consumo.size(); i++)
    {
        if (Banco::_consumo[i]->get_id() == id)
            return Banco::_consumo[i];
    }
    return nullptr;
}

Instituicao *Banco::getInstituicaoById(int id)
{
    for (int i = 0; i < Banco::_instituicao.size(); i++)
    {
        if (Banco::_instituicao[i]->get_id() == id)
            return Banco::_instituicao[i];
    }
    return nullptr;
}

ProfissionalSaude *Banco::isProfissional(std::string cpf)
{
    for (int i = 0; i < Banco::_profissionais.size(); i++)
    {
        if (Banco::_profissionais[i]->get_cpf() == cpf)
            return Banco::_profissionais[i];
    }
    return nullptr;
}

Doador *Banco::isDoador(std::string cpf)
{
    for (int i = 0; i < Banco::_doadores.size(); i++)
    {
        if (Banco::_doadores[i]->get_cpf() == cpf)
            return Banco::_doadores[i];
    }
    return nullptr;
}

Receptor *Banco::isReceptor(std::string cpf)
{
    for (int i = 0; i < Banco::_receptores.size(); i++)
    {
        if (Banco::_receptores[i]->get_cpf() == cpf)
            return Banco::_receptores[i];
    }
    return nullptr;
}

Instituicao *Banco::isInstituicao(std::string cnpj)
{
    for (int i = 0; i < Banco::_instituicao.size(); i++)
    {
        if (Banco::_instituicao[i]->get_cnpj() == cnpj)
            return Banco::_instituicao[i];
    }
    return nullptr;
}

void Banco::cadastrarProfissional(ProfissionalSaude *profissional)
{
    Banco::_profissionais.push_back(profissional);
}

std::vector<Doacao *> Banco::getDoacoesCompativeis(int idSangue)
{
    std::vector<Doacao *> compativeis;
    for (int i = 0; i < Banco::_doacao.size(); i++)
    {
        if (getDoadorById(Banco::_doacao[i]->getDoador())->get_sangue() == idSangue)
            compativeis.push_back(_doacao[i]);
    }
    return compativeis;
}

std::vector<Doador *> Banco::getDoadoresDisponiveis()
{
    std::vector<Doador *> disponiveis;
    for (int i = 0; i < Banco::_doadores.size(); i++)
    {
        if (Banco::_doadores[i]->is_apto())
            disponiveis.push_back(_doadores[i]);
    }
    return disponiveis;
}

std::vector<Doador*> Banco::getDoadoresByUser(){
    return _doadores;
}

std::vector<Receptor*> Banco::getReceptoresByUser(){
    return _receptores;
}

std::vector<ProfissionalSaude*> Banco::getProfissionaisByUser(){
    std::vector<ProfissionalSaude *> profissionais;
    int idInstituicao = 0;

    if(_puser != nullptr)
        idInstituicao = _puser->get_idInstituicao();
    else
        idInstituicao =_iuser->get_id();
    
    for (int i = 0; i < _profissionais.size(); i++)
    {
        if(_profissionais[i]->get_idInstituicao() == idInstituicao)
            profissionais.push_back(_profissionais[i]);
    }
    return profissionais;
}

std::vector<Doacao*> Banco::getDoacoesByUser(){
    std::vector<Doacao *> doacoes;
    int idInstituicao = 0;

    if(_puser != nullptr)
        idInstituicao = _puser->get_idInstituicao();
    else
        idInstituicao =_iuser->get_id();
    
    for (int i = 0; i < _doacao.size(); i++)
    {
        if(_doacao[i]->getInstituicao() == idInstituicao)
            doacoes.push_back(_doacao[i]);
    }
    return doacoes;
}

std::vector<Consumo*> Banco::getConsumosByUser(){
    std::vector<Consumo *> consumos;
    int idInstituicao = 0;

    if(_puser != nullptr)
        idInstituicao = _puser->get_idInstituicao();
    else
        idInstituicao =_iuser->get_id();
    
    for (int i = 0; i < _consumo.size(); i++)
    {
        if(_consumo[i]->get_idInstituicao() == idInstituicao)
            consumos.push_back(_consumo[i]);
    }
    return consumos;
}


bool Banco::isCpf(std::string palavra)
{
    int aux = 10;
    int num;
    int soma = 0;
    bool resp = false;

    if (palavra.size() != 14)
        return false;

    std::string substring = palavra.substr(0, 3) + palavra.substr(4, 3) + palavra.substr(8, 3) + palavra.substr(12, 2);
    palavra = substring;

    for (int i = 0; i < 10; i++)
        if (palavra[i] != palavra[i + 1])
        {
            resp = true;
            break;
        }

    if (resp)
    {

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
    else
    {
        return false;
    }
}

bool Banco::isCnpj(std::string palavra)
{
    int aux = 5;
    int num;
    int soma = 0;
    bool resp = false;

    if (palavra.size() != 18)
        return false;

    std::string substring = palavra.substr(0, 2) + palavra.substr(3, 3) + palavra.substr(7, 3) + palavra.substr(11, 4) + palavra.substr(16, 2);
    palavra = substring;

    for (int i = 0; i < 13; i++)
        if (palavra[i] != palavra[i + 1])
        {
            resp = true;
            break;
        }

    if (palavra[8] == '0' && palavra[9] == '0' && palavra[10] == '0' && (palavra[11] == '1' || palavra[11] == '2'))
        ;
    else
        resp = false;

    if (resp)
    {
        for (int i = 0; i < 12; i++)
        {
            num = palavra[i] - '0';
            soma += (num * aux);
            aux--;
            if (aux == 1)
                aux = 9;
        }

        int dig1, dig2;

        dig1 = 11 - (soma % 11);

        if (dig1 >= 10)
            dig1 = 0;

        aux = 6;
        soma = 0;

        for (int i = 0; i < 12; i++)
        {
            num = palavra[i] - '0';
            soma += (num * aux);
            aux--;
            if (aux == 1)
                aux = 9;
        }

        soma += dig1 * 2;

        dig2 = 11 - (soma % 11);

        if (dig2 >= 10)
            dig2 = 0;

        std::string cnpjaux = palavra.substr(0, 12);
        cnpjaux += std::to_string(dig1);
        cnpjaux += std::to_string(dig2);

        if (palavra != cnpjaux)
            return false;
        else
            return true;
    }
    else
        return false;
}
struct tm *Banco::criaStructTm(int dia, int mes, int ano)
{
    struct tm *tempoAux = new struct tm;

    tempoAux->tm_hour = 0;
    tempoAux->tm_min = 0;
    tempoAux->tm_sec = 0;
    tempoAux->tm_mday = dia;
    tempoAux->tm_mon = mes - 1;
    tempoAux->tm_year = ano - 1900;

    return tempoAux;
}

bool Banco::isNumber(std::string palavra){
    for(int i =0; i< palavra.size(); i++){
        if(!isdigit(palavra[i]))
               throw std::invalid_argument("/!\\O valor digitado nao e um numero. ");
    }
    return true;
}
