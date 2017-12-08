#ifndef _ID_H_
#define _ID_H_

#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "IDEXE.hpp"

/**
 * @brief Estagio ID
 */
class ID{
	private:
        BancoDeRegistradores *banco;
        IFID *ifid;
		IDEXE *idexe;
        bool regDest; //Sinais de controle
		bool regWrite;
		bool aluSrc;
		bool branch;
		bool memRead;
		bool memWrite;
		bool memToReg;
		string aluOP;
        int rs; //Numeros de registradores obtidos com decodificacao da instrucao
		int rt;
		int rd;
        int imm; //valor imediato
		void writeSignals();
		void readIFID();
		void controlSignals();
	public:
		void read_tick();
		void write_tick();
		ID(BancoDeRegistradores *banco, IFID *ifid, IDEXE *idexe);
		void setIFID(IFID *ifid);
		void setIDEXE(IDEXE *idexe);
        void reset();
		int get_reg1();
		int get_reg2();
		int npc;
		string ir;


};

#endif
