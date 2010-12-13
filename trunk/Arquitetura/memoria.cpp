#include "memoria.h"

int Memoria::acesso(bool le_esc, int endereco, int entrada)
{
    if (endereco < MAX && endereco >= 0)
    {
        if (le_esc == false)
        {
            return memoria[endereco];
        }
        else
        {
            memoria[endereco] = entrada;
            return 0;
        }
    }
}
