#include "MemoriaInstrucao.hpp"
#include <fstream>

using namespace std;
MemoriaInstrucao::MemoriaInstrucao(){
    address = 0;
    w_data = "";
    for(int i = 0; i < TAM; i++)
        dados[i] = "";
}

void MemoriaInstrucao::set_address(int val){
    val /= 4;
    address = val % TAM;
}

string MemoriaInstrucao::read(){
    return dados[address];
}

void MemoriaInstrucao::set_wdata(string val){
    w_data = val;
}

void MemoriaInstrucao::write(){
    dados[address] = w_data;
}

void MemoriaInstrucao::load_instructions(string filename){
	ifstream entrada;
	entrada.open(filename, ios_base::in);
    string linha;
    int pc = 0;
    while(getline(entrada, linha)){
        if(linha != "sair"){
            set_wdata(linha);
            set_address(pc * 4);
            write();
        }
        pc++;
    }
    n_instructions=pc;  

}

int MemoriaInstrucao::get_memory_size(){
    return TAM;
}

int MemoriaInstrucao::get_n_instructions(){
    return n_instructions;
}
