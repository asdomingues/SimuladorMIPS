#include "include/IFID.hpp"


IFID::IFID(){
	npc=0;
	ir =  "";
}

int IFID::getNPC(){
	return npc;
}

string IFID::getIR(){
	return ir;
}

void IFID::setNPC(int npc){
	this->npc=npc;
}

void IFID::setIR(string ir){
	this->ir = ir;
}
