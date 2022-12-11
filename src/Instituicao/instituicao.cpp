#include <string>
#include <vector>
#include <iostream>

#include "instituicao.h"
#include "../ProfissionalSaude/profissionalSaude.h"

int Instituicao::_numInstituicao = 0;

Instituicao::~Instituicao() {} 

Instituicao::Instituicao(std::string nome, std::string endereco) {
    _nome = nome;
    _endereco = endereco;

    _id = _numInstituicao; 
    _numInstituicao++;
}

std::string Instituicao::get_nome() {
    return _nome;
}

std::string Instituicao::get_endereco() {
    return _endereco;
}

void Instituicao::set_nome(std::string nome) {
    _nome = nome;
}

void  Instituicao::set_endereco(std::string endereco) {
    _endereco = endereco;
}

void Instituicao::cadastrarProfissional(std::string nome, std::string cpf, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo) {
ProfissionalSaude( nome, cpf, dia, mes, ano, senha, cargo, _id);
}
