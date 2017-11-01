#ifndef REGISTRADOR_HPP
#define REGISTRADOR_HPP

#define valor_max 256 //2^8

using namespace std;

class Registrador{
private:
    int nome;
    int valor;
public:
    Registrador(int nome);

    int get_nome();
    int get_valor();
    void set_valor(int valor);
};

#endif // REGISTRADOR_H
