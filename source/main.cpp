#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MemoriaInstrucao.hpp"
#include "BancoDeRegistradores.hpp"
#include "IFID.hpp"
#include "IDEXE.hpp"
#include "EXMEM.hpp"
#include "MEMWB.hpp"
#include "IF.hpp"
#include "ID.hpp"
#include "EX.hpp"
#include "WB.hpp"
#include "Memoria.hpp"
#include "Mem.hpp"
#include "Ula.hpp"

using namespace std;


int main(){

    MemoriaInstrucao memoria_instrucao;
    IFID ifid;
    ULA alu;
    EXMEM exmem;
    MEMWB memwb;
    void setRD(int rd);
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

    int numero = 0;
    while(numero != -1){
        printf("                              IF/ID                              ID/EXE                            EXE/MEM                               MEM/WB\n");
        printf("                              ____             Estágio            ____            Estágio            ____            Estágio              ____ \n");
        printf("       Estágio               |    |              ID              |    |             EXE             |    |             MEM               |    |\n");
        printf("          IF                 |    |                              |    |                             |    |                               |    |\n");
        printf("                             |    |          Registrador         |    |                             |    |          Memória de           |    |\n");
        printf(" ___       ____________      |    |      __________________      |    |            ULA              |    |            dados              |    |\n");
        printf("|   |     |Memoria     |     |    |---->|ReadReg1          |     |    |      _________________      |    |      ___________________      |    |\n");
        printf("|PC |     |   de       |     |    |     |  %3d      RdData1|---->|    |     |                 |     |    |     |                   |     |    |\n");
        printf("|   |---->|Instrucao   |---->|    |     |ReadReg2     %3d  |     |    |---->|ALUIN1           |     |    |---->|Address      RdData|---->|    |\n");
        printf("|%3d|     |%12s|     |    |---->|  %3d      RdData2|---->|    |     |           ALUOut|---->|    |     |                   |     |    |\n", /*ifstage.get_pc()*/0, /*IFID.getIR()*/"add R1, 100", ID.);
        printf("|___|     |____________|     |    |     |WrREG        %3d  |     |    |---->|ALUIN2           |     |    |     |                   |     |    |\n");
        printf("                             |    |     |  %3d             |     |    |     |_________________|     |    |---->|WrData             |     |    |\n");
        printf("                             |    |     |WrData            |     |    |                             |    |     |___________________|     |    |\n");
        printf("                             |    |     |  %3d             |     |    |                             |    |                               |    |\n");
        printf("                             |    |     |__________________|     |    |                             |    |                               |    |\n");
        printf("                             |    |                              |    |                             |    |                               |    |\n");
        printf("                             |____|                              |____|                             |____|                               |____|\n");
        cin >> numero;
        system("clear");
    }

    /*int numero = 0;
    while(numero != -1){
        printf("     ___       __________    \n");
        printf("    |   |     | Memoria  |   \n");
        printf("    |PC |     |    de    |   \n");
        printf("    |   |     | Instrucao|   \n");
        printf("    |%3d|->   |          |   \n", numero);
        printf("    |___|     |__________|   \n");
        for(int i = 100000000; i > 0; i--);
        system("clear");
        printf("     ___       __________    \n");
        printf("    |   |     | Memoria  |   \n");
        printf("    |PC |     |    de    |   \n");
        printf("    |   |     | Instrucao|   \n");
        printf("    |%3d|-->  |          |   \n", numero);
        printf("    |___|     |__________|   \n");
        for(int i = 100000000; i > 0; i--);
        system("clear");
        printf("     ___       __________    \n");
        printf("    |   |     | Memoria  |   \n");
        printf("    |PC |     |    de    |   \n");
        printf("    |   |     | Instrucao|   \n");
        printf("    |%3d|---> |          |   \n", numero);
        printf("    |___|     |__________|   \n");
        for(int i = 100000000; i > 0; i--);
        system("clear");
        printf("     ___       __________    \n");
        printf("    |   |     | Memoria  |   \n");
        printf("    |PC |     |    de    |   \n");
        printf("    |   |     | Instrucao|   \n");
        printf("    |%3d|---->|          |   \n", numero);
        printf("    |___|     |__________|   \n");
        for(int i = 100000000; i > 0; i--);
        system("clear");
        //cin >> numero;
    }*/

    return 0;
}

// PC,
