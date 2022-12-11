#include "Banco.h"
#include <vector>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

Banco* Banco::_instance = nullptr;

Banco::Banco(){
    //inutil agora mas seria o povoamento do banco
    if( Banco::_instance == nullptr)
        new Banco();
}

//verificar se ja existe 
Banco* Banco::getInstance(){
    if( Banco::_instance != nullptr){
        return _instance;
    }
    
    return new Banco();
}