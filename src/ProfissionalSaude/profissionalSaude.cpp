#include <ctime>

#include "profissionalSaude.h"
#include "../Pessoa/pessoaIF.h"

int ProfissionalSaude::_numProfissional = 0;

ProfissionalSaude::ProfissionalSaude(std::string nome, std::string cpf, struct tm* dataNascimento, std::string senha, Cargo cargo, int idInstituicao)
{
    _id = _numProfissional;
    _numProfissional ++;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _senha = senha;
    _cargo = cargo;
    _idInstituicao = idInstituicao;
}

ProfissionalSaude::ProfissionalSaude(int id, std::string nome, std::string cpf, struct tm* dataNascimento, std::string senha, Cargo cargo, int idInstituicao)
{
    _id = id;
    _nome = nome;
    _cpf = cpf;
    _dataNascimento = dataNascimento;
    _senha = senha;
    _cargo = cargo;
    _idInstituicao = idInstituicao;
}

int ProfissionalSaude::get_id()
{
    return _id;
}
std::string ProfissionalSaude::get_nome()
{
    return _nome;
}
std::string ProfissionalSaude::get_cpf()
{
    return _cpf;
}
struct tm *ProfissionalSaude::get_dataNascimento()
{
    return _dataNascimento;
}
/*std::string ProfissionalSaude::get_login()
{
    return _login;
}*/
std::string ProfissionalSaude::get_senha()
{
    return _senha;
}
Cargo ProfissionalSaude::get_cargo()
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
void ProfissionalSaude::set_static(int n)
{
    ProfissionalSaude::_numProfissional = n;
}
void ProfissionalSaude::set_senha(std::string senha)
{
    _senha = senha;
}
void ProfissionalSaude::set_cargo(Cargo cargo)
{
    _cargo = cargo;
}
ProfissionalSaude::~ProfissionalSaude()
{
}
