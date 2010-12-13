#include <stdio.h>
#include "unidade_controle.h"
#include "memoria.h"
#include "multiplexador.h"
#include "registrador.h"

int main (void)
{
    //TESTE DE MEMORIA
    Memoria memoria;
    memoria.acesso(1, 2, 35);
    printf("%d\n", memoria.acesso(0, 2, 0));

    //TESTE DAS flags
    Flags flag_ula;
    flag_ula.zero = 0;
    flag_ula.negativo = 0;
    flag_ula.carry = 0;

    //TESTE DE UC
    Unidade_Controle UC(0);
    int registrador_instrucao = 0;

        //Instrucao
    UC.start(flag_ula);
    {
        UC.ciclo_de_maquina(registrador_instrucao, flag_ula);
        UC.registrador_controle.print();
    }

    //Teste do registrador
    Registrador Rend;
    Rend.sinal(true);
    Rend = 3;
    printf("Rend: %d\n", Rend.get());
    Rend.sinal(false);
    Rend = 10;
    printf("Rend: %d\n", Rend.get());

    //Teste do multiplexador
    Multiplexador muxa;
    muxa.sinais_controle(0,0);
    printf("multiplex: %d\n", muxa.multiplexa(2, 3, 4, 5));
    muxa.sinais_controle(0,1);
    printf("multiplex: %d\n", muxa.multiplexa(2, 3, 4, 5));

    ULA ula;
    ula.sinais_controle(0,0,1,0,1);
    printf("ula: %x\n", ula.operacao(0x0001, 0x0002));

    return 0;
}
