#ifndef PESSOA_IF_H
#define PESSOA_IF_H

#include <string>
#include <ctime>

class PessoaIF
{
protected:
    //static int _numPessoa ;
    int _id;
    std::string _nome;
    std::string _cpf;
    struct tm *_dataNascimento;

public:
   // ~PessoaIF(){};

    virtual int get_id() = 0;
    virtual std::string get_nome() = 0;
    virtual std::string get_cpf() = 0;
    virtual struct tm *get_dataNascimento() = 0;

    virtual void set_nome(std::string nome) = 0;
};

#endif