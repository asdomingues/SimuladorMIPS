#include "WB.hpp"



	WB::WB(BancoDeRegistradores *banco, MEMWB *memwb){
		this->banco=banco;
		this->memwb=memwb;
		this->mux(2);
	}

	void WB::tick(){
		int data;
		
		//escreve na memoria
		
			/*//mem to reg
			if(memwb->getMemtoReg()){
				//dado da memoria
				data = memwb->getLMemoryData();
			}else{
				//dado da ALU
				data = memwb->getALUOut();
			}*/
		if(memwb->getMemtoReg()){
			mux.set_entrada(0, memwb->getALUOut());
			mux.set_entrada(1, memwb->getLMemoryData());
			data = mux.get_saida(memwb->getRegWrite());

			banco->set_wreg(memwb->get_reg_address());	
			banco->set_wdata(data);
			banco->reg_write();
		}


		
	}


	int main(){

		BancoDeRegistradores banco(32);
		MEMWB memwb;
		WB wb(&banco, &memwb);

	
        memwb->setALUOut(5);

        memwb->setLMemoryData(2);

        memwb->setRegWrite(true);

        memwb->setMemtoReg(true);
        memwb->setWr_address(0)

        wb.tick();

        cout << banco->read_reg1(0);



		return 0;
	}