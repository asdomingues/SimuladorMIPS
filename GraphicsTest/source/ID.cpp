#include "include/ID.hpp"
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

/**
 *Funcao auxiliar que divide uma string em um vetor de strings
 *  delimitador: delim
 */
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

/**
 * @brief ID::ID cria um
 * @param banco banco de registradores ja inicializado
 * @param ifid registrador intermediario - deve ser o mesmo de IF
 * @param idexe registrador intermediario - deve ser o mesmo de EX
 */
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
    npc=0;
	aluOP = "";
}


/**
 * @brief ID::controlSignals Decodifica instrucao contida em ir
 */
void ID::controlSignals(){
    //separa string pelos espacos
	vector<string> results;
	if(ir!="")
		results=split(ir,' ');
	else{
		results.resize(1);
		results.at(0)="nop";
	}
	
    //Descobre tipo de instrucao
    //de acordo com o tipo
    //gera sinais de controle

	if(results.at(0)=="add" || results.at(0)=="sub" || results.at(0)=="or" || results.at(0)=="and"){

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
				//gerar sinais
				aluOP = "";
				regDest=false;
				aluSrc=false;
				branch=false;
				memRead=false;
				memWrite=false;
				memToReg=false;
				regWrite=false;
				rt=rd=rs=imm=0;
			}
		}
	}

	
}

/**
 * @brief ID::writeSignals Escreve sinais de controle em IDEX
 */
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

/**
 * @brief ID::readIFID Realiza leitura de IFID
 */
void ID::readIFID(){
	npc = ifid->getNPC();
	ir = ifid->getIR();
}

/**
 * @brief ID::read_tick tick de leitura. Deve ser chamado apos write_tick.
 */
void ID::read_tick(){
	readIFID();	
}

/**
 * @brief ID::write_tick tick de escrita. Deve ser chamado antes de read_tick.
 */
void ID::write_tick(){

	controlSignals();
    //le registradores e salva em idex
	idexe->setA(banco->read_reg1(rs));
	idexe->setB(banco->read_reg1(rt));
	idexe->setImm(imm);
	idexe->setRD(rd);
	idexe->setRT(rt);
	idexe->setIR(ir);
	idexe->setNPC(npc);

	writeSignals();
	
}

void ID::setIFID(IFID *ifid){
	this->ifid=ifid;
}

void ID::setIDEXE(IDEXE *idexe){
	this->idexe=idexe;
}

/**
 * @brief ID::reset Retorna ID aos seus valores iniciais
 */
void ID::reset(){
    regDest = false;
    regWrite = false;
    aluSrc = false;
    branch = false;
    memRead = false;
    memWrite =  false;
    memToReg = false;
    rs=rt=rd=imm=0;
    npc=0;
    aluOP = "";
    banco->reset();
}

int ID::get_reg1(){
	return rs;
}

int ID::get_reg2(){
	return rt;
}
