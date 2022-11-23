#ifndef DOADOR_H
#define DOADOR_H

#include "./Pessoa/pessoaIF.h";
#include "./Doacao/doacao.h";
#include "./Sangue/sangue.h";
#include <ctime>

class Doador : public PessoaIF
{
private:
    static int _numDoador;
    double _peso;
    double _altura;
    time_t _dataUltimaDoacao;
    int _idSangue;

public:
    Doador(std::string nome, std::string numIdentidade, time_t dataNascimento, double peso, double altura, time_t dataUltimaDoacao, int idSangue);
    ~Doador();

    virtual int getPessoaById(int id) const;
    virtual int get_id();
    virtual std::string get_nome();
    virtual std::string get_numIdentidade();
    virtual time_t get_dataNascimento();

    virtual void set_nome(std::string nome);
    void setPeso(double peso);
    void setAltura(double altura);
    void setData(time_t dataUltimaDoacao);
    void setSangue(int id);

    int getDoadorById(int id) const;
    double getAltura();
    double getPeso();
    // Revisar esse retorno
    time_t get_dataUltimaDoacao();
    int get_Sangue() const;

    bool isApto();
};

#endif