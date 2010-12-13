#include <stdio.h>
#include "unidade_controle.h"
#include "memoria.h"
#include "multiplexador.h"
#include "registrador.h"
#include "parser.h"
#include "executa.h"

int main (int argc, char **argv)
{
    Unidade_Controle UC(0);
    Memoria memoria;
    ULA ula;
    Multiplexador mux, muxA, muxB;
    Registrador RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR;

    //Carrega programa
	Parser parser(&memoria, argv[1]);
	parser.parse();

	for (int i = 0; i < 60; i++) printf ("%d: %d\n", i, memoria.acesso(false, i, 0));
    PC.sinal(1);
    PC = 0;
    PC.sinal(0);



    UC.start(ula.get_flags());

	/*
		while(IR.get() != 718)
		{
			bool sinal_a = UC.registrador_controle.controle['a'-'a'];
			bool sinal_b = UC.registrador_controle.controle['b'-'a'];
			bool sinal_c = UC.registrador_controle.controle['c'-'a'];
			bool sinal_d = UC.registrador_controle.controle['d'-'a'];
			bool sinal_e = UC.registrador_controle.controle['e'-'a'];
			bool sinal_f = UC.registrador_controle.controle['f'-'a'];
			bool sinal_g = UC.registrador_controle.controle['g'-'a'];
			bool sinal_h = UC.registrador_controle.controle['h'-'a'];
			bool sinal_i = UC.registrador_controle.controle['i'-'a'];
			bool sinal_j = UC.registrador_controle.controle['j'-'a'];
			bool sinal_k = UC.registrador_controle.controle['k'-'a'];
			bool sinal_l = UC.registrador_controle.controle['l'-'a'];
			bool sinal_m = UC.registrador_controle.controle['m'-'a'];
			bool sinal_n = UC.registrador_controle.controle['n'-'a'];
			bool sinal_o = UC.registrador_controle.controle['o'-'a'];
			bool sinal_p = UC.registrador_controle.controle['p'-'a'];
			bool sinal_q = UC.registrador_controle.controle['q'-'a'];
			bool sinal_r = UC.registrador_controle.controle['r'-'a'];
			bool sinal_s = UC.registrador_controle.controle['s'-'a'];
			bool sinal_t = UC.registrador_controle.controle['t'-'a'];
			bool sinal_u = UC.registrador_controle.controle['u'-'a'];
			bool sinal_v = UC.registrador_controle.controle['v'-'a'];
			bool sinal_w = UC.registrador_controle.controle['w'-'a'];

			/** Multiplexador A **
			muxA.sinais_controle(0, sinal_m, sinal_n);
			int saida_muxA = muxA.multiplexa(Rdados.get(), R0.get(), R1.get(), RA.get(), 0);
			#ifdef DEBUG
				printf("saida Mux A: %d\n", saida_muxA);
			#endif

			/** Multiplexador B **
			muxB.sinais_controle(sinal_o, sinal_p, sinal_q);
			int saida_muxB = muxB.multiplexa(PC.get(), R2.get(), R3.get(), R4.get(), RB.get());
			#ifdef DEBUG
				printf("saida Mux B: %d\n", saida_muxB);
			#endif

			/** ULA **
			ula.sinais_controle(sinal_s, sinal_t, sinal_u, sinal_v, sinal_w);
			int saida_ula = ula.operacao(saida_muxA, saida_muxB);
			#ifdef DEBUG
				printf("saida ULA: %d\n", saida_ula);
			#endif

			/** Registradores com conexao direta da ULA **
			R0.sinal(sinal_a);
			R0 = saida_ula;

			R1.sinal(sinal_b);
			R1 = saida_ula;

			RA.sinal(sinal_c);
			RA = saida_ula;

			PC.sinal(sinal_d);
			PC = saida_ula;

			R2.sinal(sinal_e);
			R2 = saida_ula;

			R3.sinal(sinal_f);
			R3 = saida_ula;

			R4.sinal(sinal_g);
			R4 = saida_ula;

			RB.sinal(sinal_h);
			RB = saida_ula;

			IR.sinal(sinal_k);
			IR = saida_ula;

			Rend.sinal(sinal_i);
			Rend = saida_ula;
			
			/** Gerenciamento da memoria. leitura e escrita **
			int saida_memoria = 0;
			if (sinal_r == 0) //Leitura
			{
				/** Memoria **
				saida_memoria = memoria.acesso(sinal_r, Rend.get(), Rdados.get());

				/** MUX do Rdados **
				mux.sinais_controle(0, 0, sinal_l);
				int saida_mux = mux.multiplexa(saida_memoria, saida_ula, 0, 0, 0);

				/** Rdados **
				Rdados.sinal(sinal_j);
				Rdados = saida_mux;
			}
			else if (sinal_r == 1) //Escrita
			{
				/** MUX do Rdados **
				mux.sinais_controle(0, 0, sinal_l);
				int saida_mux = mux.multiplexa(saida_memoria, saida_ula, 0, 0, 0);

				/** Rdados **
				Rdados.sinal(sinal_j);
				Rdados = saida_mux;

				saida_memoria = memoria.acesso(sinal_r, Rend.get(), Rdados.get());
			}

			#ifdef DEBUG
				printf("Registradores:\n");
				printf("Rdados: %8d | R0: %8d | R1: %8d |              | RA: %8d\n", Rdados.get(), R0.get(), R1.get(), RA.get());
				printf("    PC: %8d | R2: %8d | R3: %8d | R4: %8d | RB: %8d\n", PC.get(), R2.get(), R3.get(), R4.get(), RB.get());
				printf("  Rend: %8d | IR: %8d\n", Rend.get(), IR.get());
				printf("Zero: %d | Carry: %d | Negativo: %d\n", ula.get_flags().zero, ula.get_flags().carry, ula.get_flags().negativo);
			#endif

			//scanf("%*c");

			/** UC **
			UC.ciclo_de_maquina(IR.get(), ula.get_flags());
		}
	*/

	while (IR.get() != 718)
	{
		char c;
		scanf (" %c", &c);
		if (c == 'd') direto (UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);
		if (c == 'i') next_inst (UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);
		if (c == 'm') next_micro (UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);
	}


    return 0;
}
