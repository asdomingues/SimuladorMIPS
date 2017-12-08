#include "include/Memoria.hpp"

Memoria::Memoria(){
	address = 0;
	w_data = 0;
	for(int i = 0; i < TAM; i++)
		dados[i] = 0;
}

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
	dados[address] = w_data;
}

int Memoria::load_memory(string name){
	FILE *fp = fopen(name.c_str(), "r");

	int data, i;
	
	if(fp == NULL)
		return -1;

    for(i = 0; i < TAM && fscanf(fp, "%d", &data) > 0; i++){
		this->dados[i] = data;
    }

    fclose(fp);

	return i;
}

void Memoria::reset(string name){
    this->load_memory(name);
}
