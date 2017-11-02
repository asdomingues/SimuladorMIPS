#ifndef MEMORIA_HPP
#define MEMORIA_HPP
#include "Registrador.hpp"
class Memoria{
	public:
		Memoria(int size);
		void set_endereco(int end);
		void set_wdata(int dado);
		int read();
		void write();
	private:
		int end, w_data, r_data, size;
		int *dados;
};

#endif
