#ifndef MEMORIA_HPP
#define MEMORIA_HPP
#include <string>

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
	private:
		int address, w_data;
		int dados[TAM];
};

#endif
