#include "Mem.hpp"
#include "EXMEM.hpp"
#include "MEMWB.hpp"

Mem::Mem(EXMEM *exmem, MEMWB *memwb, string filename){
	this->m.load_memory(filename);
	this->exmem = exmem;
	this->memwb = memwb;
}
//checar timeline
void Mem::tick(){

	memwb->setALUOut(this->alu_out);
	this->alu_out = exmem->get_alu_out();
	
	memwb->setLMemoryData(read_data);
	if(mem_read == true) {
		m.set_address(this->address);
		read_data = m.read();
	}
	this->mem_read = exmem->get_mem_read();

	memwb->setRegWrite(this->reg_write);
	this->reg_write = exmem->get_reg_write();

	memwb->setMemtoReg(mem_to_reg);
	mem_to_reg = exmem->get_mem_to_reg();

	memwb->set_reg_address(this->write_reg_address);
	this->write_reg_address = exmem->get_write_reg_address(); 

	if(mem_write == true) {
		m.set_address(this->address);
		m.set_wdata(this->write_data);
		m.write();
	}
	this->mem_write = exmem->get_mem_write();

	this->address = exmem->get_alu_out();
	
}
