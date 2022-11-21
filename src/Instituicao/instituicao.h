#ifndef INSTITUICAO_H
#define INSTITUICAO_H

#include <string>
#include <vector>

#include "./ProfissionalSaude/profissionalSaude.h"

class Instituicao
{
private:
    static int _numInstituicao;
    std::string _nome;
    std::string _endereco;
    std::vector<std::vector<int>> _doacoes; // estoque

public:
    Instituicao(std::string, std::string);
    ~Instituicao();

    std::string get_nome();
    std::string get_endereco();
    std::vector<int> *getEstoqueByTipo();
    std::string set_nome();
    std::string set_endereco();

    void _newProfissional(std::string nome, std::string numIdentidade, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo);
    Instituicao _newInstituicao();
};

#endif