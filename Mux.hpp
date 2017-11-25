#ifndef MUX_HPP
#define MUX_HPP

class Mux{
	public:
		Mux(int size);
		int get_saida(int saida);
		void set_entrada(int entrada, int valor);
	private:
		int tamanho;
		int *entradas;

};

#endif
