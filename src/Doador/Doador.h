
#include "./Pessoa/pessoa.h";
#include "./Doacao/doacao.h";
#include "./Sangue/sangue.h";

class Doador: private Pessoa{
    private:
        static int _numDoador;
        int _id;
        int _peso;
        int _altura;
        int _dia;
        int _mes;
        int _ano;
        int _tipoSangue;

    public:
        Doador();
        ~Doador();
        Doador getDoadorById(int n);
        void setPeso(int n);
        void setAltura(int n);
        void setData(int dia, int mes, int ano);
        void setSangue(int id);
        int getAltura();
        int getPeso();
        //Revisar esse retorno
        int getData();
        int getSangue();
        bool isApto();
}