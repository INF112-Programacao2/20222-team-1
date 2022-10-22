#include <string> 
#include <vector>

class Pessoa{
private: 
    std::string _nome;
    std::string _numIdentidade;
    int _dia;
    int _mes;
    int _ano;
    
public: 
    Pessoa(std::string, std::string, int, int, int);
    ~Pessoa();

    std::string get_nome();
    std::string get_numIdentidade();
    int get_dia();
    int get_mes();
    int get_ano();
    
    int set_nome();
};