#ifndef MEM_HPP
#define MEM_HPP

#include "Memoria.hpp"
#include "MEMEX.hpp"
#include "WBMEM.hpp"
class Mem{
	public:
		Mem();
		void tick();
	private:
		Memoria m = Memoria();
		EXMEM exmem;
		MEMWB memwb;
		bool mem_write = false;
		bool mem_read = false;
		bool mem_to_reg = false;
		bool reg_write = false;
		int address = 0;
		int write_data = 0;	
		int read_data = 0;
		int write_reg_address = 0;
		int alu_out = 0;

};

#endif
