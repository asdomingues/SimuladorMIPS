#ifndef _IF_H_
#define _IF_H_

#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "EXMEM.hpp"
#include "MemoriaInstrucao.hpp"
#include "Mux.hpp"
#include <iostream>

class IF{
	private:
		MemoriaInstrucao *memoria;
		IFID *ifid;
		EXMEM *exmem;
		Registrador pc;
		string ir;
		Mux mux;

		//numero do registrador de destino
	public:
		void tick();
		IF(MemoriaInstrucao *memoria, IFID *ifid, EXMEM *exmem);
		int get_pc();
};

#endif