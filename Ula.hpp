//Obs: Achei que ficaria mais fiel a arquitetura esse formato de ULA mas se quiserem mudar so alterar as funcoes
#ifndef ULA_H
#define ULA_H
#include <string>

#define NBITS 8

class Ula
{
    public:
        string aluOP;
        Ula();
        int operation();
        void set_aluIN1(int valor);
        void set_aluIN2(int valor);
        void set_aluOP(string valor);
    private:
        int aluIN1, aluIN2, aluOUT;
};

#endif // ULA_H
