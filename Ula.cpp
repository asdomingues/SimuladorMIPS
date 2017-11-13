#include <iostream>
#include "Ula.hpp"

Ula::Ula(){}

//OBS: Para realizar o OR e o AND foi dividido um inteiro em potencias de 2 para tratar ele como se fosse um binario
int Ula::operation(){
	this->aluOUT = 0;
	if(aluOP == 0)//soma
		this->aluOUT = this->aluIN1 + this->aluIN2;
	if(aluOP == 1)//subtracao
		this->aluOUT = this->aluIN1 - this->aluIN2;
	if(aluOP == 2)//AND
		this->aluOUT = this->aluIN1 & this->aluIN2;
	if(aluOP == 3)//OR
		this->aluOUT = this->aluIN1 | this->aluIN2;
	return aluOUT;
}

void Ula::set_aluIN1(int valor){
	aluIN1 = valor;
}

void Ula::set_aluIN2(int valor){
	aluIN2 = valor;
}

void Ula::set_aluOP(int valor){
	aluOP = valor;
}



