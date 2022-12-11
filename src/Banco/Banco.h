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
    static Banco* _instance;
    std::vector<Doador*> _doadores;
    std::vector<Receptor*> _receptores;
    std::vector<ProfissionalSaude*> _profissionais;
    std::vector<Sangue*> _sangue;
    std::vector<Doacao*> _doacao;
    std::vector<Consumo*> _consumo;
    std::vector<Instituicao*> _instituicao;

public:
    Banco();
    Banco* getInstance();
    ~Banco();

    void setReceptor(Receptor* receptor);
    void setDoador(Doador* doador);
    void setProfissional(ProfissionalSaude* profissional);
    void setConsumo(Consumo* consumxo);
    void setInstituicao(Instituicao* instituicao);

    Receptor* getReceptorById(int id);
    Doador* getDoadorById(int id);
    ProfissionalSaude* getProfissionalById(int id);
    Consumo* getConsumoById(int id);
    Instituicao* getInstituicaoById(int id);

    ProfissionalSaude* isProfissional(std::string cpf);
    Doador* isDoador(std::string cpf);
    Receptor* isReceptor(std::string cpf);

    std::vector<Doacao> getDoacoesCompativeis(int idSangue);
};

#endif