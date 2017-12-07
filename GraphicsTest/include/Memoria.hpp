#ifndef MEMORIA_HPP
#define MEMORIA_HPP
#include <string>
#include <stdio.h>

#define TAM 1024
using namespace std;

class Memoria{
	public:
		Memoria();
		void set_address(int val);
		void set_wdata(int val);
		int read();
		void write();
		int load_memory(string); 
        void reset(string name);
	private:
		int address, w_data;
		int dados[TAM];
};

#endif
