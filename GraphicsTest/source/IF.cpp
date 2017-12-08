#include "include/IF.hpp"

	using namespace std;

    /*
     *  Cria um objeto IF com PC=0.
     * Parametros:
     *   memoria: ponteiro para uma memoria de instrucoes ja inicializada
     *   ifid: ponteiro para o registrador intermediario IFID. Deve ser o mesmo que o passado para
     * ID.
     *   exmem: ponteiro para o registrador intermediario EXMEM. Deve ser o mesmo que o passado para
     * EX e MEM.
     */
	IF::IF(MemoriaInstrucao *memoria, IFID *ifid, EXMEM *exmem){
		this->memoria=memoria;
		this->ifid=ifid;
		this->exmem=exmem;
		ir="";
		pc.set_valor(0);
		pc.set_nome("pc");
	}

    //Retorna valor de pcSrc
    int IF::get_mux_origin(){
        return this->mux.get_seletor();
    }

    //Leitura do reg EXMEM para definicao de pcSrc (para branches)
	void IF::read_exmem(){
		//pegue do exmem
		//and branch e o zero
		pcSrc = exmem->get_alu_zero() && exmem->get_branch();
		
		mux.set_entrada(0, pc.get_valor());
		mux.set_entrada(1, exmem->get_branch_address());
		pc.set_valor(mux.get_saida(pcSrc));
	}

    /*
     * Tick de escrita: funcao que avanca o estagio no clock, executando
     * as escritas necessarias.
     * Deve ser chamado antes de read_tick.
     */
	void IF::write_tick(){
		//le memoria
		memoria->set_address(pc.get_valor());
		ir = memoria->read();
		//incrementa PC
		pc.set_valor(pc.get_valor()+4);

		//escreve no ifid
		ifid->setIR(ir);
		ifid->setNPC(pc.get_valor());
	}

    /*
     * Tick de leitura: funcao que avanca o estagio no clock, executando
     * as leituras necessarias.
     * Deve ser chamado depois de write_tick.
     */
	void IF::read_tick(){
	
		read_exmem();
	
	}

	int IF::get_pc(){
		return pc.get_valor();
	}

    bool IF::get_pcSrc(){
		return pcSrc;
	}

    /*
     * Retorna IF ao seu estado inicial
     */
    void IF::reset(){
        ir="";
        pc.set_valor(0);
        pc.set_nome("pc");
    }
