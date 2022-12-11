#ifndef PROFISSIOANLSAUDE_H
#define PROFISSIOANLSAUDE_H

#include "../Pessoa/pessoaIF.h"

enum Cargo{
    MEDICX,
    ENFERMEIRX,
};

class ProfissionalSaude : public PessoaIF
{
private:
    static int _numProfissional;
    //std::string _login;
    std::string _senha;
    Cargo _cargo;
    int _idInstituicao;

public:
    ProfissionalSaude(std::string nome, std::string cpf, struct tm *dataNascimento, std::string senha, Cargo cargo, int idInstituicao);
    ProfissionalSaude(int id,std::string nome, std::string cpf, struct tm *dataNascimento, std::string senha, Cargo cargo, int idInstituicao);

    int get_id();
    std::string get_cpf();
    struct tm *get_dataNascimento();
    //std::string get_login();
    std::string get_senha();
    std::string get_nome();
    Cargo get_cargo();
    int get_idProfissional();
    int get_idInstituicao();

    void set_nome(std::string nome);
    void set_static(int n);
    //void set_login(std::string login);
    void set_senha(std::string senha);
    void set_cargo(Cargo cargo);

    ~ProfissionalSaude();
};

#endif