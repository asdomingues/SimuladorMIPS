#ifndef _EXMEM_HPP
# define _EXMEM_HPP

#include <string>

using namespace std;

class EXMEM {
	public:
		EXMEM();
		void set_ir(string ir);

		void set_branch_address(int branch_address);
		void set_alu_zero(bool alu_zero);
		void set_alu_out(int alu_out);
		void set_alu_in2(int alu_in2);
		void set_write_reg_address(int write_reg_address);

		void set_reg_write(bool reg_write);
		void set_branch(bool branch);
		void set_mem_read(bool mem_read);
		void set_mem_write(bool mem_write);
		void set_mem_to_reg(bool mem_to_reg);

		string get_ir();

		int get_branch_address();
		bool get_alu_zero();
		int get_alu_out();
		int get_alu_in2();
		int get_write_reg_address();

		bool get_reg_write();
		bool get_branch();
		bool get_mem_read();
		bool get_mem_write();
		bool get_mem_to_reg();
        void reset();
	private:
		string ir;

		int branch_address;
		bool alu_zero;
		int alu_out;
		int alu_in2;
		int write_reg_address;

		bool reg_write;
		bool branch;
		bool mem_read;
		bool mem_write;
		bool mem_to_reg;

};

#endif
