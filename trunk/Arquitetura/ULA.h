#ifndef _ULA_H_
#define _ULA_H_

struct Flags
{
    bool zero;
    bool negativo;
    bool carry;
};

class ULA
{
    private:
        Flags flags;
        bool sinais[5];

    public:
        void sinais_controle(bool s, bool t, bool u, bool v, bool x);
        int operacao(int a, int b);
        Flags get_flags();
};

#endif
