#ifndef DOACAO_H
#define DOACAO_H

#include <ctime>
#include "../Instituicao/instituicao.h"
#include "../Pessoa/pessoaIF.h"
#include "../Doador/Doador.h"

class Doacao
{
private:
    static int _numDoacao;
    int _id;
    int _idInstituicao;
    int _idProfissional;
    int _idDoador;
    struct tm *_dataColeta;
    struct tm *_dataValidade;
    double _quantidade;
    bool _situacao;

public:
    Doacao(struct tm *dataColeta, double quantidade, int idInstituicao, int idProfissional, int idDoador);
    Doacao(int id, struct tm *dataColeta, double quantidade, int idInstituicao, int idProfissional, int idDoador, bool situacao);

    void set_data_coleta(struct tm *dataColeta);
    void set_quantidade(double quantidade);
    void set_situacao(bool situacao);
    void set_instituicao(int idInstituicao);
    void set_profissional(int idProfissional);
    void set_doador(int idDoador);
    void set_static(int n);

    struct tm *get_data_coleta();
    struct tm *get_data_validade();
    double get_quantidade();
    bool get_situacao();
    int get_instituicao();
    int get_profissional();
    int get_doador();
    int get_id();

    ~Doacao();
};

#endif