#include <iostream>
#include <ctime>
#include "../Pessoa/pessoaIF.h"
#include "Doador.h"

int Doador::_numDoador = 0;

Doador::Doador(std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue)
{
    _id = _numDoador;
    _numDoador ++;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _peso = peso;
    _altura = altura;
    _dataUltimaDoacao = dataUltimaDoacao;
    _idSangue = idSangue;
}

Doador::Doador(int id,std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue)
{
    _id = id;
    _nome = nome;
    _cpf = cpf;
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

std::string Doador::get_cpf()
{
    return _cpf;
}

struct tm *Doador::get_dataNascimento()
{
    return _dataNascimento;
}

int Doador::get_sangue() const
{
    return _idSangue;
}

double Doador::get_altura()
{
    return _altura;
}

double Doador::get_peso()
{
    return _peso;
}

void Doador::set_nome(std::string nome)
{
    _nome = nome;
}

void Doador::set_static(int n){
    Doador::_numDoador = n;
}

int Doador::get_id()
{
    return _id;
}

void Doador::set_altura(double altura)
{
    _altura = altura;
}

void Doador::set_peso(double peso)
{
    _peso = peso;
}

void Doador::set_sangue(int id)
{
    _idSangue = id;
}

void Doador::set_data(struct tm *dataUltimaDoacao)
{
    _dataUltimaDoacao = dataUltimaDoacao;
}
struct tm *Doador::get_dataUltimaDoacao()
{
    return _dataUltimaDoacao;
}

bool Doador::is_apto()
{
    return true;
}

Doador::~Doador()
{
}
