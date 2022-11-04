#include <ctime>
#include "./Instituicao/instituicao.h"
#include "./Pessoa/pessoa.h"
#include "./Doador/Doador.h"

enum Situacao
{
};

class Doacao
{
private:
    int _id;
    int _idInstituicao;

    time_t _dataColeta;
    time_t _dataValidade;
    double _quantidade;
    Situacao _situacao;

public:
    Doacao(time_t dataColeta, time_t dataValidade, double quantity, Situacao situacao) {}
    void setDataColeta(time_t dataColeta);
    void setValidade(time_t dataValidade);
    void setQuantidade(double quantidade);
    void setSituacao(Situacao situacao);

    time_t getDataColeta();
    time_t getDataValidade();
    double getQuantidade();
    Situacao getSituacao();

    ~Doacao();
};