#include "consumo.h"

int Consumo::_numConsumo = 0;

Consumo::Consumo(int idReceptor, int idInstituicao, int idDoacao, struct tm *dataConsumo)
{
    _id = _numConsumo;
    _numConsumo++;
    _idReceptor = idReceptor;
    _idInstituicao = idInstituicao;
    _idDoacao = idDoacao;
    _dataConsumo = dataConsumo;
}

Consumo::Consumo(int id, int idReceptor, int idInstituicao, int idDoacao, struct tm *dataConsumo)
{
    _id = id;
    _numConsumo++;
    _idReceptor = idReceptor;
    _idInstituicao = idInstituicao;
    _idDoacao = idDoacao;
    _dataConsumo = dataConsumo;
}

void Consumo::setData(struct tm *data)
{
    this->_dataConsumo = data;
}

void Consumo::setStatic(int id)
{
    Consumo::_numConsumo = id+1;
}


int Consumo::get_idDoacao() const
{
    return this->_idDoacao;
}

struct tm *Consumo::getData() const
{
    return this->_dataConsumo;
}

int Consumo::get_id()
{
    return this->_id;
}

int Consumo::get_idReceptor()
{
    return this->_idReceptor;
}

int Consumo::get_idInstituicao()
{
    return this->_idInstituicao;
}

Consumo::~Consumo()
{
}