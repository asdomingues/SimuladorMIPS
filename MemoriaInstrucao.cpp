#include "MemoriaInstrucao.hpp"

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
