#include "unidade_controle.h"

#include <stdio.h>
#include <stdlib.h>

/**
*   Inicializa a memoria de controle da unidade de controle.
*   Usa-se um arquivo binario para carregar na memoria de controle.
*/
Unidade_Controle::Unidade_Controle()
{

}

Unidade_Controle::Unidade_Controle(int a)
{
    //Inicializar memoria de controle
    FILE* entrada;
    entrada = fopen("memoria_controle_binario.txt", "r");
        if (!entrada)
        {
                printf ("Erro ao abrir arquivo de memoria.\n");
                return;
        }

    int i = 0;
    while ( !feof(entrada) )
    {
        char c;
        for (int j = 0; j < MAX_CONTROLES; j++)
        {
            fscanf(entrada, " %c", &c);
            memoria_controle[i].controle[j] = c - '0';
        }

        i++;
    }

    fclose(entrada);

    /* DEBUG */
    #ifdef DEBUG
        printf("Memoria de controle:\n");
        for (int i = 0; i < MAX_MICROS; i++)
        {
            printf("%d: ", i);
            for (int j = 0; j < MAX_CONTROLES; j++)
                printf("%d", memoria_controle[i].controle[j]);
            printf("\n");
        }
    #endif

    //Inicializa Registrador de Endereco
    registrador_endereco = 0;
}

/**
*   Dado a intrucao atual, a micro-instrucao atual e as flags da ultima operacao na ULA
*   retorna o endereco da proxima micro
*/
int Unidade_Controle::gerador_endereco(int instrucao, Flags flags_ula)
{
        /*case 0: //Ler instrucao e decodificar
            switch (registrador_endereco)
            {
                case 0:
                    return 4;
                case 4:
                    return 3;
                case 3:
                    return 217;
                case 217:
                    return 0;
            }
        break;*/

    switch(instrucao)
    {
        case 0:
            switch (registrador_endereco)
            {
                case 0:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 3;
                case 3:
                    return 217;
                case 217:
                    return 0;
            }

        case 1:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 54;
                case 54:
                    return 0;
            }
        break;

        case 2:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 84;
                case 84:
                    return 0;
            }
        break;

        case 3:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 4:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 5:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 6:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 7:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 8:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 9:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 10:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 11:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 54;
                case 54:
                    return 0;
            }
        break;

        case 12:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 84;
                case 84:
                    return 0;
            }
        break;

        case 13:
            switch (registrador_endereco)
            {
                case 0:
                    return 115;
                case 115:
                    return 0;
            }
        break;

        case 14:
            switch (registrador_endereco)
            {
                case 0:
                    return 141;
                case 141:
                    return 0;
            }
        break;

        case 15:
            switch (registrador_endereco)
            {
                case 0:
                    return 167;
                case 167:
                    return 0;
            }
        break;

        case 16:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 54;
                case 54:
                    return 0;
            }
        break;

        case 17:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 84;
                case 84:
                    return 0;
            }
        break;

        case 18:
            switch (registrador_endereco)
            {
                case 0:
                    return 116;
                case 116:
                    return 0;
            }
        break;

        case 19:
            switch (registrador_endereco)
            {
                case 0:
                    return 142;
                case 142:
                    return 0;
            }
        break;

        case 20:
            switch (registrador_endereco)
            {
                case 0:
                    return 168;
                case 168:
                    return 0;
            }
        break;

        case 21:
            switch (registrador_endereco)
            {
                case 0:
                    return 55;
                case 55:
                    return 0;
            }
        break;

        case 22:
            switch (registrador_endereco)
            {
                case 0:
                    return 85;
                case 85:
                    return 0;
            }
        break;

        case 23:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 117;
                case 117:
                    return 0;
            }
        break;

        case 24:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 143;
                case 143:
                    return 0;
            }
        break;

        case 25:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 169;
                case 169:
                    return 0;
            }
        break;

        case 26:
            switch (registrador_endereco)
            {
                case 0:
                    return 56;
                case 56:
                    return 0;
            }
        break;

        case 27:
            switch (registrador_endereco)
            {
                case 0:
                    return 86;
                case 86:
                    return 0;
            }
        break;

        case 28:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 117;
                case 117:
                    return 0;
            }
        break;

        case 29:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 143;
                case 143:
                    return 0;
            }
        break;

        case 30:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 169;
                case 169:
                    return 0;
            }
        break;

        case 31:
            switch (registrador_endereco)
            {
                case 0:
                    return 57;
                case 57:
                    return 0;
            }
        break;

        case 32:
            switch (registrador_endereco)
            {
                case 0:
                    return 87;
                case 87:
                    return 0;
            }
        break;

        case 33:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 117;
                case 117:
                    return 0;
            }
        break;

        case 34:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 143;
                case 143:
                    return 0;
            }
        break;

        case 35:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 169;
                case 169:
                    return 0;
            }
        break;

        case 36:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 37:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 38:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 39:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 40:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 41:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 42:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 43:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 44:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 45:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 46:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 23;
                case 23:
                    return 0;
            }
        break;

        case 47:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 23;
                case 23:
                    return 0;
            }
        break;

        case 48:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 23;
                case 23:
                    return 0;
            }
        break;

        case 49:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 23;
                case 23:
                    return 0;
            }
        break;

        case 50:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 23;
                case 23:
                    return 0;
            }
        break;

        case 51:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 24;
                case 24:
                    return 0;
            }
        break;

        case 52:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 24;
                case 24:
                    return 0;
            }
        break;

        case 53:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 24;
                case 24:
                    return 0;
            }
        break;

        case 54:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 24;
                case 24:
                    return 0;
            }
        break;

        case 55:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 24;
                case 24:
                    return 0;
            }
        break;

        case 56:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 25;
                case 25:
                    return 0;
            }
        break;

        case 57:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 25;
                case 25:
                    return 0;
            }
        break;

        case 58:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 25;
                case 25:
                    return 0;
            }
        break;

        case 59:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 25;
                case 25:
                    return 0;
            }
        break;

        case 60:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 25;
                case 25:
                    return 0;
            }
        break;

        case 61:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 58;
                case 58:
                    return 0;
            }
        break;

        case 62:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 88;
                case 88:
                    return 0;
            }
        break;

        case 63:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 64:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 65:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 66:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 58;
                case 58:
                    return 0;
            }
        break;

        case 67:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 88;
                case 88:
                    return 0;
            }
        break;

        case 68:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 69:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 70:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 71:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 58;
                case 58:
                    return 0;
            }
        break;

        case 72:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 88;
                case 88:
                    return 0;
            }
        break;

        case 73:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 74:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 75:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 76:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 58;
                case 58:
                    return 0;
            }
        break;

        case 77:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 88;
                case 88:
                    return 0;
            }
        break;

        case 78:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 79:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 80:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 81:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 58;
                case 58:
                    return 0;
            }
        break;

        case 82:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 88;
                case 88:
                    return 0;
            }
        break;

        case 83:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 114;
                case 114:
                    return 0;
            }
        break;

        case 84:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 140;
                case 140:
                    return 0;
            }
        break;

        case 85:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 166;
                case 166:
                    return 0;
            }
        break;

        case 86:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 87:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 88:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 89:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 90:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 91:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 92:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 93:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 94:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 95:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 96:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 97:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 98:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 99:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 100:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 101:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 102:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 103:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 104:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 105:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 106:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 107:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 108:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 109:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 110:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 22;
                case 22:
                    return 0;
            }
        break;

        case 111:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 59;
                case 59:
                    return 0;
            }
        break;

        case 112:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 89;
                case 89:
                    return 0;
            }
        break;

        case 113:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 114:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 115:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 116:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 117:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 118:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 119:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 120:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 121:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 59;
                case 59:
                    return 0;
            }
        break;

        case 122:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 89;
                case 89:
                    return 0;
            }
        break;

        case 123:
            switch (registrador_endereco)
            {
                case 0:
                    return 119;
                case 119:
                    return 0;
            }
        break;

        case 124:
            switch (registrador_endereco)
            {
                case 0:
                    return 145;
                case 145:
                    return 0;
            }
        break;

        case 125:
            switch (registrador_endereco)
            {
                case 0:
                    return 171;
                case 171:
                    return 0;
            }
        break;

        case 126:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 59;
                case 59:
                    return 0;
            }
        break;

        case 127:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 89;
                case 89:
                    return 0;
            }
        break;

        case 128:
            switch (registrador_endereco)
            {
                case 0:
                    return 120;
                case 120:
                    return 0;
            }
        break;

        case 129:
            switch (registrador_endereco)
            {
                case 0:
                    return 146;
                case 146:
                    return 0;
            }
        break;

        case 130:
            switch (registrador_endereco)
            {
                case 0:
                    return 172;
                case 172:
                    return 0;
            }
        break;

        case 131:
            switch (registrador_endereco)
            {
                case 0:
                    return 60;
                case 60:
                    return 0;
            }
        break;

        case 132:
            switch (registrador_endereco)
            {
                case 0:
                    return 90;
                case 90:
                    return 0;
            }
        break;

        case 133:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 121;
                case 121:
                    return 0;
            }
        break;

        case 134:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 147;
                case 147:
                    return 0;
            }
        break;

        case 135:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 173;
                case 173:
                    return 0;
            }
        break;

        case 136:
            switch (registrador_endereco)
            {
                case 0:
                    return 61;
                case 61:
                    return 0;
            }
        break;

        case 137:
            switch (registrador_endereco)
            {
                case 0:
                    return 91;
                case 91:
                    return 0;
            }
        break;

        case 138:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 121;
                case 121:
                    return 0;
            }
        break;

        case 139:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 147;
                case 147:
                    return 0;
            }
        break;

        case 140:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 173;
                case 173:
                    return 0;
            }
        break;

        case 141:
            switch (registrador_endereco)
            {
                case 0:
                    return 62;
                case 62:
                    return 0;
            }
        break;

        case 142:
            switch (registrador_endereco)
            {
                case 0:
                    return 92;
                case 92:
                    return 0;
            }
        break;

        case 143:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 121;
                case 121:
                    return 0;
            }
        break;

        case 144:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 147;
                case 147:
                    return 0;
            }
        break;

        case 145:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 173;
                case 173:
                    return 0;
            }
        break;

        case 146:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 147:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 148:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 149:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 150:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 151:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 152:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 153:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 154:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 155:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 156:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 27;
                case 27:
                    return 0;
            }
        break;

        case 157:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 27;
                case 27:
                    return 0;
            }
        break;

        case 158:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 27;
                case 27:
                    return 0;
            }
        break;

        case 159:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 27;
                case 27:
                    return 0;
            }
        break;

        case 160:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 27;
                case 27:
                    return 0;
            }
        break;

        case 161:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 28;
                case 28:
                    return 0;
            }
        break;

        case 162:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 28;
                case 28:
                    return 0;
            }
        break;

        case 163:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 28;
                case 28:
                    return 0;
            }
        break;

        case 164:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 28;
                case 28:
                    return 0;
            }
        break;

        case 165:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 28;
                case 28:
                    return 0;
            }
        break;

        case 166:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 29;
                case 29:
                    return 0;
            }
        break;

        case 167:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 29;
                case 29:
                    return 0;
            }
        break;

        case 168:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 29;
                case 29:
                    return 0;
            }
        break;

        case 169:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 29;
                case 29:
                    return 0;
            }
        break;

        case 170:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 29;
                case 29:
                    return 0;
            }
        break;

        case 171:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 63;
                case 63:
                    return 0;
            }
        break;

        case 172:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 93;
                case 93:
                    return 0;
            }
        break;

        case 173:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 174:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 175:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 176:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 63;
                case 63:
                    return 0;
            }
        break;

        case 177:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 93;
                case 93:
                    return 0;
            }
        break;

        case 178:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 179:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 180:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 181:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 63;
                case 63:
                    return 0;
            }
        break;

        case 182:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 93;
                case 93:
                    return 0;
            }
        break;

        case 183:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 184:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 185:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 186:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 63;
                case 63:
                    return 0;
            }
        break;

        case 187:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 93;
                case 93:
                    return 0;
            }
        break;

        case 188:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 189:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 190:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 191:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 63;
                case 63:
                    return 0;
            }
        break;

        case 192:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 93;
                case 93:
                    return 0;
            }
        break;

        case 193:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 118;
                case 118:
                    return 0;
            }
        break;

        case 194:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 144;
                case 144:
                    return 0;
            }
        break;

        case 195:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 170;
                case 170:
                    return 0;
            }
        break;

        case 196:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 197:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 198:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 199:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 200:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 201:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 202:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 203:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 204:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 205:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 206:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 207:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 208:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 209:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 210:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 211:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 212:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 213:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 214:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 215:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 216:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 217:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 218:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 219:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 220:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 26;
                case 26:
                    return 0;
            }
        break;

        case 221:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 222:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 223:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 224:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 225:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 226:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 10;
                case 10:
                    return 0;
            }
        break;

        case 227:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 11;
                case 11:
                    return 0;
            }
        break;

        case 228:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 12;
                case 12:
                    return 0;
            }
        break;

        case 229:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 13;
                case 13:
                    return 0;
            }
        break;

        case 230:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 14;
                case 14:
                    return 0;
            }
        break;

        case 231:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 232:
            switch (registrador_endereco)
            {
                case 0:
                    return 95;
                case 95:
                    return 0;
            }
        break;

        case 233:
            switch (registrador_endereco)
            {
                case 0:
                    return 123;
                case 123:
                    return 0;
            }
        break;

        case 234:
            switch (registrador_endereco)
            {
                case 0:
                    return 149;
                case 149:
                    return 0;
            }
        break;

        case 235:
            switch (registrador_endereco)
            {
                case 0:
                    return 175;
                case 175:
                    return 0;
            }
        break;

        case 236:
            switch (registrador_endereco)
            {
                case 0:
                    return 65;
                case 65:
                    return 0;
            }
        break;

        case 237:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 238:
            switch (registrador_endereco)
            {
                case 0:
                    return 124;
                case 124:
                    return 0;
            }
        break;

        case 239:
            switch (registrador_endereco)
            {
                case 0:
                    return 150;
                case 150:
                    return 0;
            }
        break;

        case 240:
            switch (registrador_endereco)
            {
                case 0:
                    return 176;
                case 176:
                    return 0;
            }
        break;

        case 241:
            switch (registrador_endereco)
            {
                case 0:
                    return 66;
                case 66:
                    return 0;
            }
        break;

        case 242:
            switch (registrador_endereco)
            {
                case 0:
                    return 96;
                case 96:
                    return 0;
            }
        break;

        case 243:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 244:
            switch (registrador_endereco)
            {
                case 0:
                    return 151;
                case 151:
                    return 0;
            }
        break;

        case 245:
            switch (registrador_endereco)
            {
                case 0:
                    return 177;
                case 177:
                    return 0;
            }
        break;

        case 246:
            switch (registrador_endereco)
            {
                case 0:
                    return 67;
                case 67:
                    return 0;
            }
        break;

        case 247:
            switch (registrador_endereco)
            {
                case 0:
                    return 97;
                case 97:
                    return 0;
            }
        break;

        case 248:
            switch (registrador_endereco)
            {
                case 0:
                    return 125;
                case 125:
                    return 0;
            }
        break;

        case 249:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 250:
            switch (registrador_endereco)
            {
                case 0:
                    return 178;
                case 178:
                    return 0;
            }
        break;

        case 251:
            switch (registrador_endereco)
            {
                case 0:
                    return 68;
                case 68:
                    return 0;
            }
        break;

        case 252:
            switch (registrador_endereco)
            {
                case 0:
                    return 98;
                case 98:
                    return 0;
            }
        break;

        case 253:
            switch (registrador_endereco)
            {
                case 0:
                    return 126;
                case 126:
                    return 0;
            }
        break;

        case 254:
            switch (registrador_endereco)
            {
                case 0:
                    return 152;
                case 152:
                    return 0;
            }
        break;

        case 255:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 256:
            switch (registrador_endereco)
            {
                case 0:
                    return 15;
                case 15:
                    return 30;
                case 30:
                    return 0;
            }
        break;

        case 257:
            switch (registrador_endereco)
            {
                case 0:
                    return 16;
                case 16:
                    return 30;
                case 30:
                    return 0;
            }
        break;

        case 258:
            switch (registrador_endereco)
            {
                case 0:
                    return 17;
                case 17:
                    return 30;
                case 30:
                    return 0;
            }
        break;

        case 259:
            switch (registrador_endereco)
            {
                case 0:
                    return 18;
                case 18:
                    return 30;
                case 30:
                    return 0;
            }
        break;

        case 260:
            switch (registrador_endereco)
            {
                case 0:
                    return 19;
                case 19:
                    return 30;
                case 30:
                    return 0;
            }
        break;

        case 261:
            switch (registrador_endereco)
            {
                case 0:
                    return 15;
                case 15:
                    return 31;
                case 31:
                    return 0;
            }
        break;

        case 262:
            switch (registrador_endereco)
            {
                case 0:
                    return 16;
                case 16:
                    return 31;
                case 31:
                    return 0;
            }
        break;

        case 263:
            switch (registrador_endereco)
            {
                case 0:
                    return 17;
                case 17:
                    return 31;
                case 31:
                    return 0;
            }
        break;

        case 264:
            switch (registrador_endereco)
            {
                case 0:
                    return 18;
                case 18:
                    return 31;
                case 31:
                    return 0;
            }
        break;

        case 265:
            switch (registrador_endereco)
            {
                case 0:
                    return 19;
                case 19:
                    return 31;
                case 31:
                    return 0;
            }
        break;

        case 266:
            switch (registrador_endereco)
            {
                case 0:
                    return 15;
                case 15:
                    return 32;
                case 32:
                    return 0;
            }
        break;

        case 267:
            switch (registrador_endereco)
            {
                case 0:
                    return 16;
                case 16:
                    return 32;
                case 32:
                    return 0;
            }
        break;

        case 268:
            switch (registrador_endereco)
            {
                case 0:
                    return 17;
                case 17:
                    return 32;
                case 32:
                    return 0;
            }
        break;

        case 269:
            switch (registrador_endereco)
            {
                case 0:
                    return 18;
                case 18:
                    return 32;
                case 32:
                    return 0;
            }
        break;

        case 270:
            switch (registrador_endereco)
            {
                case 0:
                    return 19;
                case 19:
                    return 32;
                case 32:
                    return 0;
            }
        break;

        case 271:
            switch (registrador_endereco)
            {
                case 0:
                    return 15;
                case 15:
                    return 33;
                case 33:
                    return 0;
            }
        break;

        case 272:
            switch (registrador_endereco)
            {
                case 0:
                    return 16;
                case 16:
                    return 33;
                case 33:
                    return 0;
            }
        break;

        case 273:
            switch (registrador_endereco)
            {
                case 0:
                    return 17;
                case 17:
                    return 33;
                case 33:
                    return 0;
            }
        break;

        case 274:
            switch (registrador_endereco)
            {
                case 0:
                    return 18;
                case 18:
                    return 33;
                case 33:
                    return 0;
            }
        break;

        case 275:
            switch (registrador_endereco)
            {
                case 0:
                    return 19;
                case 19:
                    return 33;
                case 33:
                    return 0;
            }
        break;

        case 276:
            switch (registrador_endereco)
            {
                case 0:
                    return 15;
                case 15:
                    return 34;
                case 34:
                    return 0;
            }
        break;

        case 277:
            switch (registrador_endereco)
            {
                case 0:
                    return 16;
                case 16:
                    return 34;
                case 34:
                    return 0;
            }
        break;

        case 278:
            switch (registrador_endereco)
            {
                case 0:
                    return 17;
                case 17:
                    return 34;
                case 34:
                    return 0;
            }
        break;

        case 279:
            switch (registrador_endereco)
            {
                case 0:
                    return 18;
                case 18:
                    return 34;
                case 34:
                    return 0;
            }
        break;

        case 280:
            switch (registrador_endereco)
            {
                case 0:
                    return 19;
                case 19:
                    return 34;
                case 34:
                    return 0;
            }
        break;

        case 281:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 282:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 283:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 284:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 285:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 286:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 287:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 288:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 289:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 290:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 291:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 292:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 293:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 294:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 295:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 296:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 297:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 298:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 299:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 300:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 301:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 64;
                case 64:
                    return 0;
            }
        break;

        case 302:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 94;
                case 94:
                    return 0;
            }
        break;

        case 303:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 122;
                case 122:
                    return 0;
            }
        break;

        case 304:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 148;
                case 148:
                    return 0;
            }
        break;

        case 305:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 174;
                case 174:
                    return 0;
            }
        break;

        case 306:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 307:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 11;
                case 11:
                    return 0;
            }
        break;

        case 308:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 12;
                case 12:
                    return 0;
            }
        break;

        case 309:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 13;
                case 13:
                    return 0;
            }
        break;

        case 310:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 14;
                case 14:
                    return 0;
            }
        break;

        case 311:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 10;
                case 10:
                    return 0;
            }
        break;

        case 312:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 313:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 12;
                case 12:
                    return 0;
            }
        break;

        case 314:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 13;
                case 13:
                    return 0;
            }
        break;

        case 315:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 14;
                case 14:
                    return 0;
            }
        break;

        case 316:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 10;
                case 10:
                    return 0;
            }
        break;

        case 317:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 11;
                case 11:
                    return 0;
            }
        break;

        case 318:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 319:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 13;
                case 13:
                    return 0;
            }
        break;

        case 320:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 14;
                case 14:
                    return 0;
            }
        break;

        case 321:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 10;
                case 10:
                    return 0;
            }
        break;

        case 322:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 11;
                case 11:
                    return 0;
            }
        break;

        case 323:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 12;
                case 12:
                    return 0;
            }
        break;

        case 324:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 325:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 14;
                case 14:
                    return 0;
            }
        break;

        case 326:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 10;
                case 10:
                    return 0;
            }
        break;

        case 327:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 11;
                case 11:
                    return 0;
            }
        break;

        case 328:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 12;
                case 12:
                    return 0;
            }
        break;

        case 329:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 13;
                case 13:
                    return 0;
            }
        break;

        case 330:
            switch (registrador_endereco)
            {
                case 0:
                    return 0;
            }
        break;

        case 331:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 192;
                case 192:
                    return 0;
            }
        break;

        case 332:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 196;
                case 196:
                    return 0;
            }
        break;

        case 333:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 334:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 335:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 336:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 337:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 338:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 339:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 340:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 341:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 192;
                case 192:
                    return 0;
            }
        break;

        case 342:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 196;
                case 196:
                    return 0;
            }
        break;

        case 343:
            switch (registrador_endereco)
            {
                case 0:
                    return 201;
                case 201:
                    return 0;
            }
        break;

        case 344:
            switch (registrador_endereco)
            {
                case 0:
                    return 205;
                case 205:
                    return 0;
            }
        break;

        case 345:
            switch (registrador_endereco)
            {
                case 0:
                    return 209;
                case 209:
                    return 0;
            }
        break;

        case 346:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 192;
                case 192:
                    return 0;
            }
        break;

        case 347:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 196;
                case 196:
                    return 0;
            }
        break;

        case 348:
            switch (registrador_endereco)
            {
                case 0:
                    return 202;
                case 202:
                    return 0;
            }
        break;

        case 349:
            switch (registrador_endereco)
            {
                case 0:
                    return 206;
                case 206:
                    return 0;
            }
        break;

        case 350:
            switch (registrador_endereco)
            {
                case 0:
                    return 210;
                case 210:
                    return 0;
            }
        break;

        case 351:
            switch (registrador_endereco)
            {
                case 0:
                    return 193;
                case 193:
                    return 0;
            }
        break;

        case 352:
            switch (registrador_endereco)
            {
                case 0:
                    return 197;
                case 197:
                    return 0;
            }
        break;

        case 353:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 203;
                case 203:
                    return 0;
            }
        break;

        case 354:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 207;
                case 207:
                    return 0;
            }
        break;

        case 355:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 211;
                case 211:
                    return 0;
            }
        break;

        case 356:
            switch (registrador_endereco)
            {
                case 0:
                    return 194;
                case 194:
                    return 0;
            }
        break;

        case 357:
            switch (registrador_endereco)
            {
                case 0:
                    return 198;
                case 198:
                    return 0;
            }
        break;

        case 358:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 203;
                case 203:
                    return 0;
            }
        break;

        case 359:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 207;
                case 207:
                    return 0;
            }
        break;

        case 360:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 211;
                case 211:
                    return 0;
            }
        break;

        case 361:
            switch (registrador_endereco)
            {
                case 0:
                    return 195;
                case 195:
                    return 0;
            }
        break;

        case 362:
            switch (registrador_endereco)
            {
                case 0:
                    return 199;
                case 199:
                    return 0;
            }
        break;

        case 363:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 203;
                case 203:
                    return 0;
            }
        break;

        case 364:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 207;
                case 207:
                    return 0;
            }
        break;

        case 365:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 211;
                case 211:
                    return 0;
            }
        break;

        case 366:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 367:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 368:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 369:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 370:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 371:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 372:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 373:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 374:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 375:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 376:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 213;
                case 213:
                    return 0;
            }
        break;

        case 377:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 213;
                case 213:
                    return 0;
            }
        break;

        case 378:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 213;
                case 213:
                    return 0;
            }
        break;

        case 379:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 213;
                case 213:
                    return 0;
            }
        break;

        case 380:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 213;
                case 213:
                    return 0;
            }
        break;

        case 381:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 214;
                case 214:
                    return 0;
            }
        break;

        case 382:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 214;
                case 214:
                    return 0;
            }
        break;

        case 383:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 214;
                case 214:
                    return 0;
            }
        break;

        case 384:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 214;
                case 214:
                    return 0;
            }
        break;

        case 385:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 214;
                case 214:
                    return 0;
            }
        break;

        case 386:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 215;
                case 215:
                    return 0;
            }
        break;

        case 387:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 215;
                case 215:
                    return 0;
            }
        break;

        case 388:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 215;
                case 215:
                    return 0;
            }
        break;

        case 389:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 215;
                case 215:
                    return 0;
            }
        break;

        case 390:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 215;
                case 215:
                    return 0;
            }
        break;

        case 391:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 392:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 393:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 394:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 395:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 396:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 397:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 398:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 399:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 400:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 401:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 402:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 403:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 404:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 405:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 406:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 407:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 408:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 409:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 410:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 411:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 412:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 216;
                case 216:
                    return 0;
            }
        break;

        case 413:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 200;
                case 200:
                    return 0;
            }
        break;

        case 414:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 204;
                case 204:
                    return 0;
            }
        break;

        case 415:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 208;
                case 208:
                    return 0;
            }
        break;

        case 416:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 417:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 418:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 419:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 420:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 421:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 422:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 423:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 424:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 425:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 426:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 427:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 428:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 429:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 430:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 431:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 432:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 433:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 434:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 435:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 436:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 437:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 438:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 439:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 440:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 212;
                case 212:
                    return 0;
            }
        break;

        case 441:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 69;
                case 69:
                    return 0;
            }
        break;

        case 442:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 99;
                case 99:
                    return 0;
            }
        break;

        case 443:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 444:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 445:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 446:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 447:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 448:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 449:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 450:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 451:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 69;
                case 69:
                    return 0;
            }
        break;

        case 452:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 99;
                case 99:
                    return 0;
            }
        break;

        case 453:
            switch (registrador_endereco)
            {
                case 0:
                    return 128;
                case 128:
                    return 0;
            }
        break;

        case 454:
            switch (registrador_endereco)
            {
                case 0:
                    return 154;
                case 154:
                    return 0;
            }
        break;

        case 455:
            switch (registrador_endereco)
            {
                case 0:
                    return 180;
                case 180:
                    return 0;
            }
        break;

        case 456:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 69;
                case 69:
                    return 0;
            }
        break;

        case 457:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 99;
                case 99:
                    return 0;
            }
        break;

        case 458:
            switch (registrador_endereco)
            {
                case 0:
                    return 129;
                case 129:
                    return 0;
            }
        break;

        case 459:
            switch (registrador_endereco)
            {
                case 0:
                    return 155;
                case 155:
                    return 0;
            }
        break;

        case 460:
            switch (registrador_endereco)
            {
                case 0:
                    return 181;
                case 181:
                    return 0;
            }
        break;

        case 461:
            switch (registrador_endereco)
            {
                case 0:
                    return 70;
                case 70:
                    return 0;
            }
        break;

        case 462:
            switch (registrador_endereco)
            {
                case 0:
                    return 100;
                case 100:
                    return 0;
            }
        break;

        case 463:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 130;
                case 130:
                    return 0;
            }
        break;

        case 464:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 156;
                case 156:
                    return 0;
            }
        break;

        case 465:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 182;
                case 182:
                    return 0;
            }
        break;

        case 466:
            switch (registrador_endereco)
            {
                case 0:
                    return 71;
                case 71:
                    return 0;
            }
        break;

        case 467:
            switch (registrador_endereco)
            {
                case 0:
                    return 101;
                case 101:
                    return 0;
            }
        break;

        case 468:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 130;
                case 130:
                    return 0;
            }
        break;

        case 469:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 156;
                case 156:
                    return 0;
            }
        break;

        case 470:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 182;
                case 182:
                    return 0;
            }
        break;

        case 471:
            switch (registrador_endereco)
            {
                case 0:
                    return 72;
                case 72:
                    return 0;
            }
        break;

        case 472:
            switch (registrador_endereco)
            {
                case 0:
                    return 102;
                case 102:
                    return 0;
            }
        break;

        case 473:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 130;
                case 130:
                    return 0;
            }
        break;

        case 474:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 156;
                case 156:
                    return 0;
            }
        break;

        case 475:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 182;
                case 182:
                    return 0;
            }
        break;

        case 476:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 477:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 478:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 479:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 480:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 481:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 482:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 483:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 484:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 485:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 486:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 36;
                case 36:
                    return 0;
            }
        break;

        case 487:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 36;
                case 36:
                    return 0;
            }
        break;

        case 488:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 36;
                case 36:
                    return 0;
            }
        break;

        case 489:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 36;
                case 36:
                    return 0;
            }
        break;

        case 490:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 36;
                case 36:
                    return 0;
            }
        break;

        case 491:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 37;
                case 37:
                    return 0;
            }
        break;

        case 492:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 37;
                case 37:
                    return 0;
            }
        break;

        case 493:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 37;
                case 37:
                    return 0;
            }
        break;

        case 494:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 37;
                case 37:
                    return 0;
            }
        break;

        case 495:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 37;
                case 37:
                    return 0;
            }
        break;

        case 496:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 38;
                case 38:
                    return 0;
            }
        break;

        case 497:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 38;
                case 38:
                    return 0;
            }
        break;

        case 498:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 38;
                case 38:
                    return 0;
            }
        break;

        case 499:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 38;
                case 38:
                    return 0;
            }
        break;

        case 500:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 38;
                case 38:
                    return 0;
            }
        break;

        case 501:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 73;
                case 73:
                    return 0;
            }
        break;

        case 502:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 103;
                case 103:
                    return 0;
            }
        break;

        case 503:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 504:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 505:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 506:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 73;
                case 73:
                    return 0;
            }
        break;

        case 507:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 103;
                case 103:
                    return 0;
            }
        break;

        case 508:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 509:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 510:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 511:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 73;
                case 73:
                    return 0;
            }
        break;

        case 512:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 103;
                case 103:
                    return 0;
            }
        break;

        case 513:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 514:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 515:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 516:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 73;
                case 73:
                    return 0;
            }
        break;

        case 517:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 103;
                case 103:
                    return 0;
            }
        break;

        case 518:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 519:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 520:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 521:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 73;
                case 73:
                    return 0;
            }
        break;

        case 522:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 103;
                case 103:
                    return 0;
            }
        break;

        case 523:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 127;
                case 127:
                    return 0;
            }
        break;

        case 524:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 153;
                case 153:
                    return 0;
            }
        break;

        case 525:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 179;
                case 179:
                    return 0;
            }
        break;

        case 526:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 527:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 528:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 529:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 530:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 531:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 532:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 533:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 534:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 535:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 536:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 537:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 538:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 539:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 540:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 541:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 542:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 543:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 544:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 545:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 546:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 547:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 548:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 549:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 550:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 35;
                case 35:
                    return 0;
            }
        break;

        case 551:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 74;
                case 74:
                    return 0;
            }
        break;

        case 552:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 104;
                case 104:
                    return 0;
            }
        break;

        case 553:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 554:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 555:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 556:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 557:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 558:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 559:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 560:
            switch (registrador_endereco)
            {
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 4:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 561:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 74;
                case 74:
                    return 0;
            }
        break;

        case 562:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 104;
                case 104:
                    return 0;
            }
        break;

        case 563:
            switch (registrador_endereco)
            {
                case 0:
                    return 132;
                case 132:
                    return 0;
            }
        break;

        case 564:
            switch (registrador_endereco)
            {
                case 0:
                    return 158;
                case 158:
                    return 0;
            }
        break;

        case 565:
            switch (registrador_endereco)
            {
                case 0:
                    return 184;
                case 184:
                    return 0;
            }
        break;

        case 566:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 74;
                case 74:
                    return 0;
            }
        break;

        case 567:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 104;
                case 104:
                    return 0;
            }
        break;

        case 568:
            switch (registrador_endereco)
            {
                case 0:
                    return 133;
                case 133:
                    return 0;
            }
        break;

        case 569:
            switch (registrador_endereco)
            {
                case 0:
                    return 159;
                case 159:
                    return 0;
            }
        break;

        case 570:
            switch (registrador_endereco)
            {
                case 0:
                    return 185;
                case 185:
                    return 0;
            }
        break;

        case 571:
            switch (registrador_endereco)
            {
                case 0:
                    return 75;
                case 75:
                    return 0;
            }
        break;

        case 572:
            switch (registrador_endereco)
            {
                case 0:
                    return 105;
                case 105:
                    return 0;
            }
        break;

        case 573:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 134;
                case 134:
                    return 0;
            }
        break;

        case 574:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 160;
                case 160:
                    return 0;
            }
        break;

        case 575:
            switch (registrador_endereco)
            {
                case 0:
                    return 51;
                case 51:
                    return 186;
                case 186:
                    return 0;
            }
        break;

        case 576:
            switch (registrador_endereco)
            {
                case 0:
                    return 76;
                case 76:
                    return 0;
            }
        break;

        case 577:
            switch (registrador_endereco)
            {
                case 0:
                    return 106;
                case 106:
                    return 0;
            }
        break;

        case 578:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 134;
                case 134:
                    return 0;
            }
        break;

        case 579:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 160;
                case 160:
                    return 0;
            }
        break;

        case 580:
            switch (registrador_endereco)
            {
                case 0:
                    return 52;
                case 52:
                    return 186;
                case 186:
                    return 0;
            }
        break;

        case 581:
            switch (registrador_endereco)
            {
                case 0:
                    return 77;
                case 77:
                    return 0;
            }
        break;

        case 582:
            switch (registrador_endereco)
            {
                case 0:
                    return 107;
                case 107:
                    return 0;
            }
        break;

        case 583:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 134;
                case 134:
                    return 0;
            }
        break;

        case 584:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 160;
                case 160:
                    return 0;
            }
        break;

        case 585:
            switch (registrador_endereco)
            {
                case 0:
                    return 53;
                case 53:
                    return 186;
                case 186:
                    return 0;
            }
        break;

        case 586:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 587:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 588:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 589:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 590:
            switch (registrador_endereco)
            {
                case 0:
                    return 49;
                case 49:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 591:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 592:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 593:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 594:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 595:
            switch (registrador_endereco)
            {
                case 0:
                    return 50;
                case 50:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 596:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 40;
                case 40:
                    return 0;
            }
        break;

        case 597:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 40;
                case 40:
                    return 0;
            }
        break;

        case 598:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 40;
                case 40:
                    return 0;
            }
        break;

        case 599:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 40;
                case 40:
                    return 0;
            }
        break;

        case 600:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 40;
                case 40:
                    return 0;
            }
        break;

        case 601:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 41;
                case 41:
                    return 0;
            }
        break;

        case 602:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 41;
                case 41:
                    return 0;
            }
        break;

        case 603:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 41;
                case 41:
                    return 0;
            }
        break;

        case 604:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 41;
                case 41:
                    return 0;
            }
        break;

        case 605:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 41;
                case 41:
                    return 0;
            }
        break;

        case 606:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 42;
                case 42:
                    return 0;
            }
        break;

        case 607:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 42;
                case 42:
                    return 0;
            }
        break;

        case 608:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 42;
                case 42:
                    return 0;
            }
        break;

        case 609:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 42;
                case 42:
                    return 0;
            }
        break;

        case 610:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 42;
                case 42:
                    return 0;
            }
        break;

        case 611:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 78;
                case 78:
                    return 0;
            }
        break;

        case 612:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 108;
                case 108:
                    return 0;
            }
        break;

        case 613:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 614:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 615:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 616:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 78;
                case 78:
                    return 0;
            }
        break;

        case 617:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 108;
                case 108:
                    return 0;
            }
        break;

        case 618:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 619:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 620:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 621:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 78;
                case 78:
                    return 0;
            }
        break;

        case 622:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 108;
                case 108:
                    return 0;
            }
        break;

        case 623:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 624:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 625:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 626:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 78;
                case 78:
                    return 0;
            }
        break;

        case 627:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 108;
                case 108:
                    return 0;
            }
        break;

        case 628:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 629:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 630:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 631:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 49;
                case 49:
                    return 78;
                case 78:
                    return 0;
            }
        break;

        case 632:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 50;
                case 50:
                    return 108;
                case 108:
                    return 0;
            }
        break;

        case 633:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 131;
                case 131:
                    return 0;
            }
        break;

        case 634:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 157;
                case 157:
                    return 0;
            }
        break;

        case 635:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 183;
                case 183:
                    return 0;
            }
        break;

        case 636:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 637:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 638:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 639:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 640:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 641:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 642:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 643:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 644:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 645:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 646:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 647:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 648:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 649:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 650:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 651:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 652:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 653:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 654:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 655:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 9;
                case 9:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 656:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 5;
                case 5:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 657:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 6;
                case 6:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 658:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 7;
                case 7:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 659:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 8;
                case 8:
                    return 21;
                case 21:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 660:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 48;
                case 48:
                    return 39;
                case 39:
                    return 0;
            }
        break;

        case 661:
            switch (registrador_endereco)
            {
                case 0:
                    return 79;
                case 79:
                    return 0;
            }
        break;

        case 662:
            switch (registrador_endereco)
            {
                case 0:
                    return 109;
                case 109:
                    return 0;
            }
        break;

        case 663:
            switch (registrador_endereco)
            {
                case 0:
                    return 135;
                case 135:
                    return 0;
            }
        break;

        case 664:
            switch (registrador_endereco)
            {
                case 0:
                    return 161;
                case 161:
                    return 0;
            }
        break;

        case 665:
            switch (registrador_endereco)
            {
                case 0:
                    return 187;
                case 187:
                    return 0;
            }
        break;

        case 666:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 43;
                case 43:
                    return 0;
            }
        break;

        case 667:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 43;
                case 43:
                    return 0;
            }
        break;

        case 668:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 43;
                case 43:
                    return 0;
            }
        break;

        case 669:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 43;
                case 43:
                    return 0;
            }
        break;

        case 670:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 43;
                case 43:
                    return 0;
            }
        break;

        case 671:
            switch (registrador_endereco)
            {
                case 0:
                    return 80;
                case 80:
                    return 0;
            }
        break;

        case 672:
            switch (registrador_endereco)
            {
                case 0:
                    return 110;
                case 110:
                    return 0;
            }
        break;

        case 673:
            switch (registrador_endereco)
            {
                case 0:
                    return 136;
                case 136:
                    return 0;
            }
        break;

        case 674:
            switch (registrador_endereco)
            {
                case 0:
                    return 162;
                case 162:
                    return 0;
            }
        break;

        case 675:
            switch (registrador_endereco)
            {
                case 0:
                    return 188;
                case 188:
                    return 0;
            }
        break;

        case 676:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 44;
                case 44:
                    return 0;
            }
        break;

        case 677:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 44;
                case 44:
                    return 0;
            }
        break;

        case 678:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 44;
                case 44:
                    return 0;
            }
        break;

        case 679:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 44;
                case 44:
                    return 0;
            }
        break;

        case 680:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 44;
                case 44:
                    return 0;
            }
        break;

        case 681:
            switch (registrador_endereco)
            {
                case 0:
                    return 81;
                case 81:
                    return 0;
            }
        break;

        case 682:
            switch (registrador_endereco)
            {
                case 0:
                    return 111;
                case 111:
                    return 0;
            }
        break;

        case 683:
            switch (registrador_endereco)
            {
                case 0:
                    return 137;
                case 137:
                    return 0;
            }
        break;

        case 684:
            switch (registrador_endereco)
            {
                case 0:
                    return 163;
                case 163:
                    return 0;
            }
        break;

        case 685:
            switch (registrador_endereco)
            {
                case 0:
                    return 189;
                case 189:
                    return 0;
            }
        break;

        case 686:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 45;
                case 45:
                    return 0;
            }
        break;

        case 687:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 45;
                case 45:
                    return 0;
            }
        break;

        case 688:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 45;
                case 45:
                    return 0;
            }
        break;

        case 689:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 45;
                case 45:
                    return 0;
            }
        break;

        case 690:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 45;
                case 45:
                    return 0;
            }
        break;

        case 691:
            switch (registrador_endereco)
            {
                case 0:
                    return 82;
                case 82:
                    return 0;
            }
        break;

        case 692:
            switch (registrador_endereco)
            {
                case 0:
                    return 112;
                case 112:
                    return 0;
            }
        break;

        case 693:
            switch (registrador_endereco)
            {
                case 0:
                    return 138;
                case 138:
                    return 0;
            }
        break;

        case 694:
            switch (registrador_endereco)
            {
                case 0:
                    return 164;
                case 164:
                    return 0;
            }
        break;

        case 695:
            switch (registrador_endereco)
            {
                case 0:
                    return 190;
                case 190:
                    return 0;
            }
        break;

        case 696:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 46;
                case 46:
                    return 0;
            }
        break;

        case 697:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 46;
                case 46:
                    return 0;
            }
        break;

        case 698:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 46;
                case 46:
                    return 0;
            }
        break;

        case 699:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 46;
                case 46:
                    return 0;
            }
        break;

        case 700:
            switch (registrador_endereco)
            {
                case 0:
                    return 9;
                case 9:
                    return 20;
                case 20:
                    return 46;
                case 46:
                    return 0;
            }
        break;

        case 701:
            switch (registrador_endereco)
            {
                case 0:
                    return 83;
                case 83:
                    return 0;
            }
        break;

        case 702:
            switch (registrador_endereco)
            {
                case 0:
                    return 113;
                case 113:
                    return 0;
            }
        break;

        case 703:
            switch (registrador_endereco)
            {
                case 0:
                    return 139;
                case 139:
                    return 0;
            }
        break;

        case 704:
            switch (registrador_endereco)
            {
                case 0:
                    return 165;
                case 165:
                    return 0;
            }
        break;

        case 705:
            switch (registrador_endereco)
            {
                case 0:
                    return 191;
                case 191:
                    return 0;
            }
        break;

        case 706:
            switch (registrador_endereco)
            {
                case 0:
                    return 5;
                case 5:
                    return 20;
                case 20:
                    return 47;
                case 47:
                    return 0;
            }
        break;

        case 707:
            switch (registrador_endereco)
            {
                case 0:
                    return 6;
                case 6:
                    return 20;
                case 20:
                    return 47;
                case 47:
                    return 0;
            }
        break;

        case 708:
            switch (registrador_endereco)
            {
                case 0:
                    return 7;
                case 7:
                    return 20;
                case 20:
                    return 47;
                case 47:
                    return 0;
            }
        break;

        case 709:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 47;
                case 47:
                    return 0;
            }
        break;

        case 710:
            switch (registrador_endereco)
            {
                case 0:
                    return 8;
                case 8:
                    return 20;
                case 20:
                    return 47;
                case 47:
                    return 0;
            }
        break;

        case 711:
                        if (flags_ula.zero == 1)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 712:
                        if (flags_ula.negativo == 1)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 713:
                        if (flags_ula.zero == 1)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 714:
                        if (flags_ula.zero == 0 && flags_ula.negativo == 0 && flags_ula.carry == 0)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 715:
                        if (flags_ula.negativo == 1)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 716:
                        if (flags_ula.carry == 1)
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 4;
                                        case 4:
                                                return 20;
                                        case 20:
                                                return 2;
                                }
                        }
                        else
                        {
                                switch (registrador_endereco)
                                {
                                        case 0:
                                                return 1;
                                        case 1:
                                                return 0;
                                }
                        }
                break;

                case 717:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 1;
                                case 1:
                                        return 4;
                                case 4:
                                        return 20;
                                case 20:
                                        return 2;
                        }
                break;

                case 719:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 218;
                                case 218:
                                        return 0;
                        }
                break;

                case 720:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 219;
                                case 219:
                                        return 0;
                        }
                break;

                case 721:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 220;
                                case 220:
                                        return 0;
                        }
                break;

                case 722:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 221;
                                case 221:
                                        return 0;
                        }
                break;

                case 723:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 222;
                                case 222:
                                        return 0;
                        }
                break;

                case 724:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 223;
                                case 223:
                                        return 0;
                        }
                break;

                case 725:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 224;
                                case 224:
                                        return 0;
                        }
                break;

                case 726:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 225;
                                case 225:
                                        return 0;
                        }
                break;

                case 727:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 226;
                                case 226:
                                        return 0;
                        }
                break;

                case 728:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 227;
                                case 227:
                                        return 0;
                        }
                break;

                case 729:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 5;
                                case 5:
                                        return 20;
                                case 20:
                                        return 228;
                                case 228:
                                        return 0;
                        }
                break;

                case 730:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 6;
                                case 5:
                                        return 20;
                                case 20:
                                        return 228;
                                case 228:
                                        return 0;
                        }
                break;

                case 731:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 7;
                                case 5:
                                        return 20;
                                case 20:
                                        return 228;
                                case 228:
                                        return 0;
                        }
                break;

                case 732:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 8;
                                case 5:
                                        return 20;
                                case 20:
                                        return 228;
                                case 228:
                                        return 0;
                        }
                break;

                case 733:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 9;
                                case 5:
                                        return 20;
                                case 20:
                                        return 228;
                                case 228:
                                        return 0;
                        }
                break;

                case 734:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 5;
                                case 5:
                                        return 20;
                                case 20:
                                        return 229;
                                case 229:
                                        return 0;
                        }
                break;

                case 735:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 6;
                                case 6:
                                        return 20;
                                case 20:
                                        return 229;
                                case 229:
                                        return 0;
                        }
                break;

                case 736:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 7;
                                case 7:
                                        return 20;
                                case 20:
                                        return 229;
                                case 229:
                                        return 0;
                        }
                break;

                case 737:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 8;
                                case 8:
                                        return 20;
                                case 20:
                                        return 229;
                                case 229:
                                        return 0;
                        }
                break;

                case 738:
                        switch (registrador_endereco)
                        {
                                case 0:
                                        return 9;
                                case 9:
                                        return 20;
                                case 20:
                                        return 229;
                                case 229:
                                        return 0;
                        }
                break;
    }
}

/**
*   Executa todas as operacoes correspondentes a um ciclo de maquina
*/
void Unidade_Controle::ciclo_de_maquina(int instrucao, Flags flags_ula)
{
    #ifdef DEBUG
        printf("Executando a instrucao (interno): %d\n", registrador_instrucao_interno);
        printf("Executando a instrucao (externo): %d\n", instrucao);
    #endif

    //Pega o endereco da proxima micro
    registrador_endereco = gerador_endereco(registrador_instrucao_interno, flags_ula);
    #ifdef DEBUG
        printf("Endereco da micro sendo executada: %d\n", registrador_endereco);
    #endif

    //Copia o ponto de controle da memoria de controle para o registrador de controle
    registrador_controle = memoria_controle[registrador_endereco];
    #ifdef DEBUG
        printf("Sinais: ");
        for (int i = 0; i < MAX_CONTROLES; i++)
            printf("%d", registrador_controle.controle[i]);
        printf("\n");
    #endif

    /*  O processador sempre deve decodificar as instrucoes. (Decodificar instrucao -> instrucao = 0)
    *   Portanto, ao final da decodificacao (Ultima micro da decodificacao = 163) podemos comecar a executar a intrucao decodificada.
    *   (registrador_instrucao_interno = instrucao;)
    *   Ao terminar de executar uma instrucao qualquer (registrador_instrucao_interno != 0 e ultima micro = 0), devemos decodificar a proxima intrucao
    *   (registrador_instrucao_interno = 0;)
    */
    if (registrador_instrucao_interno == 0 && registrador_endereco == 217)
    {
        registrador_instrucao_interno = instrucao;
        registrador_endereco = 0;
    }
    else if (registrador_instrucao_interno != 0 && registrador_endereco == 0)
    {
        registrador_instrucao_interno = 0;
    }
        else if (registrador_instrucao_interno > 710 && registrador_instrucao_interno < 718 && registrador_endereco == 2)
    {
        registrador_instrucao_interno = 0;
                registrador_endereco = 0;
    }
}

/**
*   Comeca o processador
*/
void Unidade_Controle::start(Flags flag_ula)
{
    #ifdef DEBUG
        printf("Comecou!\n");
    #endif
    //Inicializa Registrador de Endereco
    registrador_endereco = 0;
    registrador_instrucao_interno = 0;

    ciclo_de_maquina(0, flag_ula);
}
