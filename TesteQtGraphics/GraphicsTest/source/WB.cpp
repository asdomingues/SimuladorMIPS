#include "include/WB.hpp"
#include <iostream>

using namespace std;


	WB::WB(BancoDeRegistradores *banco, MEMWB *memwb){
		this->banco=banco;
		this->memwb=memwb;
		reg_write = false;
		alu_out = 0;
		l_memory_data = 0;
		mem_to_reg = false;
		reg_address = 0;

	}

	void WB::read_tick(){
		//ler mem/wb
		alu_out = memwb->getALUOut();
		l_memory_data = memwb->getLMemoryData();
		mem_to_reg = memwb->getMemtoReg();
		reg_address = memwb->get_reg_address();
		reg_write = memwb->getRegWrite();
	}

	void WB::write_tick(){
		int data;
		
		//escreve no banco de registradores
		if(reg_write){
			//usando mux		
			mux.set_entrada(0, alu_out);
			mux.set_entrada(1, l_memory_data);
			data = mux.get_saida(mem_to_reg);

			//escrevendo no banco
			banco->set_wreg(reg_address);	
			banco->set_wdata(data);
			banco->reg_write();
		}
	
		
	}


    void WB::reset(){
        reg_write = false;
        alu_out = 0;
        l_memory_data = 0;
        mem_to_reg = false;
        reg_address = 0;
    }
