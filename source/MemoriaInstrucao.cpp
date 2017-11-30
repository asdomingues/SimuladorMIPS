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

void load_instructions(string filename){
	ifstream entrada;
	entrada.open("entrada.txt", ios_base::in);
    string linha;
    int pc = 0;
    while(getline(entrada, linha)){
        if(linha != "sair"){
            this.set_wdata(linha);
            this.set_address(pc * 4);
            this.write();
        }
        pc++;
    }
}
