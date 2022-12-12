#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/Doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

class Banco
{
private:
    //static Banco *_instance;
    static std::vector<Doador *> _doadores;
    static std::vector<Receptor *> _receptores;
    static std::vector<ProfissionalSaude *> _profissionais;
    static std::vector<Sangue *> _sangue;
    static std::vector<Doacao *> _doacao;
    static std::vector<Consumo *> _consumo;
    static std::vector<Instituicao *> _instituicao;

public:
    static ProfissionalSaude* _puser;
    static Instituicao* _iuser;

    Banco();
    void leArquivoDoador();
    void leArquivoReceptor();
    void leArquivoProfissional();
    void leArquivoDoacao();
    void leArquivoConsumo();
    void leArquivoInstituicao();
    void fechaArquivoDoador();
    void fechaArquivoReceptor();
    void fechaArquivoProfissional();
    void fechaArquivoDoacao();
    void fechaArquivoConsumo();
    void fechaArquivoInstituicao();
    ~Banco();

    void setReceptor(Receptor *receptor);
    void setDoador(Doador *doador);
    void setProfissional(ProfissionalSaude *profissional);
    void setConsumo(Consumo *consumo);
    void setDoacao(Doacao *doacao);
    void setInstituicao(Instituicao *instituicao);

    Receptor *getReceptorById(int id);
    Doador *getDoadorById(int id);
    ProfissionalSaude *getProfissionalById(int id);
    Consumo *getConsumoById(int id);
    Instituicao *getInstituicaoById(int id);

    ProfissionalSaude *isProfissional(std::string cpf);
    Doador *isDoador(std::string cpf);
    Receptor *isReceptor(std::string cpf);
    Instituicao *isInstituicao(std::string cnpj);

    std::vector<Doacao*> getDoacoesCompativeis(int idSangue);
    //filtrar disponiveis depois
    std::vector<Doador*> getDoadoresDisponiveis();
    
    std::vector<Doador*> getDoadoresByUser();
    std::vector<Receptor*> getReceptoresByUser();
    std::vector<ProfissionalSaude*> getProfissionaisByUser();
    std::vector<Doacao*> getDoacoesByUser();
    std::vector<Consumo*> getConsumosByUser();

    void cadastrarProfissional(ProfissionalSaude *profissional);

    bool isCpf(std::string palavra);
    bool isCnpj(std::string palavra);
    bool isNumber(std::string palavra);
    struct tm *criaStructTm(int dia, int mes, int ano);

};

#endif
