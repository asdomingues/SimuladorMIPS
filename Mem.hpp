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

		

};

#endif
