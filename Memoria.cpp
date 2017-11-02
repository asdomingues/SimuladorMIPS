#include "Memoria.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
Memoria::Memoria(int size){
	this->dados = (int*) malloc(sizeof(int) * size);	
	this->size = size;
}

// TODO tratar end > size
void Memoria::set_endereco(int end){
	if(end > this->size){

	}
	this->end = end;
}

int Memoria::read(){
	return this->dados[this->end];
}

void Memoria::set_wdata(int dado){
	this->w_data = dado;
}

void Memoria::write(){
	this->dados[this->end] = this->w_data % VALOR_MAX;
}


int main(){
	Memoria m = Memoria(10);
	m.set_endereco(0);
	m.set_wdata(35);
	m.write();
	m.set_endereco(3);
	m.set_wdata(21);
	m.write();
	m.set_endereco(0);
	cout << m.read() << endl;
	m.set_endereco(3);
	cout << m.read() << endl;



}
