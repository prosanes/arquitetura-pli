#include "registrador.h"

void Registrador::sinal(bool sin)
{
    carrega = sin;
}

int& Registrador::operator= (const int &op)
{
    if (carrega == true)
    {
        reg = op;
        return reg;
    }

    return reg;
}

int Registrador::get()
{
    return reg;
}
