#include "include/BancoDeRegistradores.hpp"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

int BancoDeRegistradores::read_reg1(int reg){
	return this->banco[reg].get_valor();
}

string BancoDeRegistradores::get_name(int reg){
    return this->banco[reg].get_nome();
}

void BancoDeRegistradores::set_wreg(int reg){
	this->write_register = reg;
}

void BancoDeRegistradores::set_wdata(int data){
	this->write_data = data;
}
void BancoDeRegistradores::reg_write(){
	this->banco[this->write_register].set_valor(this->write_data);
}
BancoDeRegistradores::BancoDeRegistradores(int size){
	for(int i = 0; i < size; i++){
		stringstream ss;
		ss << i;		
		string s = "R" + ss.str();
		this->banco[i].set_nome(s);
	}
}

/*int main (){
	BancoDeRegistradores b(NREGISTRADORES);
	b.set_wreg(3);
	b.set_wdata(55);
	b.reg_write();
	b.read_reg1(3);
	std::cout << b.read_reg1(3); 
	}
*/
