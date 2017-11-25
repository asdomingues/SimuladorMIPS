#include "WB.hpp"
#include <iostream>

using namespace std;


	WB::WB(BancoDeRegistradores *banco, MEMWB *memwb){
		this->banco=banco;
		this->memwb=memwb;

	}

	void WB::tick(){
		int data;
		
		//escreve na memoria
		if(memwb->getRegWrite()){
		
			mux.set_entrada(0, memwb->getALUOut());
			mux.set_entrada(1, memwb->getLMemoryData());
			data = mux.get_saida(memwb->getMemtoReg());


			banco->set_wreg(memwb->get_reg_address());	
			banco->set_wdata(data);
			banco->reg_write();
		}


		
	}

/*
	int main(){

		BancoDeRegistradores banco(32);
		MEMWB memwb;
		WB wb(&banco, &memwb);

        memwb.setALUOut(5);

        memwb.setLMemoryData(2);

        memwb.setRegWrite(true);

        memwb.setMemtoReg(true);
        memwb.set_reg_address(0);

        wb.tick();

        cout << banco.read_reg1(0);



		return 0;
	}*/