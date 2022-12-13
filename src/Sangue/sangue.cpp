#include <iostream>
#include <vector>
#include "sangue.h"

int Sangue::_numSangue = 0; 
std::vector<Sangue*> Sangue::_instance = std::vector<Sangue*>();

Sangue::Sangue(){
    if(Sangue::_instance.size() == 0){
        Sangue::_instance.push_back(new Sangue("A", Rh::POSITIVO));
        Sangue::_instance.push_back(new Sangue("A", Rh::NEGATIVO));
        Sangue::_instance.push_back(new Sangue("B", Rh::POSITIVO));
        Sangue::_instance.push_back(new Sangue("B", Rh::NEGATIVO));
        Sangue::_instance.push_back(new Sangue("AB", Rh::POSITIVO));
        Sangue::_instance.push_back(new Sangue("AB", Rh::NEGATIVO));
        Sangue::_instance.push_back(new Sangue("O", Rh::POSITIVO));
        Sangue::_instance.push_back(new Sangue("O", Rh::NEGATIVO));
    }
}

Sangue::Sangue(std::string nome, Rh Rh_do_sangue){
    _nome = nome;
    _rhTipo = Rh_do_sangue;
    _id = _numSangue;
    _numSangue +=1;
}

Sangue:: ~Sangue(){

}
/*
std::vector<Sangue> Sangue::getInstance(){
    
}*/

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
    for(int i = 0; i < Sangue::_instance.size(); i++)
        if(Sangue::_instance[i]->get_id() == id)
            return *_instance[i];
    return {};
}

std::vector<int> Sangue::get_receptores(){
    return _receptores;
}

std::vector<int> Sangue::get_doadores(){
    return _doadores;
}

bool Sangue::isReceptor(int id){
    for(int i = 0; i < Sangue::_instance.size(); i++)
        if(_receptores[i] == id)
            return true;
    return false;
}

bool Sangue::isDoador(int id){
    for(int i = 0; i < Sangue::_instance.size(); i++)
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

