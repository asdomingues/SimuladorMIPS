#include <iostream>
#include "include/Ula.hpp"

Ula::Ula(){}

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


