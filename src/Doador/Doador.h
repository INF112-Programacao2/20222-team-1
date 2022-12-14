#ifndef DOADOR_H
#define DOADOR_H

#include "../Pessoa/pessoaIF.h"
#include "../Doacao/doacao.h"
#include "../Sangue/sangue.h"
#include <ctime>

enum Sexo{
    MASCULINO,
    FEMININO,
};

class Doador : public PessoaIF
{
private:
    static int _numDoador;
    double _peso;
    double _altura;
    struct tm *_dataUltimaDoacao;
    int _idSangue;
    Sexo _sexo;

public:
    Doador(std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue, Sexo sexo);
    Doador(int id, std::string nome, std::string cpf, struct tm *dataNascimento, double peso, double altura, struct tm *dataUltimaDoacao, int idSangue, Sexo sexo);
    ~Doador();

    int get_id();
    std::string get_nome();
    std::string get_cpf();
    struct tm *get_data_nascimento();
    Sexo get_sexo();

    void set_nome(std::string nome);
    void set_peso(double peso);
    void set_altura(double altura);
    void set_data(struct tm *dataUltimaDoacao);
    void set_sangue(int id);
    void set_sexo(Sexo sexo);
    void set_static(int n);

    double get_altura();
    double get_peso();
    // Revisar esse retorno
    struct tm *get_data_ultima_doacao();
    int get_sangue() const;

    bool is_apto();
};

#endif