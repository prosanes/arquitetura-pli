#ifndef _PARSER_H_
#define _PARSER_H_

#include <map>
#include "command.h"
#include "memoria.h"

using namespace std;

class Parser
{
	int posAtual;
	FILE *entrada;
	Memoria *mem;

	map<string,int> nop;
	map<string,int> label;
	map<command,int> codigo;

	public:
		Parser (Memoria *memory, char* input);
		void parse (void);
};

#endif
