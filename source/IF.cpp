#include "IF.hpp"

	using namespace std;


	IF::IF(MemoriaInstrucao *memoria, IFID *ifid, EXMEM *exmem): pc("PC"){
		this->memoria=memoria;
		this->ifid=ifid;
		this->exmem=exmem;
		ir="";
		pc.set_valor(0);
	}

	void IF::read_exmem(){
		//pegue do exmem
		//and branch e o zero
		pcSrc = exmem->get_alu_zero() && exmem->get_branch();
		
		mux.set_entrada(0, pc.get_valor());
		mux.set_entrada(1, exmem->get_branch_address());
		pc.set_valor(mux.get_saida(pcSrc));
	}


	void IF::tick(){
		//le memoria
		memoria->set_address(pc.get_valor());
		ir = memoria->read();
		
		//incrementa PC
		pc.set_valor(pc.get_valor()+4);
	
		//escreve no ifid
		ifid->setIR(ir);
		ifid->setNPC(pc.get_valor());
	}

	int IF::get_pc(){
		return pc.get_valor();
	}
/*
	int main(void){

		//criar memoria

		MemoriaInstrucao memoria;

		memoria.set_address(0);
		memoria.set_wdata("add $r3, $r2, %r1");
		memoria.write();

		memoria.set_address(4);
		memoria.set_wdata("sub $r2, $r2, %r1");
		memoria.write();

		IFID ifid;
		EXMEM exmem;
		IF ifstage(&memoria, &ifid, &exmem);
		ifstage.tick();

		cout << ifid.getIR();
		cout << "\n";
		cout << ifid.getNPC();
		cout << "\n";
		//set branch
		exmem.set_branch(true);
		exmem.set_alu_zero(true);
		exmem.set_branch_address(0);

		ifstage.tick();

		cout << ifid.getIR();
		cout << "\n";
		cout << ifid.getNPC();
		cout << "\n";
		exmem.set_alu_zero(false);

		ifstage.tick();

		cout << ifid.getIR();
		cout << "\n";
		cout << ifid.getNPC();
		cout << "\n";

		
		return 0;
	}
*/
