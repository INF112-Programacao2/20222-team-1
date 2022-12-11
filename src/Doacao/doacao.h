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

    void setDataColeta(struct tm *dataColeta);
    void setQuantidade(double quantidade);
    void setSituacao(bool situacao);
    void setInstituicao(int idInstituicao);
    void setProfissional(int idProfissional);
    void setDoador(int idDoador);
    void setStatic(int n);

    struct tm *getDataColeta();
    struct tm *getDataValidade();
    double getQuantidade();
    bool getSituacao();
    int getInstituicao();
    int getProfissional();
    int getDoador();
    int get_id();

    ~Doacao();
};

#endif