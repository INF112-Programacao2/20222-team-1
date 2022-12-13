#include <iostream>
#include <ctime>
#include "../Pessoa/pessoaIF.h"
#include "Doador.h"

int Doador::_numDoador = 0;

Doador::Doador(std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue, Sexo sexo)
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
    _sexo = sexo;
}

Doador::Doador(int id,std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue, Sexo sexo)
{
    _id = id;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _peso = peso;
    _altura = altura;
    _dataUltimaDoacao = dataUltimaDoacao;
    _idSangue = idSangue;
    _sexo = sexo;
}

std::string Doador::get_nome()
{
    return _nome;
}

std::string Doador::get_cpf()
{
    return _cpf;
}
struct tm *Doador::get_data_nascimento()
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

Sexo Doador::get_sexo(){
    return _sexo;
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

void Doador::set_sexo(Sexo sexo){
    _sexo = sexo;
}
struct tm *Doador::get_data_ultima_doacao()
{
    return _dataUltimaDoacao;
}

bool Doador::is_apto()
{
    if (_peso < 50)
        return false;
    if ((_peso / (_altura * _altura)) < 18.5 || (_peso / (_altura * _altura)) > 25)
        return false;
    
    time_t idade18, idade60, idadeatual;
    idade18 = 567648000;
    idade60 = 1892160000;
    time(&idadeatual);
    idadeatual = difftime(idadeatual, mktime(_dataNascimento));

    if (idadeatual < idade18 || idadeatual > idade60)
        return false;

    if(_dataUltimaDoacao != nullptr){
    if(_sexo == Sexo::MASCULINO){
        time_t ultimadoacaoaux, now;
        ultimadoacaoaux = 7776000;
        now = difftime(time(&now), mktime(_dataUltimaDoacao));
    
        if(now < ultimadoacaoaux)
            return false;
    }
    if(_sexo == Sexo::FEMININO){
        time_t ultimadoacaoaux, now;
        ultimadoacaoaux = 10368000;
        now = difftime(time(&now), mktime(_dataUltimaDoacao));
    
        if(now < ultimadoacaoaux)
            return false;
    }}

    return true;
}

Doador::~Doador()
{
    delete _dataUltimaDoacao;
    delete _dataNascimento;
}
