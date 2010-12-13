/**
*   Faltam uns sinais de controle!
*/

#include "ULA.h"
#include <stdio.h>

void ULA::sinais_controle(bool s, bool t, bool u, bool v, bool x)
{
    sinais[0] = x;
    sinais[1] = v;
    sinais[2] = u;
    sinais[3] = t;
    sinais[4] = s;
}

int ULA::operacao(int a, int b)
{
    //00000
    if (sinais[0] == false &&
        sinais[1] == false &&
        sinais[2] == false &&
        sinais[3] == false &&
        sinais[4] == false )
    {
        return a;
    }
    //00001
    else if (sinais[0] == true &&
            sinais[1] == false &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == false )
    {
        return b;
    }
    //00010
    else if (sinais[0] == false &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == false )
    {
        return b+1;
    }
    //00011
    else if (sinais[0] == true &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == false )
    {
		long long temp = ((long long) a) + b;
		if (temp != a + b)
			flags.carry = 1;
		else
			flags.carry = 0;
		if (a + b == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if (a + b < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a+b;
    }
    //00100
    else if (sinais[0] == false &&
            sinais[1] == false &&
            sinais[2] == true &&
            sinais[3] == false &&
            sinais[4] == false )
    {
		long long temp = ((long long) a) - b;
		if (temp != a - b)
			flags.carry = 1;
		else
			flags.carry = 0;
		if (a - b == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if (a - b < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a-b;
    }
    //00101
    else if (sinais[0] == true &&
            sinais[1] == false &&
            sinais[2] == true &&
            sinais[3] == false &&
            sinais[4] == false )
    {
		long long temp = ((long long) b) - a;
		if (temp != b - a)
			flags.carry = 1;
		else
			flags.carry = 0;
		if (b - a == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if (b - a < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return b-a;
    }
    //00110
    else if (sinais[0] == false &&
            sinais[1] == true &&
            sinais[2] == true &&
            sinais[3] == false &&
            sinais[4] == false )
    {
		flags.carry = 0;
		if ((a & b) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a & b) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a & b;
    }
    //00111
    else if (sinais[0] == true &&
            sinais[1] == true &&
            sinais[2] == true &&
            sinais[3] == false &&
            sinais[4] == false )
    {
		flags.carry = 0;
		if ((a | b) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a | b) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a | b;
    }
    //01000
    else if (sinais[0] == false &&
            sinais[1] == false &&
            sinais[2] == false &&
            sinais[3] == true &&
            sinais[4] == false )
    {
        return ~a;
    }
    //01001
    else if (sinais[0] == true &&
            sinais[1] == false &&
            sinais[2] == false &&
            sinais[3] == true &&
            sinais[4] == false )
    {
        return ~b;
    }
    //01010
    else if (sinais[0] == false &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == true &&
            sinais[4] == false )
    {
        return 0;
    }
    //01011
    else if (sinais[0] == true &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == true &&
            sinais[4] == false )
    {
        return 0 - a;
    }
    //01100
    else if (sinais[0] == false &&
            sinais[1] == false &&
            sinais[2] == true &&
            sinais[3] == true &&
            sinais[4] == false )
    {
        return 0 - b;
    }
    //01101
    else if (sinais[0] == true &&
            sinais[1] == false &&
            sinais[2] == true &&
            sinais[3] == true &&
            sinais[4] == false )
    {
		long long temp = ((long long) a) << 1;
		if (temp != a << 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((a << 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a << 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a << 1;
    }
    //01110
    else if (sinais[0] == false &&
            sinais[1] == true &&
            sinais[2] == true &&
            sinais[3] == true &&
            sinais[4] == false )
    {
		long long temp = ((long long) b) << 1;
		if (temp != b << 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((b << 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((b << 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return b << 1;
    }
    //01111
    else if (sinais[0] == true &&
            sinais[1] == true &&
            sinais[2] == true &&
            sinais[3] == true &&
            sinais[4] == false )
    {
		long long temp = ((long long) a) >> 1;
		if (temp != a >> 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((a >> 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a >> 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a >> 1;
    }
    //10000
    else if (sinais[0] == false &&
            sinais[1] == false &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == true )
    {
		long long temp = ((long long) b) >> 1;
		if (temp != b >> 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((b >> 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((b >> 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return b >> 1;
    }

	//10001
    else if (sinais[0] == true &&
            sinais[1] == false &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == true )
    {
		long long temp = ((long long) a) + 1;
		if (temp != a + 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((a + 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a + 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a + 1;
    }

	//10010
    else if (sinais[0] == false &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == true )
    {
		long long temp = ((long long) b) + 1;
		if (temp != b + 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((b + 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((b + 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return b + 1;
    }

	//10011
    else if (sinais[0] == true &&
            sinais[1] == true &&
            sinais[2] == false &&
            sinais[3] == false &&
            sinais[4] == true )
    {
		long long temp = ((long long) a) - 1;
		if (temp != a - 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((a - 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((a - 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return a - 1;
    }

	//10100
    else if (sinais[0] == false &&
            sinais[1] == false &&
            sinais[2] == true &&
            sinais[3] == false &&
            sinais[4] == true )
    {
		long long temp = ((long long) b) - 1;
		if (temp != b - 1)
			flags.carry = 1;
		else
			flags.carry = 0;
		if ((b - 1) == 0)
			flags.zero = 1;
		else
			flags.zero = 0;
		if ((b - 1) < 0)
			flags.negativo = 1;
		else
			flags.negativo = 0;
        return b - 1;
    }

    return -1;
}


Flags ULA::get_flags()
{
    return flags;
}
