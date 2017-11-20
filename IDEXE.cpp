	#include "IDEXE.hpp"



		IDEXE::IDEXE(){
			ir="";
			npc=0;
			rt=0;
			rd=0;
			regDest=false;
			regWrite=false;
			aluSrc=false;
			branch=false;
			memRead=false;
			memWrite=false;
			memToReg=false;
			ra=0;
			rb=0;
			aluOP="";
		}

		void IDEXE::setIR(string ir){
			this->ir=ir;
		}

		void IDEXE::setNPC(int npc){
			this->npc=npc;
		}

		string IDEXE::getIR(){
			return ir;
		}

		int IDEXE::getNPC(){
			return npc;
		}

		void IDEXE::setRegDest (bool regDest){
			this->regDest=regDest;
		}

		void IDEXE::setRegWrite(bool regWrite){
			this->regWrite=regWrite;
		}

		void IDEXE::setAluSrc(bool aluSrc){
			this->aluSrc=aluSrc;
		}

		void IDEXE::setBranch(bool branch){
			this->branch=branch;
		}

		void IDEXE::setMemRead(bool memRead){
			this->memRead=memRead;
		}

		void IDEXE::setMemWrite(bool memWrite){
			this->memWrite=memWrite;
		}

		void IDEXE::setMemToReg(bool memToReg){
			this->memToReg=memToReg;
		}

		void IDEXE::setAluOP(string aluOP){
			this->aluOP=aluOP;
		}

		void IDEXE::setA(int ra){
			this->ra=ra;
		}

		void IDEXE::setB(int rb){
			this->rb=rb;
		}

		void IDEXE::setRD(int rd){
			this->rd=rd;
		}

		void IDEXE::setRT (int rt){
			this->rt=rt;
		}

		void IDEXE::setImm (int imm){
			this->imm=imm;

		}

		int IDEXE::getImm (){
			return imm;
		}

		int IDEXE::getRD(){
			return rd;
		}

		int IDEXE::getRT(){
			return rt;
		}

		int IDEXE::getA(){
			return ra;
		}

		int IDEXE::getB(){
			return rb;
		}

		bool IDEXE::getRegDest(){
			return regDest;
		}

		bool IDEXE::getRegWrite(){
			return regWrite;
		}

		bool IDEXE::getAluSrc(){
			return aluSrc;
		}

		bool IDEXE::getBranch(){
			return branch;
		}

		bool IDEXE::getMemRead(){
			return memRead;
		}

		bool IDEXE::getMemWrite(){
			return memWrite;
		}

		bool IDEXE::getMemToReg(){
			return memToReg;
		}

		string IDEXE::getAluOP(){
			return aluOP;
		}