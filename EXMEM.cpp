#include <string>
#include "EXMEM.hpp"


EXMEM::EXMEM() {
	this->ir = "";
	this->branch_address = 0;
	this->alu_zero = false;
	this->alu_out = 0;
	this->alu_in2 = 0;
	this->write_reg_address = false;
	this->reg_write = false;
	this->branch = false;
	this->mem_read = false;
	this->mem_write = false;
	this->mem_to_reg = false;
}

void EXMEM::set_ir(string ir) {
	this->ir = ir;
}

void EXMEM::set_branch_address(int branch_address) {
	this->branch_address = branch_address;
}

void EXMEM::set_alu_zero(bool alu_zero) {
	this->alu_zero = alu_zero;
}

void EXMEM::set_alu_out(int alu_out) {
	this->alu_out = alu_out;
}

void EXMEM::set_alu_in2(int alu_in2) {
	this->alu_in2 = alu_in2;
}

void EXMEM::set_write_reg_address(int write_reg_address) {
	this->write_reg_address = write_reg_address;
}

void EXMEM::set_reg_write(bool reg_write) {
	this->reg_write = reg_write;
}

void EXMEM::set_branch(bool branch) {
	this->branch = branch;
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


string EXMEM::get_ir() {
	return this->ir;
}

int EXMEM::get_branch_address() {
	return this->branch_address;
}

bool EXMEM::get_alu_zero() {
	return this->alu_zero;
}

int EXMEM::get_alu_out() {
	return this->alu_out;
}

int EXMEM::get_alu_in2() {
	return this->alu_in2;
}

int EXMEM::get_write_reg_address() {
	return this->write_reg_address;
}

bool EXMEM::get_reg_write() {
	return this->reg_write;
}

bool EXMEM::get_branch() {
	return this->branch;
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
/*
int main (void) {
	return 0;
}*/
