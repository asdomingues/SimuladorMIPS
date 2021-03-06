#include "include/Mux.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Mux::Mux(int size){
	this->tamanho = size;
    this->entradas = (int *) calloc(size, sizeof(int));
}

Mux::Mux(){
	this->tamanho = 2;
    this->entradas = (int *) calloc(2, sizeof(int));
}

void Mux::set_entrada(int entrada, int valor){
	if(entrada > this->tamanho)
		return;
	this->entradas[entrada] = valor;
}
int Mux::get_seletor(){
    return this->seletor;
}

int Mux::get_saida(int entrada){
	if(entrada > this->tamanho){
        return 0;
	}
    this->seletor=entrada;
	return this->entradas[entrada];
}
