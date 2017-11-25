#ifndef MEMORIA_HPP
#define MEMORIA_HPP
#include "Registrador.hpp"
#define TAM 1024
class Memoria{
	public:
		Memoria();
		void set_endereco(int val);
		void set_wdata(int val);
		int read();
		void write();
	private:
		int adress, w_data;
		int dados[TAM];
};

#endif
