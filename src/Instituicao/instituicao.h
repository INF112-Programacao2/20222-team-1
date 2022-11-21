#ifndef INSTITUICAO_H
#define INSTITUICAO_H

#include <string>
#include <vector>

#include "../ProfissionalSaude/profissionalSaude.h"


class Instituicao{
private:
    static int _numInstituicao;
    int _id;
    std::string _nome;
    std::string _endereco;

public:
    Instituicao(std::string nome, std::string endereco);
    ~Instituicao();

    std::string get_nome();
    std::string get_endereco();

    void set_nome(std::string nome);
    void set_endereco(std::string endereco);
    
    
    void cadastrarProfissional(std::string nome, std::string numIdentidade, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo);
};

#endif