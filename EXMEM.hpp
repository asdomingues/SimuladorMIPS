#ifndef _EXMEM_HPP
# define _EXMEM_HPP

#include <string>

using namespace std;

class EXMEM {
	private:
		string ir;
		int branch;
		int alu_out;
		int alu_in2;
		int npc;
		bool reg_write;
		bool mem_read;
		bool mem_write;
		bool mem_to_reg;
	public:
		EXMEM();
		void set_ir(string ir);
		void set_branch(int branch);
		void set_alu_out(int alu_out);
		void set_alu_in2(int alu_in2);
		void set_npc(int npc);
		void set_reg_write(bool reg_write);
		void set_mem_read(bool mem_read);
		void set_mem_write(bool mem_write);
		void set_mem_to_reg(bool mem_to_reg);
		string get_ir();
		int get_branch();
		int get_alu_out();
		int get_alu_in2();
		int get_npc();
		bool get_reg_write();
		bool get_mem_read();
		bool get_mem_write();
		bool get_mem_to_reg();
}

#endif
