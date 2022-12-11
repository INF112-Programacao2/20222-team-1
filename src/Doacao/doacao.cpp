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

void Doacao::setDataColeta(struct tm *dataColeta)
{
    _dataColeta = dataColeta;
}
void Doacao::setQuantidade(double quantidade)
{
    _quantidade = quantidade;
}

void Doacao::setSituacao(bool situacao)
{
    _situacao = situacao;
}

void Doacao::setStatic(int n)
{
    Doacao::_numDoacao = n;
}

void Doacao::setInstituicao(int idInstituicao)
{
    _idInstituicao = idInstituicao;
}

void Doacao::setProfissional(int idProfissional)
{
    _idProfissional = idProfissional;
}

void Doacao::setDoador(int idDoador)
{
    _idDoador = idDoador;
}

struct tm *Doacao::getDataColeta()
{
    return _dataColeta;
}

struct tm *Doacao::getDataValidade()
{
    return _dataValidade;
}

double Doacao::getQuantidade()
{
    return _quantidade;
}

bool Doacao::getSituacao()
{
    return _situacao;
}

int Doacao::getInstituicao()
{
    return _idInstituicao;
}

int Doacao::getProfissional()
{
    return _idProfissional;
}

int Doacao::getDoador()
{
    return _idDoador;
}

Doacao::~Doacao()
{
}
