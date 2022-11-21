#ifndef PESSOA_IF_H
#define PESSOA_IF_H

#include <string>
#include <vector>

class PessoaIF
{
protected:
    static int _numPessoa;
    int _id;
    std::string _nome;
    std::string _numIdentidade;
    int _dia;
    int _mes; // arrumar para o tipo data
    int _ano;

public:
    ~PessoaIF(){};

    virtual int getPessoaById() const = 0;
    virtual int get_id() = 0;
    virtual std::string get_nome() = 0;
    virtual std::string get_numIdentidade() = 0;
    virtual int get_dia() = 0;
    virtual int get_mes() = 0;
    virtual int get_ano() = 0;

    virtual int set_nome() = 0;
};

#endif