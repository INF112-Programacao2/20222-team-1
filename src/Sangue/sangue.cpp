#include <iostream>
#include <vector>
#include "sangue.h"

int Sangue::_numSangue = 0; 

Sangue::Sangue(std::string nome, Rh Rh_do_sangue){
    _nome = nome;
    _rhTipo = Rh_do_sangue;
    _id = _numSangue;
    _numSangue +=1;
}

Sangue:: ~Sangue(){

}

std::vector<Sangue> Sangue::getInstance(){
    if(_instance.size() == 0){
        _instance.push_back(Sangue("A", Rh::POSITIVO));
        _instance.push_back(Sangue("A", Rh::NEGATIVO));
        _instance.push_back(Sangue("B", Rh::POSITIVO));
        _instance.push_back(Sangue("B", Rh::NEGATIVO));
        _instance.push_back(Sangue("AB", Rh::POSITIVO));
        _instance.push_back(Sangue("AB", Rh::NEGATIVO));
        _instance.push_back(Sangue("O", Rh::POSITIVO));
        _instance.push_back(Sangue("O", Rh::NEGATIVO));
    }
    return _instance;
}

std::string Sangue::get_nome(){
    return _nome;
}

Rh Sangue::get_rh_sangue(){
    return _rhTipo;
}

int Sangue::get_id(){
    return _id;
}

Sangue Sangue::get_sangue_by_id(int id){
    for(int i = 0; i < _instance.size(); i++)
        if(_instance[i].get_id() == id)
            return _instance[i];
}

std::vector<int> Sangue::get_receptores(){
    return _receptores;
}

std::vector<int> Sangue::get_doadores(){
    return _doadores;
}

bool Sangue::isReceptor(int id){
    for(int i = 0; i < _instance.size(); i++)
        if(_receptores[i] == id)
            return true;
    return false;
}

bool Sangue::isDoador(int id){
    for(int i = 0; i < _instance.size(); i++)
        if(_doadores[i] == id)
            return true;
    return false;
}

void Sangue::set_receptores(int id){
    _receptores.push_back(id);
}

void Sangue::set_doadores(int id){
    _doadores.push_back(id);
}

