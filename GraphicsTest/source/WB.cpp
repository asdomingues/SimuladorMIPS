#include "include/WB.hpp"
#include <iostream>

using namespace std;

    /**
     * @brief WB::WB cria estagio WB
     * @param banco banco de registradores. Deve ser o mesmo de ID.
     * @param memwb registrador intermediario. Deve ser o mesmo de Mem.
     */
	WB::WB(BancoDeRegistradores *banco, MEMWB *memwb){
		this->banco=banco;
		this->memwb=memwb;
		reg_write = false;
		alu_out = 0;
		l_memory_data = 0;
		mem_to_reg = false;
		reg_address = 0;

	}

    /**
     * @brief WB::read_tick tick de leitura. Deve ser chamado depois de write_tick.
     */
	void WB::read_tick(){
		//ler mem/wb
		alu_out = memwb->getALUOut();
		l_memory_data = memwb->getLMemoryData();
		mem_to_reg = memwb->getMemtoReg();
		reg_address = memwb->get_reg_address();
		reg_write = memwb->getRegWrite();
	}

    /**
     * @brief WB::write_tick tick de escrita. Deve ser chamado antes de read_tick.
     */
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

    /**
     * @brief WB::reset Reinicia WB com seus valores iniciais
     */
    void WB::reset(){
        reg_write = false;
        alu_out = 0;
        l_memory_data = 0;
        mem_to_reg = false;
        reg_address = 0;
    }
