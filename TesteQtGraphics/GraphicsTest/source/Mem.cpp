#include "include/Mem.hpp"
#include "include/EXMEM.hpp"
#include "include/MEMWB.hpp"
#include <iostream>

using namespace std;


Mem::Mem(EXMEM *exmem, MEMWB *memwb, string filename){
	this->m.load_memory(filename);
	this->exmem = exmem;
	this->memwb = memwb;
}

void Mem::read_tick(){
	this->ir = exmem->get_ir();
	this->alu_out = exmem->get_alu_out();
	this->mem_read = exmem->get_mem_read();
	this->reg_write = exmem->get_reg_write();
	this->mem_to_reg = exmem->get_mem_to_reg();
	this->write_reg_address = exmem->get_write_reg_address(); 
	this->mem_write = exmem->get_mem_write();
	this->address = exmem->get_alu_out();
	this->write_data = exmem->get_alu_in2();
}

//checar timeline
void Mem::write_tick(){
	memwb->setir(this->ir);
	memwb->setALUOut(this->alu_out);
	
	if(mem_read == true) {
		m.set_address(this->address);
		read_data = m.read();
	}else{
		read_data = 0;
	}
	memwb->setLMemoryData(read_data);
	
	memwb->setRegWrite(this->reg_write);
	memwb->setMemtoReg(mem_to_reg);
	memwb->set_reg_address(this->write_reg_address);
	
	if(mem_write == true) {
		m.set_address(this->address);
		m.set_wdata(this->write_data);
		m.write();
	}

	
}
