#ifndef RECEPTOR_H
#define RECEPTOR_H

#include "../Pessoa/pessoaIF.h"
#include <ctime>

class Receptor : public PessoaIF
{
private:
    static int _numReceptor;
    int _id;
    int _idSangue;

public:
    Receptor(std::string nome, std::string cpf, struct tm *dataNascimento, int idSangue);
    Receptor(int id, std::string nome, std::string cpf, struct tm *dataNascimento, int idSangue);
    ~Receptor();

    int get_id();
    std::string get_nome();
    std::string get_cpf();
    struct tm *get_data_nascimento();
    int get_sangue() const;

    virtual void set_nome(std::string nome);
    int set_static(int n);
};

#endif