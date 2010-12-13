#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

set<string> setao;

int main (void)
{
	char cmm[32];
	FILE *arq = fopen("arq1.txt", "r");
	if (!arq)
	{
		puts ("PUTA QUE PARIU!");
		return 0;
	}
	
	fgets(cmm, 32, arq);
	while (!feof(arq))
	{
		if (setao.find(string(cmm)) != setao.end());
		else
		{
			setao.insert(string(cmm));
			printf ("%s", cmm);
		}
		fgets(cmm, 32, arq);
	}

	return 0;
}

/*

	Estrutura do parser:
		- Lê linha
		- Procura o tipo do comando
		- Procura, se existir, operando fonte
		- Procura, se existir, operando destino
		- Procura no map a instrução
		- Coloca na posição atual de memória
		- Incrementa posição atual de memória

*/