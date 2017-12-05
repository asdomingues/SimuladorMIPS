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


<<<<<<< HEAD:source/WB.cpp
	/*int main(){

		BancoDeRegistradores banco(32);
		MEMWB memwb;
		WB wb(&banco, &memwb);

        memwb.setALUOut(5);

        memwb.setLMemoryData(2);

        memwb.setRegWrite(true);

        memwb.setMemtoReg(false);
        memwb.set_reg_address(0);

        wb.tick();
         memwb.setALUOut(3);

        memwb.setLMemoryData(1);

        memwb.setRegWrite(true);

        memwb.setMemtoReg(true);

        memwb.set_reg_address(0);
        wb.tick();

        cout << banco.read_reg1(0);

        wb.tick();
         cout << banco.read_reg1(0);



		return 0;
	}*/
=======
    void WB::reset(){
        reg_write = false;
        alu_out = 0;
        l_memory_data = 0;
        mem_to_reg = false;
        reg_address = 0;
    }
>>>>>>> gui_gets:TesteQtGraphics/GraphicsTest/source/WB.cpp
