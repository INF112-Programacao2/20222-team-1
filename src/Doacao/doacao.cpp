#include <ctime>
#include "./Instituicao/instituicao.h"
#include "./Pessoa/pessoaIF.h"
#include "./Doador/doador.h"

Doacao::Doacao(struct tm dataColeta, struct tm dataValidade, double quantidade)
{
    _dataColeta = dataColeta;
    _dataValidade = dataValidade;
    _quantidade = quantidade;
    _situacao = true;
}
void Doacao::setDataColeta(struct tm dataColeta)
{
    _dataColeta = dataColeta;
}
void Doacao::setValidade(struct tm dataValidade)
{
    _dataValidade = dataValidade;
}
void Doacao::setQuantidade(double quantidade)
{
    _quantidade = quantidade;
}
void Doacao::setSituacao(bool situacao)
{
    _situacao = situacao;
}
struct tm Doacao::getDataColeta()
{
    return _dataColeta;
}
struct tm Doacao::getDataValidade()
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
Doacao::~Doacao()
{
}