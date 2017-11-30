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
    Ula alu;
    EXMEM exmem;
    MEMWB memwb;
    IDEXE idexe;
    BancoDeRegistradores banco(32);
    memoria_instrucao.load_instructions("instrucoes.in");

    //criar todos os estagios
    IF ifstage(&memoria_instrucao, &ifid, &exmem);
    ID idstage(&banco, &ifid, &idexe);
    EX exstage(&alu, &idexe, &exmem);
    Mem memstage(&exmem, &memwb, "registrador.in");
    WB wbstage(&banco, &memwb);

    while(ifstage.get_pc()<memoria_instrucao.get_n_instructions()*4){
        ifstage.tick();
        idstage.tick();
        exstage.tick();
        ifstage.read_exmem();
        memstage.tick();
        wbstage.tick();
        cout << "ifid: " << ifid.getIR() << " " << ifid.getNPC() << endl;
        cout << "idexe: " << idexe.getIR() << " " << idexe.getNPC() << endl;
        cout << "exmem: " << exmem.get_ir() << " " << endl;
        cout << "memwb: " << memwb.getir() << " " << endl;
	cout << "in1 :" << idexe.getA() << endl;
	cout << "in2 :" << idexe.getB() << endl;
	cout << "aluout: " << exmem.get_alu_out() << " " << endl;
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
