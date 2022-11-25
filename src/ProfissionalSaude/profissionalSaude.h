#ifndef PROFISSIOANLSAUDE_H
#define PROFISSIOANLSAUDE_H

#include "./Pessoa/pessoaIF.h"

class ProfissionalSaude : public PessoaIF
{
private:
    static int _numProfissional;
    std::string _login;
    std::string _senha;
    std::string _cargo;
    int _idInstituicao;

public:
    ProfissionalSaude(std::string nome, std::string numIdentidade, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo, int idInstituicao);

    virtual int getPessoaById(int id) const;
    virtual int get_id();
    virtual std::string get_nome();
    virtual std::string get_numIdentidade();
    virtual struct tm get_dataNascimento();
    std::string get_login();
    std::string get_senha();
    std::string get_cargo();
    int get_idProfissional();
    int get_idInstituicao();

    virtual void set_nome(std::string nome);
    void set_login(std::string login);
    void set_senha(std::string senha);
    void set_cargo(std::string cargo);

    ~ProfissionalSaude();
};

#endif