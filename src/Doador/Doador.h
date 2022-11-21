#ifndef DOADOR_H
#define DOADOR_H

#include "./Pessoa/pessoaIF.h";
#include "./Doacao/doacao.h";
#include "./Sangue/sangue.h";

class Doador : public Pessoa
{
private:
    static int _numDoador;
    int _id;
    int _peso;
    int _altura;
    int _dia;
    int _mes;
    int _ano;
    int _idSangue;

public:
    Doador();
    ~Doador();
    Doador getDoadorById(int n);
    void setPeso(int n);
    void setAltura(int n);
    void setData(int dia, int mes, int ano);
    void setSangue(int id);
    int getAltura();
    int getPeso();
    // Revisar esse retorno
    int getData();
    int getSangue() const;
    bool isApto();
};

#endif