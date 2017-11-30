#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MemoriaInstrucao.hpp"
#include "BancoDeRegistradores.hpp"

using namespace std;


int main(){

    MemoriaInstrucao memoria_instrucao;
    IFID ifid;
    ULA alu;
    EXMEM exmem;
    MEMWB memwb;
    IDEXE idexe;
    BancoDeRegistradores banco(32);
    memoria_instrucao.load_instructions("entrada.txt");

    //criar todos os estagios
    IF ifstage(&memoria_instrucao, &ifid, &exmem);
    ID idstage(&banco, &ifid, &idexe);
    EX exstage(&alu, &idexe, &exmem);
    MEM memstage(&exmem, &memwb);
    WB wbstage(&banco, &memwb);

    for(int i=0; i<memoria_instrucao.get_n_instructions(); i++){
        ifstage.tick();
        idstage.tick();
        exstage.tick();
        memstage.tick();
        wbstage.tick();
    }



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
