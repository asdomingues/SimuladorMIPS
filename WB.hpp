#ifndef _WB_H_
#define _WB_H_

#include "BancoDeRegistradores.hpp"
#include "Mux.hpp"
#include "MEMWB.hpp"


class WB{
	private:
		BancoDeRegistradores *banco;
		MEMWB *memwb;
		Mux mux;
	
		
		//numero do registrador de destino
	public:
		void tick();
		WB(BancoDeRegistradores *banco, MEMWB *memwb);

};

#endif