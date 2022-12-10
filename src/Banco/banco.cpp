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

Banco Banco::*_instance = nullptr;

Banco::Banco(){
    //abrir os arquivos e repassar para os vetores
    //caso de sangue e especial
}

//verificar se ja existe 
Banco* Banco::getInstance(){
    if( Banco::_instance != nullptr){
        return Banco::_instance;
    }else{
        Banco();
    }
}