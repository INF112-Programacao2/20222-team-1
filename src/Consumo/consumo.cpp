#include "consumo.h"
#include "../Banco/Banco.h"

Banco* bconsumo;

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
    bconsumo->getDoacaoById(idDoacao)->set_situacao(false);
}

void Consumo::set_data(struct tm *data)
{
    this->_dataConsumo = data;
}

void Consumo::set_static(int id)
{
    Consumo::_numConsumo = id+1;
}


int Consumo::get_doacao() const
{
    return this->_idDoacao;
}

struct tm *Consumo::get_data() const
{
    return this->_dataConsumo;
}

int Consumo::get_id()
{
    return this->_id;
}

int Consumo::get_receptor()
{
    return this->_idReceptor;
}

int Consumo::get_instituicao()
{
    return this->_idInstituicao;
}

Consumo::~Consumo()
{
    delete bconsumo;
    delete _dataConsumo;
}