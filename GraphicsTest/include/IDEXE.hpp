#ifndef _IDEXE_H
#define _IDEXE_H

#include <string>

using namespace std;

/**
 * @brief Registrador intermediario IDEX
 */
class IDEXE{
	private:
		string ir;
		int npc;
		int rt;
		int rd;
		bool regDest;
		bool regWrite;
		bool aluSrc;
		bool branch;
		bool memRead;
		bool memWrite;
		bool memToReg;
		int ra, rb;
		int imm;
		string aluOP;

	public:
		IDEXE();
		void setIR(string ir);
		void setNPC(int npc);
		string getIR();
		int getNPC();
		void setRegDest (bool regDest);
		void setRegWrite(bool regWrite);
		void setAluSrc(bool aluSrc);
		void setBranch(bool branch);
		void setMemRead(bool memRead);
		void setMemWrite(bool memWrite);
		void setMemToReg(bool memToReg);
		void setAluOP(string aluOP);
		void setA(int ra);
		void setB(int rb);
		void setRD(int rd);
		void setRT (int rt);
		void setImm (int imm);
		int getImm ();
		int getRD();
		int getRT();
		int getA();
		int getB();
		bool getRegDest();
		bool getRegWrite();
		bool getAluSrc();
		bool getBranch();
		bool getMemRead();
		bool getMemWrite();
		bool getMemToReg();
		string getAluOP();
        void reset();
};

#endif
