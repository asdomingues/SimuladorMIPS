#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MemoriaInstrucao.hpp"
#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "IDEXE.hpp"
#include "EXMEM.hpp"
#include "MEMWB.hpp"
#include "IF.hpp"
#include "ID.hpp"
#include "EX.hpp"
#include "WB.hpp"
#include "Memoria.hpp"
#include "Mem.hpp"
#include "Ula.hpp"

using namespace std;


int main(void){

	MemoriaInstrucao memoria_instrucao;
	IFID ifid;
	Ula alu;
	EXMEM exmem;
	MEMWB memwb;
	IDEXE idexe;
	BancoDeRegistradores banco(NREGISTRADORES);
	memoria_instrucao.load_instructions("instrucoes.in");

	//criar todos os estagios
	IF ifstage(&memoria_instrucao, &ifid, &exmem);
	ID idstage(&banco, &ifid, &idexe);
	EX exstage(&alu, &idexe, &exmem);
	Mem memstage(&exmem, &memwb, "registrador.in");
	WB wbstage(&banco, &memwb);
	int counter = 0;

    do{
		ifstage.write_tick();
		wbstage.write_tick();
        idstage.write_tick();
        exstage.write_tick();
        memstage.write_tick();

        ifstage.read_tick();
        idstage.read_tick();
        exstage.read_tick();
        memstage.read_tick();
        wbstage.read_tick();
        

	if(ifid.getIR() != "") counter = 0;

        cout << "ifid: " << ifid.getIR() << " " << ifid.getNPC() << endl;
        cout << "idexe: " << idexe.getIR() << " " << idexe.getNPC() << endl;
        cout << "exmem: " << exmem.get_ir() << " " << endl;
        cout << "memwb: " << memwb.getir() << " " << endl;
	cout << "R0 : " << banco.read_reg1(0) << endl;
	cout << "R1 : " << banco.read_reg1(1) << endl;
	cout << "R2 : " << banco.read_reg1(2) << endl;
	cout << "R3 : " << banco.read_reg1(3) << endl;
	cout << "in1 :" << idexe.getA() << endl;
	cout << "in2 :" << idexe.getB() << endl;
	cout << "aluout: " << memwb.getALUOut() << " " << endl;
	/*cout << "idex:" <<endl;
	  cout << "imm: " << idexe.getImm() << endl;
	  cout << "RD " << idexe.getRD() << endl;
	  cout << "RT: " << idexe.getRT() << endl;
	  cout << "A: " << idexe.getA() << endl;
	  cout << "B: " << idexe.getB() << endl;
	  cout << "Sinais:" <<endl;
	  cout << "RegDest: " << idexe.getRegDest() << endl;
	  cout << "RegWrite: " << idexe.getRegWrite() << endl;
	  cout << "AluSrc: " << idexe.getAluSrc() << endl;
	  cout << "Branch: " << idexe.getBranch() << endl;
	  cout << "MemRead: " << idexe.getMemRead() << endl;
	  cout << "MemWrite: " << idexe.getMemWrite() << endl;
	  cout << "MemToReg: " << idexe.getMemToReg() << endl;
	  cout << "AluOP: " << idexe.getAluOP() << endl; */
	cout << endl;
	
	/*cout << "exmem:" << endl;
	cout << "branch address: "<< exmem.get_branch_address() << endl;
	cout << "alu_zero: "<< exmem.get_alu_zero() << endl;
	cout << "alu_out: "<< exmem.get_alu_out() << endl;
	cout << "alu_in2: " << exmem.get_alu_in2() << endl;
	cout << "write_reg_address: " << exmem.get_write_reg_address() << endl;
	cout << "reg_write: " << exmem.get_reg_write() << endl;
	cout << "branch: " << exmem.get_branch() << endl;
	cout << "mem_read: "<< exmem.get_mem_read() << endl;
	cout << "mem_write:" << exmem.get_mem_write() << endl;
	cout << "mem_to_reg:" << exmem.get_mem_to_reg() << endl;*/
	cout << "memwb : " << endl;	
	cout << "ALUOut : " << memwb.getALUOut() << endl;
        cout << "LMemoryData : " << memwb.getLMemoryData() << endl;
      	cout << "RegWrite : " << memwb.getRegWrite() << endl;
    	cout << "MemtoReg : " << memwb.getMemtoReg() << endl;
     	cout << "RegAddress : " << memwb.get_reg_address() << endl;
 
		cout << endl << endl;
    }while((++counter) < 5);



	/*int numero = 0;
	  while(numero != -1){

	  printf("     ___       __________    \n");
	  printf("    |   |     | Memoria  |   \n");
	  printf("    |PC |     |    de    |   \n");
	  printf("    |   |     | Instrucao|   \n");
	  printf("    |%3d|->   |          |   \n", numero);
	  printf("    |___|     |__________|   \n");
	  cin >> numero;
	  system("clear");
	  printf("     ___       __________    \n");
	  printf("    |   |     | Memoria  |   \n");
	  printf("    |PC |     |    de    |   \n");
	  printf("    |   |     | Instrucao|   \n");
	  printf("    |%3d|-->  |          |   \n", numero);
	  printf("    |___|     |__________|   \n");
	  cin >> numero;
	  system("clear");
	  printf("     ___       __________    \n");
	  printf("    |   |     | Memoria  |   \n");
	  printf("    |PC |     |    de    |   \n");
	  printf("    |   |     | Instrucao|   \n");
	  printf("    |%3d|---> |          |   \n", numero);
	  printf("    |___|     |__________|   \n");
	  cin >> numero;
	  system("clear");
	  }*/

	return 0;
}

// PC,
