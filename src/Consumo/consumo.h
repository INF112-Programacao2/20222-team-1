#ifndef CONSUMO_H
#define CONSUMO_H

#include <ctime>

#include "../Doador/doador.h"
#include "../Doacao/doacao.h"
#include "../Pessoa/pessoaIF.h"
#include "../Instituicao/instituicao.h"

class Consumo
{
private:
    static int _numConsumo;
    int _id;
    int _idDoador;
    int _idDoacao;
    tm _dataConsumo;
    std::string _local;

public:
    Consumo();
    ~Consumo();
    Consumo getConsumoById(int n) const;
    void setDoador(int n);
    void setDoacao(int n);
    void setData(tm data);
    void setLocal(std::string local);
    int getDoador() const;
    int getDoacao() const;
    tm getData() const;
    std::string getLocal();
};

#endif