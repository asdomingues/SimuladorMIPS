#ifndef _WB_H_
#define _WB_H_

#include "BancoDeRegistradores.hpp"
#include "Mux.hpp"
#include "MEMWB.hpp"

using namespace std;
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
	
		//numero do registrador de destino
	public:
		void read_tick();
		void write_tick();
<<<<<<< HEAD:include/WB.hpp
=======
        void reset();
>>>>>>> gui_gets:TesteQtGraphics/GraphicsTest/include/WB.hpp
		WB(BancoDeRegistradores *banco, MEMWB *memwb);

};

#endif
