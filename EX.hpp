#ifndef _EX_HPP
# define _EX_HPP

#include "Ula.hpp"
#include "IDEXE.hpp"
#include "EXMEM.hpp"

class EX {
	private:
		IDEXE *idex;
		EXMEM *exmem;
		Ula *alu;

		// signals used at this stage
		bool reg_dst;
		string alu_op;
		bool alu_src;
		// signals used at mem stage
		bool mem_read;
		bool mem_write;
		// signals used at wb stage
		bool mem_to_reg;
		// signals used at if stage
		bool branch;
		// signals used at id stage
		bool reg_write;
		void write_signals();
		void read_idex();
	public:
		void tick();
		EX(Ula *alu, IDEXE *idex, EXMEM *exmem);
};

#endif
