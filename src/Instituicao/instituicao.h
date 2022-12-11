#ifndef INSTITUICAO_H
#define INSTITUICAO_H

#include <string>
#include <vector>

#include "../ProfissionalSaude/profissionalSaude.h"


class Instituicao{
private:
    static int _numInstituicao;
    int _id;
    std::string _cnpj;
    std::string _nome;
    std::string _endereco;
    std::string _senha;

public:
    Instituicao(std::string nome, std::string endereco, std::string cnpj, std::string senha);
    Instituicao(int id, std::string nome, std::string endereco, std::string cnpj, std::string senha);
    ~Instituicao();

    std::string get_nome();
    std::string get_endereco();
    std::string get_cnpj();
    std::string get_senha();

    void set_nome(std::string nome);
    void set_endereco(std::string endereco);
    void set_senha(std::string senha);
    void set_static(int id);
    
    
    void cadastrarProfissional(std::string nome, std::string numIdentidade, struct tm *data, std::string senha, std::string cargo);
};

#endif