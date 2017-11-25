#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include "Registrador.hpp"
#define TAM 1024
#include <string>

class MemoriaInstrucao{
    public:
        MemoriaInstrucao();
        void set_address(int val);
        void set_wdata(string val);
        string read();
        void write();

    private:
        int address;
        string dados[TAM], w_data;
};

#endif
