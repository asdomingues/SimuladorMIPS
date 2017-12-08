#include "include/Mem.hpp"
#include "include/EXMEM.hpp"
#include "include/MEMWB.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Mem::Mem cria estagio MEM
 * @param exmem registrador intermediario. Deve ser o mesmo de IF e EX.
 * @param memwb registrador intermediario. Deve ser o mesmo de MEM e WB.
 * @param filename nome do arquivo que contem os dados da memoria de dados
 */
Mem::Mem(EXMEM *exmem, MEMWB *memwb, string filename){
	this->m.load_memory(filename);
	this->exmem = exmem;
	this->memwb = memwb;
}

/**
 * @brief Mem::get_memory_data retorna conteudo da memoria de pos
 * @param pos posicao da memoria, numera em termos de bytes (4 bytes por item)
 * @return conteudo da memoria em pos
 */
int Mem::get_memory_data(int pos){
    m.set_address(pos);
    return m.read();
}

/**
 * @brief Mem::read_tick tick de leitura. Deve ser chamado depois de write_tick
 */
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

/**
 * @brief Mem::write_tick tick de escrita. Deve ser chamado antes de read_tick
 */
void Mem::write_tick(){
	memwb->setir(this->ir);
	memwb->setALUOut(this->alu_out);
	
    //leitura de memoria
	if(mem_read == true) {
		m.set_address(this->address);
		read_data = m.read();
	}else{
		read_data = 0;
	}
	memwb->setLMemoryData(read_data);
	
    //Escrita de memoria
	memwb->setRegWrite(this->reg_write);
	memwb->setMemtoReg(mem_to_reg);
	memwb->set_reg_address(this->write_reg_address);
	
	if(mem_write == true) {
		m.set_address(this->address);
		m.set_wdata(this->write_data);
		m.write();
	}

	
}

/**
 * @brief Mem::reset Reinicia Mem aos seus valores iniciais
 */
void Mem::reset(){
    mem_write = false;
    mem_read = false;
    mem_to_reg = false;
    reg_write = false;
    address = 0;
    write_data = 0;
    read_data = 0;
    write_reg_address = 0;
    alu_out = 0;
    ir="";
    m.reset("registrador.in");
}
