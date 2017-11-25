#ifndef MEMORIA_HPP
#define MEMORIA_HPP
#include "Registrador.hpp"
#define TAM 1024
#include <string>

class Memoria{
	public:
		Memoria();
		void set_address(int val);
		void set_wdata(int val);
		string read();
		void write();

	private:
		int address, w_data;
		string dados[TAM];
};

#endif
