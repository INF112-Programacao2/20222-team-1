#include <ctime>

#include "profissionalSaude.h"
#include "../Pessoa/pessoaIF.h"

ProfissionalSaude::ProfissionalSaude(std::string nome, std::string cpf, struct tm dataNascimento, std::string senha, std::string cargo, int idInstituicao)
{
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
struct tm ProfissionalSaude::get_dataNascimento()
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
