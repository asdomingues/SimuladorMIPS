#include "IF.hpp"


	ID::ID(Memoria *memoria, IFID *ifid, EXMEM *exmem){
		this->memoria=memoria;
		this->ifid=ifid;
		ir="";
		pc = Registrador("PC");
		pc.set_valor(0);
		mux = Mux(2);
	}

	void ID::tick(){
		//le memoria
		memoria.set_endereco(pc.get_valor());
		ir = memoria.read();
		
		//incrementa PC
		pc.set_valor(pc.get_valor()+4);

		bool pcSrc;

		//pegue do exmem
		//and branch e o zero
		pcSrc = exmem->get_alu_zero() && exmem->get_branch();
		
		mux.set_entrada(0, pc);
		mux.set_entrada(1, exmem->get_branch_address());
		pc.set_valor(mux.get_saida(pcSrc));
	
		//escreve no ifid
		ifid.setIR(ir);
		ifid.setNPC(pc);
	}

	int ID::get_pc(){
		return pc.get_valor();
	}

	int main(void){

		

		return 0;
	}

