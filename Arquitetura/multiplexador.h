#ifndef _MULTIPLEXADOR_H_
#define _MULTIPLEXADOR_H_

class Multiplexador
{
    private:
        bool sinal0;
        bool sinal1;
        bool sinal2;

    public:
        void sinais_controle(bool s2, bool s1, bool s0);
        int multiplexa(int a, int b, int c, int d, int e);

};

#endif
