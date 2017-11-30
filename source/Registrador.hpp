#ifndef REGISTRADOR_HPP
#define REGISTRADOR_HPP
#include <string>
#define VALOR_MAX 256 //2^8

using namespace std;

class Registrador{
private:
    string nome;
    int valor;
public:
    Registrador(string nome);

    string get_nome();
    int get_valor();
    void set_valor(int valor);
};

#endif // REGISTRADOR_H
