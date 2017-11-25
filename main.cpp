#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "MemoriaInstrucao.hpp"

using namespace std;

int main(int argc, char *argv[]){
    ifstream entrada;
    entrada.open("entrada.txt", ios_base::in);
    string linha;
    MemoriaInstrucao m;
    while(getline(entrada, linha)){
        if(linha != "sair"){
            m.set_wdata(linha);
            m.write();
        }
    }

    return 0;
}
