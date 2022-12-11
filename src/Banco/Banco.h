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
    static Banco *_instance;
    std::vector<Doador *> _doadores;
    std::vector<Receptor *> _receptores;
    std::vector<ProfissionalSaude *> _profissionais;
    std::vector<Sangue *> _sangue;
    std::vector<Doacao *> _doacao;
    std::vector<Consumo *> _consumo;
    std::vector<Instituicao *> _instituicao;
    Banco();

public:
    Banco(int n);
    Banco *getInstance();
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

    std::vector<Doacao> getDoacoesCompativeis(int idSangue);

    void cadastrarProfissional(ProfissionalSaude *profissional);

    bool isCpf(std::string palavra);
    bool isCnpj(std::string palavra);
};

#endif
