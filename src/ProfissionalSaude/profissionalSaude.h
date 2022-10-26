#include <bits/stdc++.h>

#include "./Pessoa/pessoa.h"

class profissionalSaude : public Pessoa
{
private:
    static int _numProfissional;
    std::string _login;
    std::string _senha;
    std::string _cargo;
    int _idProfissional;
    int _idInstituicao;

public:
    profissionalSaude(std::string nome, std::string numIdentidade, int dia, int mes, int ano, std::string login, std::string senha, std::string cargo, int idProfissional, int idInstituicao);

    std::string get_login();
    std::string get_senha();
    std::string get_cargo();
    int get_idProfissional();
    int get_idInstituicao();

    std::string set_login();
    std::string set_senha();
    std::string set_cargo();

    ~profissionalSaude();
};