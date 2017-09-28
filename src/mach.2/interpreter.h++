#ifndef INTERPTRETER
#define INTERPTRETER

#include <string>
//#include <sstream>

//#include "B:\Documents\Visual Studio Projects\NoWare\lexical_analyzer.cpp"
//#include "B:\Documents\Visual Studio Projects\NoWare\lexical_analyzer"
//#include "peers.hpp"
//#include "memory.hpp"
#include "resources/processor.h++"

namespace LIB
{
	namespace cluster
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
				
					unsigned short int enqueue (const std::string & /* File name. */, std::queue <LIB::cluster::processor::instructions> &, std::string & = (std::string &) "");
			};
	}
}

#endif
