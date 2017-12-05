#ifndef MEM_HPP
#define MEM_HPP

#include "Memoria.hpp"
#include "EXMEM.hpp"
#include "MEMWB.hpp"
class Mem{
	public:
		Mem(EXMEM *exmem, MEMWB *memwb, string filename);
		void read_tick();
		void write_tick();
<<<<<<< HEAD:include/Mem.hpp
=======
        int get_memory_data(int pos);
        void reset();
>>>>>>> gui_gets:TesteQtGraphics/GraphicsTest/include/Mem.hpp
	private:
		Memoria m;
		EXMEM *exmem;
		MEMWB *memwb;
		bool mem_write = false;
		bool mem_read = false;
		bool mem_to_reg = false;
		bool reg_write = false;
		int address = 0;
		int write_data = 0;	
		int read_data = 0;
		int write_reg_address = 0;
		int alu_out = 0;
		string ir;

};

#endif
