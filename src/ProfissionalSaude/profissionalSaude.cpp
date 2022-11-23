#include <ctime>

#include "profissionalSaude.h"
#include "./Pessoa/pessoaIF.h"

ProfissionalSaude::ProfissionalSaude(std::string nome, std::string numIdentidade, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo, int idInstituicao)
{
    _nome = nome;
    _numIdentidade = numIdentidade;
    _dataNascimento.tm_mday = dia;
    _dataNascimento.tm_mon = mes - 1;
    _dataNascimento.tm_year = ano - 1900;
    _login = login;
    _senha = senha;
    _cargo = cargo;
    _idInstituicao = idInstituicao;
}
int ProfissionalSaude::getPessoaById(int id) const
{
}
int ProfissionalSaude::get_id()
{
    return _id;
}
std::string ProfissionalSaude::get_nome()
{
    return _nome;
}
std::string ProfissionalSaude::get_numIdentidade()
{
    return _numIdentidade;
}
time_t ProfissionalSaude::get_dataNascimento()
{
    return _dataNascimento;
}
std::string ProfissionalSaude::get_login()
{
    return _login;
}
std::string ProfissionalSaude::get_senha()
{
    return _senha;
}
std::string ProfissionalSaude::get_cargo()
{
    return _cargo;
}
int ProfissionalSaude::get_idInstituicao()
{
    return _idInstituicao;
}
void ProfissionalSaude::set_nome(std::string nome)
{
    _nome = nome;
}
void ProfissionalSaude::set_login(std::string login)
{
    _login = login;
}
void ProfissionalSaude::set_senha(std::string senha)
{
    _senha = senha;
}
void ProfissionalSaude::set_cargo(std::string cargo)
{
    _cargo = cargo;
}
ProfissionalSaude::~ProfissionalSaude()
{
}