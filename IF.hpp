#ifndef _IF_H_
#define _IF_H_

#include "BancoDeRegistradores.hpp"
#include "IFIF.hpp"
#include "IFEXE.hpp"

class IF{
	private:
		Memoria *memoria;
		IFID *ifid;
		Registrador pc;
		string ir;
		Mux mux;
		
		//numero do registrador de destino
	public:
		void tick();
		ID(Memoria *memoria, IFID *ifid);
};

#endif