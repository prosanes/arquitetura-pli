#include "unidade_controle.h"
#include "memoria.h"
#include "multiplexador.h"
#include "registrador.h"
#include "parser.h"

void next_micro (Unidade_Controle & UC, Memoria &memoria, ULA &ula, Multiplexador &mux, Multiplexador &muxA, Multiplexador &muxB,
	Registrador &RA, Registrador &RB, Registrador &R0, Registrador &R1, Registrador &R2, Registrador &R3, Registrador &R4,
	Registrador &PC, Registrador &Rdados, Registrador &Rend, Registrador &IR);

void next_inst (Unidade_Controle & UC, Memoria &memoria, ULA &ula, Multiplexador &mux, Multiplexador &muxA, Multiplexador &muxB,
	Registrador &RA, Registrador &RB, Registrador &R0, Registrador &R1, Registrador &R2, Registrador &R3, Registrador &R4,
	Registrador &PC, Registrador &Rdados, Registrador &Rend, Registrador &IR);

void direto (Unidade_Controle &UC, Memoria &memoria, ULA &ula, Multiplexador &mux, Multiplexador &muxA, Multiplexador &muxB,
	Registrador &RA, Registrador &RB, Registrador &R0, Registrador &R1, Registrador &R2, Registrador &R3, Registrador &R4,
	Registrador &PC, Registrador &Rdados, Registrador &Rend, Registrador &IR);
