#include <iostream>
#include "receptor.h"
#include <ctime>
#include "../Pessoa/pessoaIF.h"

int Receptor::_numReceptor = 0;

Receptor::Receptor(std::string nome, std::string cpf, struct tm *dataNascimento, int idSangue)
{
    _id = _numReceptor;
    _numReceptor++;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _idSangue = idSangue;
}

Receptor::Receptor(int id, std::string nome, std::string cpf, struct tm *dataNascimento, int idSangue)
{
    _id = id;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _idSangue = idSangue;
}

int Receptor::set_static(int n){
    _numReceptor = n;
}

std::string Receptor::get_nome()
{
    return _nome;
}

std::string Receptor::get_cpf()
{
    return _cpf;
}

struct tm *Receptor::get_data_nascimento()
{
    return _dataNascimento;
}

int Receptor::get_sangue() const
{
    return _idSangue;
}

void Receptor::set_nome(std::string nome)
{
    _nome = nome;
}

int Receptor::get_id()
{
    return _id;
}

Receptor::~Receptor()
{
    delete _dataNascimento;
}