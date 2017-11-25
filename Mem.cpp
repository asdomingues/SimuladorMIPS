#include "Mem.hpp"


Mem::Mem(EXMEM *exmem, MEMWB *memwb){
	this->exmem = exmem;
	this->memwb = memwb;
}

void Mem::tick(){
	memwb->set_reg_write(exmem->getRegWrite());
	memwb->set_mem_to_reg(exmem->getMemToReg());
		
	memwb->setLMemoryData(m->read());
	memwb->setALUOut(exmem->get_alu_out());

	m->set_address(exmem->get_alu_out());
	m->set_wdata(exmem->alu_in2);
	if(exmem->get_mem_write() == true) m->write();
	if(exmem->get_mem_read() == true) m->read();
}
