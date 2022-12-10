#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

class Banco
{
private:
    static Banco *_instance;
    vector<Doador*> _doadores;
    vector<Receptor*> _receptores;
    vector<ProfissionalSaude*> _profissionais;
    vector<Sangue*> _sangue;
    vector<Doacao*> _doacao;
    vector<Consumo*> _consumo;
    vector<Instituicao*> _instituicao;
    Banco();

public:
    Banco* getInstance();
    ~Banco();

    void setReceptor(Receptor* receptor);
    void setDoador(Doador* doador);
    void setProfissional(ProfissionalSaude* profissional);
    void setDoador(Doador* doador);
    void setConsumo(Consumo* consumxo);
    void setInstituicao(Instituicao* instituicao);

    Receptor* getReceptorById(int id);
    Doador* getDoadorById(int id);
    ProfissionalSaude* getProfissionalById(int id);
    Doador* getDoadorById(int id);
    Consumo* getConsumoById(int id);
    Instituicao* getInstituicaoById(int id);

    ProfissionalSaude* isProfissional(std::string cpf);
    Doador* isDoador(std::string cpf);
    Receptor* isReceptor(std::string cpf);

    vector<Doacoes> getDoacoesCompativeis(int idSangue);
};

#endif