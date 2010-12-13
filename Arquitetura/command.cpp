#include "command.h"

command::command (string s)
{
	op = s;
}

command::command (string s, string s1)
{
	op = s;
	source = s1;
}

command::command (string s, string s1, string s2)
{
	op = s;
	source = s1;
	destination = s2;
}

bool operator< (const command c1, const command c2)
{
	if (c1.op != c2.op) return c1.op < c2.op;
	if (c1.source != c2.source) return c1.source < c2.source;
	return c1.destination < c2.destination;
}
