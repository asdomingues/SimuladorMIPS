#include <iostream>
#include "Ula.hpp"

Ula::Ula(){}

//OBS: Para realizar o OR e o AND foi dividido um inteiro em potencias de 2 para tratar ele como se fosse um binario
int Ula::operation(){
	this->aluOUT = 0;
	if(aluOP == "add")//soma
		this->aluOUT = this->aluIN1 + this->aluIN2;
	if(aluOP == "sub")//subtracao
		this->aluOUT = this->aluIN1 - this->aluIN2;
	if(aluOP == "and")//AND
		this->aluOUT = this->aluIN1 & this->aluIN2;
	if(aluOP == "or")//OR
		this->aluOUT = this->aluIN1 | this->aluIN2;
	return aluOUT;
}

void Ula::set_aluIN1(int valor){
	aluIN1 = valor;
}

void Ula::set_aluIN2(int valor){
	aluIN2 = valor;
}

void Ula::set_aluOP(string valor){
	aluOP = valor;
}

int Ula::get_aluOUT(){
	return aluOUT;
}


