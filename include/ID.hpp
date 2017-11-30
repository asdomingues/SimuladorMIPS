#ifndef _ID_H_
#define _ID_H_

#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "IDEXE.hpp"

class ID{
	private:
		BancoDeRegistradores *banco;
		IFID *ifid;
		IDEXE *idexe;
		bool regDest;
		bool regWrite;
		bool aluSrc;
		bool branch;
		bool memRead;
		bool memWrite;
		bool memToReg;
		string aluOP;
		int rs;
		int rt;
		int rd;
		int imm;
		void writeSignals();
		void readIFID();
		void controlSignals();
		//numero do registrador de destino
	public:
		void tick();
		ID(BancoDeRegistradores *banco, IFID *ifid, IDEXE *idexe);
		void setIFID(IFID *ifid);
		void setIDEXE(IDEXE *idexe);
		int npc;
		string ir;


};

#endif