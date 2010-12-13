#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	char linha[64], *op, *src, *dst;

	for (int i = 1; gets (linha); i++)
	{
		op = linha;
		op = strtok(op, " \n\t");

		if (!strcmp(op, "add") || !strcmp(op, "sub") || !strcmp(op, "mov") || !strcmp(op, "cmp") || !strcmp(op, "and") || !strcmp(op, "or") || !strcmp(op, "sh") || !strcmp(op, "br"))
		{
			src = linha + strlen(op) + 1;
			src = strtok(src, " \n\t");

			dst = linha + strlen(op) + strlen(src) + 2;
			dst = strtok(dst, " \n\t");
			
			printf ("codigo[command(\"%s\", \"%s\", \"%s\")] = %d;\n", op, src, dst, i);
		}
		else if (!strcmp(op, "not") || !strcmp(op, "neg") || !strcmp(op, "clr") || !strcmp(op, "jmp"))
		{
			src = linha + strlen(op) + 1;
			src = strtok(src, " \n\t");
			
			printf ("codigo[command(\"%s\", \"%s\")] = %d;\n", op, src, i);
		}
		else
		{
			printf ("codigo[command(\"%s\")] = %d;\n", op, i);
		}
	}
	
	return 0;
}
