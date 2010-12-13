#ifndef _MEMORIA_H_
#define _MEMORIA_H_

class Memoria
{
    private:
        const static int MAX = 65536;
        int memoria[MAX];

    public:
        int acesso(bool le_esc, int endereco, int entrada);
};

#endif
