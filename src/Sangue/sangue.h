#ifndef SANGUE_H
#define SANGUE_H

#include <string>
#include <vector>

enum Rh
{
    POSITIVO,
    NEGATIVO
};

class Sangue
{
private:
    static std::vector<Sangue*> _instance;
    static int _numSangue;
    int _id;
    std::string _nome;
    Rh _rhTipo;
    std::vector<int> _receptores;
    std::vector<int> _doadores;

    Sangue(std::string nome, Rh Rh_do_sangue);

public:

    Sangue();
    ~Sangue();
    //std::vector<Sangue> getInstance();

    std::string get_nome();
    Rh get_rh_sangue();
    int get_id();
    Sangue get_sangue_by_id(int id);
    std::vector<int> get_receptores();
    std::vector<int> get_doadores();

    bool isReceptor(int id);
    bool isDoador(int id);

    void set_receptores(int id);
    void set_doadores(int id);

};

#endif