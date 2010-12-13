#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>

using namespace std;

class command
{
	public: string op, source, destination;

	public:
		command (string);
		command (string, string);
		command (string, string, string);
};

bool operator< (const command, const command);

#endif
