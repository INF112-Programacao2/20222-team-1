#include <string>
#include <vector>

#include "./ProfissionalSaude/profissionalSaude.h"

class Instituicao{
private:
    static int _numInstituicao;
    std::string _nome;
    std::string _endereco;
    std::vector<vector<int> > _doacoes; //estoque

public:
    Instituicao(std::string, std::string);
    ~Instituicao();

    std::string get_nome();
    std::string get_endereco();
    vector<int>* getEstoqueByTipo();
    std::string set_nome();
    std::string set_endereco();
    
    
    ProfissionalSaude _newProfissional();
    Instituicao _newInstituicao();
};