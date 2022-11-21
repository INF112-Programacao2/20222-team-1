#include <string>
#include <vector>

class Pessoa
{
private:
    static int _numPessoa;
    int _id
    std::string _nome;
    std::string _numIdentidade;
    int _dia;
    int _mes;       // arrumar para o tipo data 
    int _ano;

public:
    Pessoa(std::string nome, std::string numIdentidade, int dia, int mes, int ano);
    ~Pessoa() {};

    int getPessoaById() const = 0;
    int get_id() = 0;
    std::string get_nome() = 0;
    std::string get_numIdentidade() = 0;
    int get_dia() = 0;
    int get_mes() = 0;
    int get_ano() = 0;

    int set_nome() = 0;
};