#include "multiplexador.h"

void Multiplexador::sinais_controle(bool s2, bool s1, bool s0)
{
    sinal0 = s0;
    sinal1 = s1;
    sinal2 = s2;
}

int Multiplexador::multiplexa(int a, int b, int c, int d, int e)
{
    if (sinal2 == false && sinal1 == false && sinal0 == false)
        return a;

    if (sinal2 == false && sinal1 == false && sinal0 == true)
        return b;

    if (sinal2 == false && sinal1 == true && sinal0 == false)
        return c;

    if (sinal2 == false && sinal1 == true && sinal0 == true)
        return d;

    return e;
}
