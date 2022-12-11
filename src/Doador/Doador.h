#ifndef DOADOR_H
#define DOADOR_H

#include "../Pessoa/pessoaIF.h"
#include "../Doacao/doacao.h"
#include "../Sangue/sangue.h"
#include <ctime>

class Doador : public PessoaIF
{
private:
    static int _numDoador;
    double _peso;
    double _altura;
    struct tm _dataUltimaDoacao;
    int _idSangue;

public:
    Doador(std::string nome, std::string cpf, struct tm dataNascimento, double peso, double altura, struct tm dataUltimaDoacao, int idSangue);
    ~Doador();

    int getPessoaById(int id) const;
    int get_id();
    std::string get_nome();
    std::string get_cpf();
    struct tm get_dataNascimento();

    void set_nome(std::string nome);
    void setPeso(double peso);
    void setAltura(double altura);
    void setData(struct tm dataUltimaDoacao);
    void setSangue(int id);

    double getAltura();
    double getPeso();
    // Revisar esse retorno
    struct tm get_dataUltimaDoacao();
    int get_Sangue() const;

    bool isApto();
};

#endif