#include "MemoriaDados.hpp"

MemoriaDados::MemoriaDados(){
	address = 0;
	w_data = 0;
	for(int i = 0; i < TAM; i++)
		dados[i] = 0;
}

// TODO tratar end > size
void MemoriaDados::set_address(int val){
	val /= 4;
	address = val % TAM;
}

int MemoriaDados::read(){
	return dados[address];
}

void MemoriaDados::set_wdata(int val){
	w_data = val;
}

void MemoriaDados::write(){
	dados[address] = w_data;
}

int MemoriaDados::load_memory(string name){
	FILE *fp = fopen(name.c_str(), "r");
	int data, i;
	
	if(fp == NULL)
		return -1;

	for(i = 0; i < TAM && fscanf(fp, "%d", &data) > 0; i++)
		this->dados[i] = data;

	return i;
}
