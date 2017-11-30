#include "ID.hpp"
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <stdlib.h>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

ID::ID(BancoDeRegistradores *banco, IFID *ifid, IDEXE *idexe){
	this->banco = banco;
	this->ifid = ifid;
	this->idexe = idexe;
	regDest = false;
	regWrite = false;
	aluSrc = false;
	branch = false;
	memRead = false;
	memWrite =  false;
	memToReg = false;
	rs=rt=rd=imm=0;
	aluOP = "";
}



void ID::controlSignals(){
	//separate string into parts
	vector<string> results;

	if(ir!="")
		results=split(ir,' ');
	else{
		results.resize(1);
		results.at(0)="nop";
	}
	

	//find what type of instruction it is
	//according to type
	//generate signals


	if(results.at(0)=="add" || results.at(0)=="sub" || results.at(0)=="or" || results.at(0)=="and"){
		//cout << "encontrei tipo r\n";

		//gerar sinais
		aluOP = results.at(0);
		regDest=true;
		aluSrc=false;
		branch=false;
		memRead=false;
		memWrite=false;
		memToReg=false;
		regWrite=true;
		imm=0;

		std::string output;
		for(size_t i = 0; i < results.at(1).size(); ++i)
		  if(results.at(1)[i]>='0' && results.at(1)[i]<='9') output += results.at(1)[i];

		//pegar rs, rt, rd
		rd = atoi(output.c_str());
	

		output="";
		for(size_t i = 0; i < results.at(2).size(); ++i)
		  if(results.at(2)[i]>='0' && results.at(2)[i]<='9') output += results.at(2)[i];

		rs = atoi(output.c_str());


		output="";
		for(size_t i = 0; i < results.at(3).size(); ++i)
		  if(results.at(3)[i]>='0' && results.at(3)[i]<='9') output += results.at(3)[i];

		rt = atoi(output.c_str());
				
	}else{
		if(results.at(0)=="beq"){
			//cout << "encontrei beq\n";

			//gerar sinais
			aluOP = "sub";
			regDest=false;
			aluSrc=false;
			branch=true;
			memRead=false;
			memWrite=false;
			memToReg=false;
			regWrite=false;
			rd=0;

			std::string output;
			for(size_t i = 0; i < results.at(1).size(); ++i)
			  if(results.at(1)[i]>='0' && results.at(1)[i]<='9') output += results.at(1)[i];

			rs = atoi(output.c_str());
			

			output="";
			for(size_t i = 0; i < results.at(2).size(); ++i)
			  if(results.at(2)[i]>='0' && results.at(2)[i]<='9') output += results.at(2)[i];

			rt = atoi(output.c_str());
		
			imm = atoi(results.at(3).c_str());

		}else{
			if(results.at(0)=="lw" || results.at(0)=="sw"){
				//cout<<"lw ou sw\n";

				rd=0;

				std::string output;
				for(size_t i = 0; i < results.at(1).size(); ++i)
				  if(results.at(1)[i]>='0' && results.at(1)[i]<='9') output += results.at(1)[i];

				rt = atoi(output.c_str());
		
				vector<string> aux = split(results.at(2),'(');
				imm = atoi(aux.at(0).c_str());

				output="";
				for(size_t i = 0; i < aux.at(1).size(); ++i)
				  if(aux.at(1)[i]>='0' && aux.at(1)[i]<='9') output += aux.at(1)[i];

				rs = atoi(output.c_str());

				aluOP = "add";
				if(results.at(0)=="lw"){
					regDest=false;
					aluSrc=true;
					branch=false;
					memRead=true;
					memWrite=false;
					memToReg=true;
					regWrite=true;
				}else{
					regDest=false;
					aluSrc=true;
					branch=false;
					memRead=false;
					memWrite=true;
					memToReg=false;
					regWrite=false;
				}
			}else{
				//NOP
				//cout << "NOP\n";
				//gerar sinais
				aluOP = "";
				regDest=true;
				aluSrc=false;
				branch=false;
				memRead=false;
				memWrite=false;
				memToReg=false;
				regWrite=true;
				rt=rd=rs=imm=0;
			}
		}
	}

	
}

void ID::writeSignals(){
	idexe->setRegDest (this->regDest);
	idexe->setRegWrite(this->regWrite);
	idexe->setAluSrc(this->aluSrc);
	idexe->setBranch(this->branch);
	idexe->setMemRead(this->memRead);
	idexe->setMemWrite(this->memWrite);
	idexe->setMemToReg(this->memToReg);
	idexe->setAluOP(this->aluOP);
}

void ID::readIFID(){
	npc = ifid->getNPC();
	ir = ifid->getIR();
}

void ID::tick(){

	//executar
		//generate new signals
		//read registers
	//escrever id/exe
	//ler if/id
	
	controlSignals();
	//read registers and save to id/exe

	idexe->setA(banco->read_reg1(rs));
	idexe->setB(banco->read_reg1(rt));
	idexe->setImm(imm);
	idexe->setRD(rd);
	idexe->setRT(rt);
	idexe->setIR(ir);
	idexe->setNPC(npc);

	writeSignals();
	readIFID();	
}

void ID::setIFID(IFID *ifid){
	this->ifid=ifid;
}

void ID::setIDEXE(IDEXE *idexe){
	this->idexe=idexe;
}

/*
int main(){
	string test = "lw $r1, 100($r2)";
	string test2 ="add $r3, $r2, $r1";

	IFID ifid;
	IDEXE idexe;
	BancoDeRegistradores banco(32);
	ID id(&banco, &ifid, &idexe);

	ifid.setIR(test);

	banco.set_wreg(2);
	banco.set_wdata(2);
	banco.reg_write();

	id.tick();
	cout << idexe.getA();
	cout << "\n";
	cout << idexe.getB();
	cout << "\n";
	cout << idexe.getImm();
	cout << "\n";
	id.tick();
	cout << idexe.getA();
	cout << "\n";
	cout << idexe.getB();
	cout << "\n";
	cout << idexe.getImm();
	cout << "\n";


	return 0;
}
*/
