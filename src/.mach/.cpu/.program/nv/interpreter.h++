#pragma once
//#ifndef __INTERPTRETER
//#define __INTERPTRETER

#include <string>
//#include <sstream>

#include "../default.h++"
//#include "B:\Documents\Visual Studio Projects\NoWare\lexical_analyzer.cpp"
//#include "B:\Documents\Visual Studio Projects\NoWare\lexical_analyzer"
//#include "peers.hpp"
//#include "memory.hpp"
#include "../machine/resources/processor.h++"

namespace LIB
{
	namespace language
	{
		//public:
			class interpreter
			{
				protected:
					std::stringstream instructions;
					std::string intruction;
				public:
					interpreter (void);
					~interpreter (void);
					
					unsigned short int enqueue (const std::string & /* File name. */, std::queue <LIB::machine::resources::processor::instructions> &, std::string & = (std::string &) "");
					//static unsigned short int enqueue (const std::string & /* File name. */, std::queue <LIB::machine::resources::processor::instructions> &, const std::string & = (std::string &) "");
			};
	}
}

//#endif
