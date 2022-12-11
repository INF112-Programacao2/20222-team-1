#ifndef CONSUMO_H
#define CONSUMO_H

#include <ctime>

#include "../Doador/Doador.h"
#include "../Doacao/doacao.h"
#include "../Pessoa/pessoaIF.h"
#include "../Instituicao/instituicao.h"

class Consumo
{
private:
    static int _numConsumo;
    int _id;
    int _idReceptor;
    int _idInstituicao;
    int _idDoacao;
    struct tm *_dataConsumo;

public:
    Consumo(int idReceptor, int idInstituicao, int idDoacao, struct tm *dataConsumo);
    Consumo(int id, int idReceptor, int idInstituicao, int idDoacao, struct tm *dataConsumo);
    ~Consumo();
    int get_id();
    int get_idReceptor();
    int get_idInstituicao();
    void setData(struct tm *data);
    void setStatic(int n);
    int get_idDoacao() const;
    struct tm *getData() const;
};

#endif
