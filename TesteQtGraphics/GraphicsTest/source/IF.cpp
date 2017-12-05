#include "include/IF.hpp"

	using namespace std;


	IF::IF(MemoriaInstrucao *memoria, IFID *ifid, EXMEM *exmem){
		this->memoria=memoria;
		this->ifid=ifid;
		this->exmem=exmem;
		ir="";
		pc.set_valor(0);
		pc.set_nome("pc");
	}
    int IF::get_mux_origin(){
        return this->mux.get_seletor();
    }
	void IF::read_exmem(){
		//pegue do exmem
		//and branch e o zero
		pcSrc = exmem->get_alu_zero() && exmem->get_branch();
		
		mux.set_entrada(0, pc.get_valor());
		mux.set_entrada(1, exmem->get_branch_address());
		pc.set_valor(mux.get_saida(pcSrc));
	}

	void IF::write_tick(){
		//le memoria
		memoria->set_address(pc.get_valor());
		ir = memoria->read();
		//incrementa PC
		pc.set_valor(pc.get_valor()+4);

		//escreve no ifid
		ifid->setIR(ir);
		ifid->setNPC(pc.get_valor());
	}

	void IF::read_tick(){
	
		read_exmem();
	
	}

	int IF::get_pc(){
		return pc.get_valor();
	}

    bool IF::get_pcSrc(){
		return pcSrc;
	}

    void IF::reset(){
        ir="";
        pc.set_valor(0);
        pc.set_nome("pc");
    }
