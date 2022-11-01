#include <string>
#include <vector>

static enum Rh = (Rh positivo, Rh negativo);

class Sangue
{
private:
    static int _numSangue;
    char[3] _nome;
    Rh _Rh_do_sangue;
    int _id;
    vector<int> _receptores;
    vector<int> _doadores;

public:
    Sangue(char[3] nome, Rh Rh_do_sangue);
    ~Sangue();

    char[3] get_nome();
    Rh get_Rh_do_sangue();
    int get_id();
    vector<int> get_receptores();
    vector<int> get_doadores();

    bool isReceptor(int id);
    bool isDoador(int id);

    void set_receptores(int id);
    void set_doadores(int id);
};

