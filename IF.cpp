#include "IF.hpp"


	ID(Memoria *memoria, IFID *ifid){
		this->memoria=memoria;
		this->ifid=ifid;
		ir="";
		pc = Registrador("PC");
		pc.set_valor(0);
		mux = Mux(2);
	}

	void tick(){
		//le memoria
		memoria.set_endereco();
		ir = memoria.read();
		
		//incrementa PC
		pc.set_valor(pc.get_valor+4);

		bool pcSrc;
		//pegue do exmem
			//and branch e o zero
			//npc
		mux.set_entrada(0, pc);
		mux.set_entrada(1, int valor);
		pc.set_valor(mux.get_saida(pcSrc));
	
		//escreve no ifid
		ifid.setIR(ir);
		ifid.setNPC(pc);
	}
