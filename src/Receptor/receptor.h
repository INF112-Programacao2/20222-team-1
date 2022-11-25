#ifndef RECEPTOR_H
#define RECEPTOR_H

#include "./Pessoa/pessoaIF.h";
#include <ctime>

class Receptor : public PessoaIF
{
private:
    static int numReceptor;
    int _idSangue;

public:
    Receptor(std::string nome, std::string numIdentidade, struct tm dataNascimento, int idSangue);
    ~Receptor();

    virtual int getPessoaById(int id) const;
    virtual int get_id();
    virtual std::string get_nome();
    virtual std::string get_numIdentidade();
    virtual struct tm get_dataNascimento();
    int get_idSangue() const;

    virtual void set_nome(std::string nome);
};

#endif