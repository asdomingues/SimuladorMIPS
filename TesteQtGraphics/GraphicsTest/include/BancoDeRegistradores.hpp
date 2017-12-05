#ifndef BANCODEREGISTRADORES_HPP
#define BANCODEREGISTRADORES_HPP
#include "Registrador.hpp"

#define NREGISTRADORES 32
class BancoDeRegistradores{
	public:
		int read_reg1(int reg);
		void set_wreg(int reg);
		void set_wdata(int data);
		void reg_write();
        string get_name(int reg);
		BancoDeRegistradores(int size);
	private:
		Registrador banco[NREGISTRADORES];
		int write_register, write_data;
};
#endif
