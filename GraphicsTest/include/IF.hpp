#ifndef _IF_H_
#define _IF_H_

#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "EXMEM.hpp"
#include "MemoriaInstrucao.hpp"
#include "Mux.hpp"
#include <iostream>

/*Estagio IF
 *  Busca instrucoes na memoria e mantem PC atualizado
 */
class IF{
	private:
        MemoriaInstrucao *memoria; //memoria de instrucoes
        IFID *ifid; //registrador intermediario IF/ID
        EXMEM *exmem; //registrador intermediaro EX/MEM (para definicao de branch)
        Registrador pc; //Registrador PC - program counter
        string ir; //Instruction Register
        Mux mux; //Para selecao do PC - branch ou pc+4
        bool pcSrc; //Sinal de selecao para PC

	public:
		void write_tick();
		void read_tick();
		IF(MemoriaInstrucao *memoria, IFID *ifid, EXMEM *exmem);
		int get_pc();
		void read_exmem();
        int get_mux_origin();
		bool get_pcSrc();
        void reset();
};

#endif
