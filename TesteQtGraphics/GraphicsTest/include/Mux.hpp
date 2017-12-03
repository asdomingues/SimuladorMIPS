#ifndef MUX_HPP
#define MUX_HPP

class Mux{
	public:
		Mux(int size);
		Mux();
		int get_saida(int saida);
		void set_entrada(int entrada, int valor);
        int get_seletor();
	private:
		int tamanho;
		int *entradas;
        int seletor = 0;
};

#endif
