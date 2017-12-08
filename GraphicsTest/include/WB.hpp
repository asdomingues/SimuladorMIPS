#ifndef _WB_H_
#define _WB_H_

#include "BancoDeRegistradores.hpp"
#include "Mux.hpp"
#include "MEMWB.hpp"

using namespace std;

/**
 * @brief The WB class Estagio WB
 */
class WB{
	private:
		BancoDeRegistradores *banco;
		MEMWB *memwb;
		Mux mux;
		bool reg_write;
		int alu_out = 0;
		int l_memory_data;
		bool mem_to_reg;
		int reg_address;
	
	public:
		void read_tick();
		void write_tick();
        void reset();
		WB(BancoDeRegistradores *banco, MEMWB *memwb);

};

#endif
