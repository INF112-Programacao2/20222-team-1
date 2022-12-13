#include <ctime>
#include "../Instituicao/instituicao.h"
#include "../Pessoa/pessoaIF.h"
#include "../Doador/Doador.h"

int Doacao::_numDoacao = 0;

Doacao::Doacao(struct tm *dataColeta, double quantidade, int idInstituicao, int idProfissional, int idDoador)
{
    _id = _numDoacao;
    _numDoacao++;
    _idInstituicao = idInstituicao;
    _idProfissional = idProfissional;
    _idDoador = idDoador;
    _dataColeta = dataColeta;
    _quantidade = quantidade;
    _idInstituicao = idInstituicao;
    _situacao = true;

    time_t auxValidade;

    auxValidade = mktime(_dataColeta) + 3024000;
    _dataValidade = localtime(&auxValidade);
}

Doacao::Doacao(int id, struct tm *dataColeta, double quantidade, int idInstituicao, int idProfissional, int idDoador, bool situacao)
{
    _id = id;
    _idInstituicao = idInstituicao;
    _idProfissional = idProfissional;
    _idDoador = idDoador;
    _dataColeta = dataColeta;
    _quantidade = quantidade;
    _idInstituicao = idInstituicao;
    _situacao = situacao;

    time_t auxValidade;

    auxValidade = mktime(_dataColeta) + 3024000;
    _dataValidade = localtime(&auxValidade);
}

void Doacao::set_data_coleta(struct tm *dataColeta)
{
    _dataColeta = dataColeta;
}

void Doacao::set_quantidade(double quantidade)
{
    _quantidade = quantidade;
}

void Doacao::set_situacao(bool situacao)
{
    _situacao = situacao;
}

void Doacao::set_static(int n)
{
    Doacao::_numDoacao = n;
}

void Doacao::set_instituicao(int idInstituicao)
{
    _idInstituicao = idInstituicao;
}

void Doacao::set_profissional(int idProfissional)
{
    _idProfissional = idProfissional;
}

void Doacao::set_doador(int idDoador)
{
    _idDoador = idDoador;
}

struct tm *Doacao::get_data_coleta()
{
    return _dataColeta;
}

struct tm *Doacao::get_data_validade()
{
    return _dataValidade;
}

double Doacao::get_quantidade()
{
    return _quantidade;
}

bool Doacao::get_situacao()
{
    return _situacao;
}

int Doacao::get_instituicao()
{
    return _idInstituicao;
}

int Doacao::get_profissional()
{
    return _idProfissional;
}

int Doacao::get_doador()
{
    return _idDoador;
}

int Doacao::get_id()
{
    return _id;
}

Doacao::~Doacao()
{
    delete _dataColeta;
    delete _dataValidade;
}
