#include "Registrador.hpp"
Registrador::Registrador(string nome){
    this->nome = nome;
    valor = 0;
}

string Registrador::get_nome(){
    return this->nome;
}
int Registrador::get_valor(){
    return this->valor;
}
void Registrador::set_valor(int valor){
    this->valor = valor % VALOR_MAX;
}
