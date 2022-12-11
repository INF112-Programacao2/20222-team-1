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

// verificar se ja existe
Banco *Banco::getInstance()
{
    return nullptr;
}
void Banco::leArquivoDoador()
{
    std::ifstream doador_txt("doador.txt");

    while (!doador_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento;
        double peso, altura;
        struct tm *dataUltimaDoacao;
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

        _doadores.push_back(new Doador(idPessoa, nome, cpf, dataNascimento, peso, altura, dataUltimaDoacao, idSangue));
    }

    doador_txt.close();
}
void Banco::leArquivoReceptor()
{
    std::ifstream receptor_txt("receptor.txt");

    while (!receptor_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento;
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

        _receptores.push_back(new Receptor(idPessoa, nome, cpf, dataNascimento, idSangue));
    }

    receptor_txt.close();
}
void Banco::leArquivoProfissional()
{
    std::ifstream profissional_txt("profissional.txt");

    while (!profissional_txt.eof())
    {
        int idPessoa;
        std::string nome, cpf;
        struct tm *dataNascimento;
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
            _profissionais.push_back(new ProfissionalSaude(idPessoa, nome, cpf, dataNascimento, senha, Cargo::MEDICX, idInstituicao));
        else if (cargo == 1)
            _profissionais.push_back(new ProfissionalSaude(idPessoa, nome, cpf, dataNascimento, senha, Cargo::ENFERMEIRX, idInstituicao));
    }

    profissional_txt.close();
}
void Banco::leArquivoDoacao()
{
    std::ifstream doacao_txt("doacao.txt");

    while (!doacao_txt.eof())
    {
        int idDoacao;
        struct tm *dataColeta;
        double quantidade;
        int idInstituicao, idProfissional, idDoador;

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
        doacao_txt >> quantidade >> idInstituicao >> idProfissional >> idDoador >> aux;

        _doacao.push_back(new Doacao(idDoacao, dataColeta, quantidade, idInstituicao, idProfissional, idDoador));
    }

    doacao_txt.close();
}
void Banco::leArquivoConsumo()
{
    std::ifstream consumo_txt("consumo.txt");

    while (!consumo_txt.eof())
    {
        int idConsumo, idReceptor, idInstituicao, idDoacao;
        struct tm *dataConsumo;

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

        _consumo.push_back(new Consumo(idConsumo, idReceptor, idInstituicao, idDoacao, dataConsumo));
    }

    consumo_txt.close();
}
void Banco::leArquivoInstituicao()
{
    std::ifstream instituicao_txt("instituicao.txt");

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

        _instituicao.push_back(new Instituicao(idInstituicao, nome, endereco, cnpj, senha));
    }

    instituicao_txt.close();
}

Banco::~Banco()
{
}

void Banco::setReceptor(Receptor *receptor)
{
}
void Banco::setDoador(Doador *doador)
{
}
void Banco::setProfissional(ProfissionalSaude *profissional)
{
}
void Banco::setConsumo(Consumo *consumxo)
{
}
void Banco::setInstituicao(Instituicao *instituicao)
{
}

Receptor *Banco::getReceptorById(int id)
{
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
