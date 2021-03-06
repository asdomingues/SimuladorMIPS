#ifndef INSTRUCAO_HPP
#define INSTRUCAO_HPP

#include "Registrador.hpp"
#define TAM 1024
#include <string>

/**
 * @brief Memoria de Instrucoes - guarda instrucoes em formato de string.
 * Posicoes de memoria numeradas a cada 4 bytes.
 */
class MemoriaInstrucao{
    public:
        MemoriaInstrucao();
        void set_address(int val);
        void set_wdata(string val);
        string read();
        void write();
        void load_instructions(string filename);
        int get_memory_size();
        int get_n_instructions();

    private:
        int address;
        int n_instructions;
        string dados[TAM], w_data;
};

#endif
