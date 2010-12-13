#include <stdio.h>

#define MAXPONTOS 23

int main (void)
{
    FILE* entrada;
    entrada = fopen("memoria_controle_letras.txt", "r");

    FILE* saida;
    saida = fopen("memoria_controle_binario.txt", "w");

    while( !feof(entrada) )
    {
        bool output[MAXPONTOS];
        for (int i = 0; i < MAXPONTOS; i++)
            output[i] = false;

        char linha[23];
        fscanf(entrada, " %s", linha);
        for (int i = 0; linha[i]; i++)
        {
            output[ linha[i] - 'a' ] = true;
        }

        for (int i = 0; i < 23; i++)
        {
            fprintf(saida, "%d", output[i]);
            printf("%d", output[i]);
        }
        fprintf(saida, "\n");
        printf("\n");
    }

    fclose(entrada);
    fclose(saida);

    ////////////////
    /*entrada = fopen("memoria_controle_binario.txt", "r");

    while ( !feof(entrada) )
    {
        bool output[21];

        fread(output, sizeof(bool), sizeof(output), entrada);

        for (int i = 0; i < 21; i++)
        {
            printf("%d", output[i]);
        }
        printf("\n");
    }

    fclose(entrada);*/

    return 0;
}
