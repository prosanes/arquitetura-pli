#ifndef _UNIDADE_CONTROLE_H_
#define _UNIDADE_CONTROLE_H_

#include "ULA.h"

#include <stdio.h>

#define MAX_CONTROLES 23
class Ponto_Controle
{
    public:
        bool controle[MAX_CONTROLES];
        void print()
        {
            for (int i = 0; i < MAX_CONTROLES; i++)
                printf("%d", controle[i]);
            printf("\n");
        }
};

class Unidade_Controle
{
    private:
        //Consts
        const static int MAX_MICROS = 230;
        //Variaveis
        Ponto_Controle memoria_controle[MAX_MICROS];
        int registrador_endereco;
        int registrador_instrucao_interno;
        //Metodos internos
        int gerador_endereco(int instrucao, Flags flags_ula);

    public:
        //Variaveis publicas
        Ponto_Controle registrador_controle;
        //Metodos externos
        Unidade_Controle(int a);
        void ciclo_de_maquina(int instrucao, Flags flags_ula);
        void start(Flags flags_ula);

};

#endif
