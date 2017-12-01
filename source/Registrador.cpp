#include "Registrador.hpp"

Registrador::Registrador(){
    this->nome = "R";
    valor = 0;
}

string Registrador::get_nome(){
    return this->nome;
}
int Registrador::get_valor(){
    return this->valor;
}
void Registrador::set_nome(string nome){
	this->nome = nome;
}
void Registrador::set_valor(int valor){
    this->valor = valor % VALOR_MAX;
}
