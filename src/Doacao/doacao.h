#ifndef DOACAO_H
#define DOACAO_H

#include <ctime>
#include "../Instituicao/instituicao.h"
#include "../Pessoa/pessoaIF.h"
#include "../Doador/Doador.h"

class Doacao
{
private:
    int _id;
    int _idInstituicao;

    struct tm _dataColeta;
    struct tm _dataValidade;
    double _quantidade;
    bool _situacao;

public:
    Doacao(struct tm dataColeta, struct tm dataValidade, double quantidade);
    void setDataColeta(struct tm dataColeta);
    void setValidade(struct tm dataValidade);
    void setQuantidade(double quantidade);
    void setSituacao(bool situacao);

    struct tm getDataColeta();
    struct tm getDataValidade();
    double getQuantidade();
    bool getSituacao();

    ~Doacao();
};

#endif