#ifndef CONSUMO_H

#include "./Doador/doador.h";
#include "./Doacao/doacao.h";
#include "./Pessoa/pessoa.h";
#include "./Instituicao/instituicao.h";

class Consumo{
    private:
        static int _numConsumo;
        int _id;
        int _idDoador;
        int _idDoacao;
        //date
        int _dia;
        int _mes;
        int _ano;
        std::string _local;

    public:
        Consumo();
        ~Consumo();
        Consumo getConsumoById(int n) const;
        void setDoador(int n);
        void setDoacao(int n);
        void setData(int dia, int mes, int ano);
        void setLocal(std::string local);
        int getDoador() const;
        int getDoacao() const;
        //Revisar esse retorno
        int getData();
        std::string getLocal();
}

#endif