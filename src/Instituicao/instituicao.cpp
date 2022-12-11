#include <string>
#include <vector>
#include <iostream>

#include "instituicao.h"
#include "../ProfissionalSaude/profissionalSaude.h"

int Instituicao::_numInstituicao = 0;

Instituicao::~Instituicao() {} 

Instituicao::Instituicao(std::string nome, std::string endereco, std::string cnpj, std::string senha) {
    _nome = nome;
    _endereco = endereco;
    _cnpj = cnpj;
    _senha = senha;

    _id = _numInstituicao; 
    _numInstituicao++;
}

std::string Instituicao::get_nome() {
    return _nome;
}

std::string Instituicao::get_endereco() {
    return _endereco;
}

std::string Instituicao::get_cnpj() {
    return _cnpj;
}

std::string Instituicao::get_senha() {
    return _senha;
}

void Instituicao::set_nome(std::string nome) {
    _nome = nome;
}

void Instituicao::set_senha(std::string senha) {
    _senha = senha;
}
void  Instituicao::set_endereco(std::string endereco) {
    _endereco = endereco;
}

void Instituicao::cadastrarProfissional(std::string nome, std::string cpf, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo) {
ProfissionalSaude( nome, cpf, dia, mes, ano, senha, cargo, _id);
}
