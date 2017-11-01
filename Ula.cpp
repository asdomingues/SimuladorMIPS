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
	if(aluOP == 2){//AND
		this->aluOUT = this->aluIN1 & this->aluIN2;
		/*		for(int i = 0; i < NBITS; i++){
				int e = (int)pow(2, (double)i + 1);
				if(aluIN1 % e >= e / 2  && aluIN2 % e >= e / 2)
				aluOUT += (int)pow(2, (double)i);
				}*/
	}
	if(aluOP == 3){//OR
		this->aluOUT = this->aluIN1 | this->aluIN2;
/*		for(int i = 0; i < NBITS; i++){
			int e = (int)pow(2, (double)i + 1);//e = potencia de 2^(i+1)
			if(aluIN1 % e >= e / 2  || aluIN2 % e >= e / 2)
				aluOUT += (int)pow(2, (double)i);
		}*/
	}
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

//Sub rotina pra testar se o OR e o AND estao funcionando
int main(){
	Ula u;
	u.set_aluIN1(255);
	u.set_aluIN2(55);
	u.set_aluOP(3);
	std::cout << u.operation();
	u.set_aluIN1(255);
	u.set_aluIN2(55);
	u.set_aluOP(2);
	std::cout << u.operation();
}



