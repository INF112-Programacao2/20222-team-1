#include <string>
#include <vector>

class Pessoa
{
private:
    std::string _nome;
    std::string _numIdentidade;
    int _dia;
    int _mes;
    int _ano;

public:
    Pessoa(std::string nome, std::string numIdentidade, int dia, int mes, int ano);
    ~Pessoa();

    std::string get_nome();
    std::string get_numIdentidade() const;
    int get_dia();
    int get_mes();
    int get_ano();

    int set_nome();
};