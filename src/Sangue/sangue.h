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
    static int _numSangue;
    std::string _nome;
    Rh _Rh_do_sangue;
    int _id;
    std::vector<int> _receptores;
    std::vector<int> _doadores;

public:
    Sangue(std::string nome, Rh Rh_do_sangue);
    ~Sangue();

    std::string get_nome();
    Rh get_Rh_do_sangue();
    int get_id();
    std::vector<int> get_receptores();
    std::vector<int> get_doadores();

    bool isReceptor(int id);
    bool isDoador(int id);

    void set_receptores(int id);
    void set_doadores(int id);
};

#endif