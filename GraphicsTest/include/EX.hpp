#ifndef _EX_HPP
# define _EX_HPP

#include "Ula.hpp"
#include "IDEXE.hpp"
#include "EXMEM.hpp"
#include <string>

/**
 * @brief Estágio EX
 */
class EX {
	private:
		IDEXE *idex; // registradores intermediários anteriores
		EXMEM *exmem; // registradores intermediários posteriores
		Ula *alu; // alu do processador

		// sinais de controle usados neste estágios
		bool reg_dst;
		string alu_op;
		bool alu_src;
		// sinais de controle usados no próximo estágio (mem)
		bool mem_read;
		bool mem_write;
		// sinais de controle usados no estágio de write back
		bool mem_to_reg;
		// sinal usado pelo estado de busca
		bool branch;
		// sinais usados pelo estado de decodificação
		bool reg_write;

		void write_signals();
		void read_idex();
		string ir; // instruction register
		int b, a, rt, rd; // entradas da ULA e registrador de destino
		int imm, npc;

	public:
		void read_tick(); // primeira metade do clock
        void write_tick(); // segunda metade do clock
        void reset();
		EX(Ula *alu, IDEXE *idex, EXMEM *exmem);
};

#endif
