//Obs: Achei que ficaria mais fiel a arquitetura esse formato de ULA mas se quiserem mudar so alterar as funcoes
#ifndef ULA_H
#define ULA_H
#include <string>

#define NBITS 8

using namespace std;

class Ula
{
    public:
        string aluOP;
        Ula();
        int operation();
        void set_aluIN1(int valor);
        void set_aluIN2(int valor);
        void set_aluOP(string valor);
		int get_aluOUT();
    private:
        int aluIN1 = 0, aluIN2 = 0, aluOUT = 0;
};

#endif // ULA_H
