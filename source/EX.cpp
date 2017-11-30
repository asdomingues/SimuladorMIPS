#include <string>

#include "IDEXE.hpp"
#include "EX.hpp"
#include "EXMEM.hpp"
#include "Mux.hpp"
#include "Ula.hpp"

using namespace std;

EX::EX(Ula *alu, IDEXE *idex, EXMEM *exmem) {
	this->alu = alu;
	this->idex = idex;
	this->exmem = exmem;

	this->reg_dst = false;
	this->reg_write = false;
	this->alu_src = false;
	this->branch = false;
	this->mem_read = false;
	this->mem_write = false;
	this->mem_to_reg = false;
	this->alu_op = "";
}

void EX::write_signals() {
	exmem->set_reg_write(reg_write);
	exmem->set_branch(branch);
	exmem->set_mem_read(mem_read);
	exmem->set_mem_write(mem_write);
	exmem->set_mem_to_reg(mem_to_reg);
	exmem->set_ir(idex->getIR());
}

void EX::read_idex() {
	reg_dst = idex->getRegDest();
	reg_write = idex->getRegWrite();
	alu_src = idex->getAluSrc();
	branch = idex->getBranch();
	mem_read = idex->getMemRead();
	mem_write = idex->getMemWrite();
	mem_to_reg = idex->getMemToReg();
	alu_op = idex->getAluOP();
}

void EX::tick() {
	Mux m = Mux(2);
	int select;

	exmem->set_branch_address(idex->getNPC() + idex->getImm() << 2);

	m.set_entrada(idex->getB(), 0);
	m.set_entrada(idex->getImm(), 1);
	select = idex->getAluSrc() == true ? 1 : 0;
	alu->set_aluIN1(idex->getA());
	alu->set_aluIN2(m.get_saida(select));
	alu->set_aluOP(idex->getAluOP());
	exmem->set_alu_out(alu->operation());

	exmem->set_alu_in2(idex->getB());

	m.set_entrada(idex->getRT(), 0);
	m.set_entrada(idex->getRD(), 1);
	select = idex->getRegDest() == true ? 1 : 0;
	exmem->set_write_reg_address(m.get_saida(select));
	
	write_signals();
	read_idex();
}

/*
int main(void) {
	return 0;
}
*/
