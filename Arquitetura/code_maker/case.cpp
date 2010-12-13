#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXS 50

#define MAXMICROS 218
#define MAXINST 710

char micros[MAXN][MAXS];
int tam_micros;

int main (void)
{
    FILE* entrada_micros;
    entrada_micros = fopen("micros.txt", "r");

    int j;
    for (int i = 0; i < MAXMICROS; i++)
    {
        fgets(micros[i], MAXS+1, entrada_micros);

        for (j = 0; micros[i][j] != '\n'; j++);
        micros[i][j] = '\0';

        puts("Leu uma micro");
    }
    tam_micros = MAXMICROS;

    fclose(entrada_micros);

    puts("Leu micros!");

    FILE* entrada_instr;
    entrada_instr = fopen("instrucao_micros.txt", "r");

    FILE* saida;
    saida = fopen("codigo.txt", "w");

    fprintf(saida, "switch(instrucao)\n{\n");

    char atual[MAXS];
    char c = ' ';
    for (int i = 1; i <= MAXINST; i++)
    {
        fprintf(saida, "    case %d:\n", i);
        fprintf(saida, "        switch (registrador_endereco)\n        {\n");
        fprintf(saida, "            case 0:\n");

        c = ' ';
        while (c != '!')
        {
            fscanf(entrada_instr, "%*[^(]");
            fscanf(entrada_instr, "%[^)]", atual);
            fscanf(entrada_instr, "%*c%c", &c);

            for (j = 0; atual[j] != '\0'; j++);
            atual[j] = ')';
            atual[j+1] = '\0';

            j = 0;
            while (strcmp(atual, micros[j]) != 0)
                j++;

            printf("%s %d ", atual, j);
            printf("%c\n", c);

            fprintf(saida, "                return %d;\n", j);
            if (j != 0)
                fprintf(saida, "            case %d:\n", j);
        }

        fprintf(saida, "        }\n");
        fprintf(saida, "    break;\n\n");
    }

    return 0;
}
