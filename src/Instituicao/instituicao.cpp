#include <string>
#include <vector>
#include <iostream>

#include "instituicao.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Banco/Banco.h"

Banco *binstituicao = new Banco();

int Instituicao::_numInstituicao = 0;

Instituicao::Instituicao(std::string nome, std::string endereco, std::string cnpj, std::string senha)
{
    _id = _numInstituicao;
    _numInstituicao++;
    _nome = nome;
    _endereco = endereco;
    _cnpj = cnpj;
    _senha = senha;
    _numInstituicao++;
}

Instituicao::Instituicao(int id, std::string nome, std::string endereco, std::string cnpj, std::string senha)
{
    _id = id;
    _nome = nome;
    _endereco = endereco;
    _cnpj = cnpj;
    _senha = senha;
    _numInstituicao++;
}

std::string Instituicao::get_nome()
{
    return _nome;
}

std::string Instituicao::get_senha()
{
    return _senha;
}
std::string Instituicao::get_endereco()
{
    return _endereco;
}

std::string Instituicao::get_cnpj()
{
    return _cnpj;
}

void Instituicao::set_nome(std::string nome)
{
    _nome = nome;
}

void Instituicao::set_static(int id)
{
    Instituicao::_numInstituicao = id;
}

void Instituicao::set_endereco(std::string endereco)
{
    _endereco = endereco;
}

int Instituicao::get_id()
{
    return _id;
}

void Instituicao::cadastrarProfissional(std::string nome, std::string cpf, struct tm *data, std::string senha, Cargo cargo)
{
    binstituicao->cadastrarProfissional(new ProfissionalSaude(nome, cpf, data, senha, cargo, _id));
}

Instituicao::~Instituicao() {
    delete binstituicao;
}
