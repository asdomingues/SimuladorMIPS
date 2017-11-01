#include "Registrador.hpp"

Registrador::Registrador(int nome){
    this->nome = nome;
}

int Registrador::get_nome(){
    return this->nome;
}
int Registrador::get_valor(){
    return this->valor;
}
void Registrador::set_valor(int valor){
    this->valor = valor % valor_max;
}
