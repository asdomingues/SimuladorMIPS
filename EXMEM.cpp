#include <string>
#include "EXMEM.hpp"

EXMEM::EXMEM() {
	this->ir = "";
	this->branch = 0;
	this->alu_out = 0;
	this->alu_in2 = 0;
	this->npc = 0;
	this->reg_write = false;
	this->mem_read = false;
	this->mem_write = false;
	this->mem_to_reg = false;
}

void EXMEM::set_ir(string ir) {
	this->ir = ir;
}

void EXMEM::set_branch(int branch) {
	this->branch = branch;
}

void EXMEM::set_alu_out(int alu_out) {
	this->alu_out = alu_out;
}

void EXMEM::set_alu_in2(int alu_in2) {
	this->alu_in2 = alu_in2;
}

void EXMEM::set_npc(int npc) {
	this->npc = npc;
}

void EXMEM::set_reg_write(bool reg_write) {
	this->reg_write = reg_write;
}

void EXMEM::set_mem_read(bool mem_read) {
	this->mem_read = mem_read;
}

void EXMEM::set_mem_write(bool mem_write) {
	this->mem_write = mem_write;
}

void EXMEM::set_mem_to_reg(bool mem_to_reg) {
	this->mem_to_reg = mem_to_reg;
}

string EXMEM::get_ir(string ir) {
	this->ir = ir;
}

int EXMEM::get_branch() {
	return this->branch;
}

int EXMEM::get_alu_out() {
	return this->alu_out;
}

int EXMEM::get_alu_in2() {
	return this->alu_in2;
}

int EXMEM::get_npc() {
	return this->npc;
}

bool EXMEM::get_reg_write() {
	return this->reg_write;
}

bool EXMEM::get_mem_read() {
	return this->mem_read;
}

bool EXMEM::get_mem_write() {
	return this->mem_write;
}

bool EXMEM::get_mem_to_reg() {
	return this->mem_to_reg;
}
