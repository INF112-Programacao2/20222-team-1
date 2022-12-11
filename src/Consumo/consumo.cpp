#include "consumo.h"

int Consumo::_numConsumo = 0;

Consumo::Consumo(int idReceptor, int idInstituicao, int idDoacao, struct tm dataConsumo)
{
    _id = _numConsumo;
    _numConsumo++;
    _idReceptor = idReceptor;
    _idInstituicao = idInstituicao;
    _idDoacao = idDoacao;
    _dataConsumo = dataConsumo;
}

void Consumo::setData(struct tm data)
{
    this->_dataConsumo = data;
}

int Consumo::getDoacao() const
{
    return this->_idDoacao;
}

struct tm Consumo::getData() const
{
    return this->_dataConsumo;
}

Consumo::~Consumo()
{
}