#include <iostream>
#include <ctime>
#include "./Pessoa/pessoaIF.h"
#include "Doador.h"

Doador::Doador(std::string nome, std::string numIdentidade, struct tm dataNascimento, double peso, double altura, struct tm dataUltimaDoacao, int idSangue)
{
    _nome = nome;
    _numIdentidade = numIdentidade;
    _dataNascimento = dataNascimento;
    _peso = peso;
    _altura = altura;
    _dataUltimaDoacao = dataUltimaDoacao;
    _idSangue = idSangue;
}

std::string Doador::get_nome()
{
    return _nome;
}

std::string Doador::get_numIdentidade()
{
    return _numIdentidade;
}

struct tm Doador::get_dataNascimento()
{
    return _dataNascimento;
}

int Doador::get_Sangue() const
{
    return _idSangue;
}

double Doador::getAltura()
{
    return _altura;
}

double Doador::getPeso()
{
    return _peso;
}

void Doador::set_nome(std::string nome)
{
    _nome = nome;
}

int Doador::get_id()
{
    return _id;
}

int Doador::getDoadorById(int id) const
{
}

int Doador::getPessoaById(int id) const
{
}

void Doador::setAltura(double altura)
{
    _altura = altura;
}

void Doador::setPeso(double peso)
{
    _peso = peso;
}

void Doador::setSangue(int id)
{
    _idSangue = id;
}

void Doador::setData(struct tm dataUltimaDoacao)
{
    _dataUltimaDoacao = dataUltimaDoacao;
}

struct tm Doador::get_dataUltimaDoacao()
{
    return _dataUltimaDoacao;
}

bool Doador::isApto()
{
}

Doador::~Doador()
{
}
