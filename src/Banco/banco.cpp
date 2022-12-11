#include "Banco.h"
#include <vector>
#include "../Pessoa/pessoaIF.h"
#include "../Receptor/receptor.h"
#include "../Doador/Doador.h"
#include "../ProfissionalSaude/profissionalSaude.h"
#include "../Sangue/sangue.h"
#include "../Doacao/doacao.h"
#include "../Consumo/consumo.h"
#include "../Instituicao/instituicao.h"

Banco *Banco::_instance = nullptr;

Banco::Banco()
{
}

// verificar se ja existe
Banco *Banco::getInstance()
{
    return nullptr;
}

Banco::~Banco(){
    
}

void Banco::setReceptor(Receptor *receptor){

}
void Banco::setDoador(Doador *doador){

}
void Banco::setProfissional(ProfissionalSaude *profissional){

}
void Banco::setConsumo(Consumo *consumxo){

}
void Banco::setInstituicao(Instituicao *instituicao){

}

Receptor *Banco::getReceptorById(int id){
    return nullptr;
}
Doador *Banco::getDoadorById(int id){
    return nullptr;
}
ProfissionalSaude *Banco::getProfissionalById(int id){
    return nullptr;
}
Consumo *Banco::getConsumoById(int id){
    return nullptr;
}
Instituicao *Banco::getInstituicaoById(int id){
    return nullptr;
}

ProfissionalSaude *Banco::isProfissional(std::string cpf){
    return nullptr;
}
Doador *Banco::isDoador(std::string cpf){
    return nullptr;
}
Receptor *Banco::isReceptor(std::string cpf){
    return nullptr;
}
Instituicao *Banco::isInstituicao(std::string cnpj){
    return nullptr;
}

std::vector<Doacao> Banco::getDoacoesCompativeis(int idSangue){
    return {};
}

bool Banco::isCpf(std::string palavra){
    int aux = 10;
    int num;
    int soma = 0;

    for (int i = 0; i < 9; i++)
    {
        num = palavra[i] - '0';
        soma += (num * aux);
        aux--;
    }

    int dig1, dig2;

    dig1 = soma % 11;
    dig1 = 11 - dig1;

    if (dig1 >= 10)
        dig1 = 0;

    aux = 11;
    soma = 0;

    for (int i = 0; i < 9; i++)
    {
        num = palavra[i] - '0';
        soma += (num * aux);
        aux--;
    }

    soma += dig1 * 2;

    dig2 = soma % 11;
    dig2 = 11 - dig2;

    if (dig2 >= 10)
        dig2 = 0;

    std::string cpfaux = palavra.substr(0, 9);
    cpfaux += std::to_string(dig1);
    cpfaux += std::to_string(dig2);

    if (palavra != cpfaux)
        return false;
    else
        return true;
}
bool Banco::isCnpj(std::string palavra){
    return true;
}
