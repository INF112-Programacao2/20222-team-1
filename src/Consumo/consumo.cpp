#include "consumo.h"

Consumo::Consumo()
{
}

Consumo Consumo::getConsumoById(int n) const
{
    return Consumo();
}

void Consumo::setDoador(int n)
{
    this->_idDoador = n;
}

void Consumo::setDoacao(int n)
{
    this->_idDoacao = n;
}

void Consumo::setData(tm data)
{
    this->_dataConsumo = data;
}

void Consumo::setLocal(std::string local)
{
    this->_local = local;
}

int Consumo::getDoador() const
{
    return this->_idDoador;
}

int Consumo::getDoacao() const
{
    return this->_idDoacao;
}

tm Consumo::getData() const
{
    return this->_dataConsumo;
}

std::string Consumo::getLocal()
{
    return this->_local;
}

Consumo::~Consumo()
{
}