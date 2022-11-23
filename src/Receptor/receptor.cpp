#include <iostream>
#include "receptor.h"
#include <ctime>
#include "./Pessoa/pessoaIF.h";

Receptor::Receptor(std::string nome, std::string numIdentidade, time_t dataNascimento, int idSangue)
{
    _nome = nome;
    _numIdentidade = numIdentidade;
    _dataNascimento = dataNascimento;
    _idSangue = idSangue;
}

std::string Receptor::get_nome()
{
    return _nome;
}

std::string Receptor::get_numIdentidade()
{
    return _numIdentidade;
}

time_t Receptor::get_dataNascimento()
{
    return _dataNascimento;
}

int Receptor::get_idSangue() const
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

int Receptor::getPessoaById(int id) const
{
}

Receptor::~Receptor()
{
}