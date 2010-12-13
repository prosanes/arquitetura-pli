#ifndef _REGISTRADOR_H_
#define _REGISTRADOR_H_

class Registrador
{
    private:
        bool carrega;
        int reg;

    public:
        void sinal(bool sin);
        int& operator= (const int &op);
        int get();
};

#endif
