# Este � um teste de programa em assembly.
# O objetivo aqui � colocar dois n�meros na mem�ria e calcular o primeiro elevado ao segundo.

	mov 10, r0
	mov 8, r1
1:	shr r0
	cmp r1,r0
	brl 1
	HALT
