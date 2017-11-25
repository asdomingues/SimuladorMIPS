#include "Memoria.hpp"

using namespace std;
Memoria::Memoria(){
	address = 0;
	w_data = 0;
	for(int i = 0; i < TAM; i++)
		dados[i] = 0;
}

// TODO tratar end > size
void Memoria::set_address(int val){
	val /= 4;
	address = val % TAM;
}

int Memoria::read(){
	return dados[address];
}

void Memoria::set_wdata(int val){
	w_data = val;
}

void Memoria::write(){
	dados[address] = w_data % TAM;
}
