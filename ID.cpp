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
	vector<string> results = split(ir,' ');

	if(results.at(0)=="add" || results.at(0)=="sub" || results.at(0)=="or" || results.at(0)=="and"){
		cout << "encontrei tipo r\n";

		//gerar sinais
		aluOP = results.at(0);
		regDest=true;
		aluSrc=false;
		branch=false;
		memRead=false;
		memWrite=false;
		memToReg=false;
		regWrite=true;

		std::string output;
		for(size_t i = 0; i < results.at(1).size(); ++i)
		  if(results.at(1)[i]>='0' && results.at(1)[i]<='9') output += results.at(1)[i];

		//pegar rs, rt, rd
		rd = atoi(output.c_str());
		cout << rd;
		cout << "\n";

		output="";
		for(size_t i = 0; i < results.at(2).size(); ++i)
		  if(results.at(2)[i]>='0' && results.at(2)[i]<='9') output += results.at(2)[i];

		rs = atoi(output.c_str());
		cout << rs;
		cout << "\n";

		output="";
		for(size_t i = 0; i < results.at(3).size(); ++i)
		  if(results.at(3)[i]>='0' && results.at(3)[i]<='9') output += results.at(3)[i];

		rt = atoi(output.c_str());
		cout << rt;
		cout << "\n";
				
	}else{
		if(results.at(0)=="beq"){
			cout << "encontrei beq\n";

			//gerar sinais
			aluOP = "";
			regDest=false;
			aluSrc=false;
			branch=true;
			memRead=false;
			memWrite=false;
			memToReg=false;
			regWrite=false;

			std::string output;
			for(size_t i = 0; i < results.at(1).size(); ++i)
			  if(results.at(1)[i]>='0' && results.at(1)[i]<='9') output += results.at(1)[i];

			rs = atoi(output.c_str());
			cout << rs;
			cout << "\n";

			output="";
			for(size_t i = 0; i < results.at(2).size(); ++i)
			  if(results.at(2)[i]>='0' && results.at(2)[i]<='9') output += results.at(2)[i];

			rt = atoi(output.c_str());
			cout << rt;
			cout << "\n";

			imm = atoi(results.at(3).c_str());
			cout << imm;
			cout << "\n";

		}else{
			if(results.at(0)=="lw" || results.at(0)=="sw"){

			}else{
				//NOP
			}
		}
	}
	//find what type of instruction it is
		//according to type
		//generate signals
	//r type
	//add, sub, and, or

	//lw, sw

	//beq
	
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
		//get ir and npc from id/exe
		//generate new signals
		//read registers
	//escrever id/exe
	//ler if/id
	
	/*controlSignals();
	//read registers
	idexe->setA(banco->read_reg1(rs));
	idexe->setB(banco->read_reg1(rt));
	ideexe->setImm(imm);

	writeSignals();
	readIFID();	
*/
	readIFID();
	controlSignals();
}

void ID::setIFID(IFID *ifid){
	this->ifid=ifid;
}

void ID::setIDEXE(IDEXE *idexe){
	this->idexe=idexe;
}


int main(){
	string test = "beq $r1, $r2, 100";

	IFID ifid;
	IDEXE idexe;
	ID id(NULL, &ifid, &idexe);

	//id.setIDEXE(&idexe);
	//id.setIFID(&ifid);

	ifid.setIR(test);

	//id.readIFID();
	//id.controlSignals();
	id.tick();
//	id.tick();
	/*vector<string> results = split(test,' ');

	for(int i=0; i<results.size(); i++){
		cout << results.at(i);
		cout << "    ";
	}*/
	return 0;
}