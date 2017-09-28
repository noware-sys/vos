#include <string>
#include "Memory.h"

#ifndef _Parser
#define _Parser

namespace Emulator
{
	namespace Hardware
	{
		typedef std::string Data;
		typedef std::string Value;

		struct Instruction
		{
			Data action;
			Data operand1;
			Data operand2;
			Data output;
		};

		class Evaluator
		{
		public:
			Value Evaluate (const Data);
		};

		class Parser
		{
		private:
		public:
			//Parser (void);
			Instruction Parse (const Data);
		};
	}
}

#endif _Parser
