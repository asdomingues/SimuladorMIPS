#include "Memoria.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
Memoria::Memoria(){
	adress = 0;
	w_data = 0;
	for(int i = 0; i < TAM; i++)
		dados[i] = 0;
}

// TODO tratar end > size
void Memoria::set_endereco(int val){
	val /= 4;
	addres = val % TAM;
}

int Memoria::read(){
	return dados[addres];
}

void Memoria::set_wdata(int val){
	w_data = val;
}

void Memoria::write(){
	dados[adress] = w_data % TAM;
}

