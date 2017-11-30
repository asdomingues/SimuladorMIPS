#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MemoriaInstrucao.hpp"
#include "BancoDeRegistradores.hpp"

using namespace std;


int main(){
    MemoriaInstrucao m;
    BancoDeRegistradores b(32);
    m.load_instructions("entrada.txt");


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
