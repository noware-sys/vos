//#include <Poco/any.h>
#include <string>
#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
//#include <omp.h>
//#include <unordered_map>
//#include <typeinfo>
//#include <list>
//#include <string>
//#include <stack>

// #include <cln/cln.h>

//
//// Boost:
//#include <boost/any.hpp>
//#include <boost/thread.hpp>
//// Boost serialization:
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/split_member.hpp>	// For separating reading and writing.
//#include <boost/serialization/list.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
////#include <boost/archive/binary_oarchive.hpp>
////#include <boost/archive/binary_iarchive.hpp>

#include <noware/var>
#include <noware/mach.cpu.cxx>
#include <noware/tool/pause>
//#include <noware/container/entity.h++>

//////#include <noware/containers/entity.h++>
////#include <noware/containers/variable-undefine.h++>
//#include <noware/math.h++>
//#include <noware/serialization.h++>

//#include <noware/containers/text.h++>
//#include <noware/containers/any.hpp>
//#include <NoWare/Container/Variable.h>
//#include <noware/containers/array.hpp>
//#include <NoWare/Containers/Dynamic.h>
//#include <NoWare/Containers/Dynamic.cpp>
//#include "MPI.h"
//#include <noware/cluster.h++>
//#include "Memory.h"
//#include "HPC.cpp"
//#include "Numerical Strings.h"
//#include <vector>
//struct My
//{
//	int x, y;
//};

int main (int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	/*
	if (argc < 2)
	{
		std::cout << "'" << argv [0] << "': usage: '" << argv [0] <<"' <instructions.txt>" << std::endl;
		
		return EXIT_FAILURE;
	}
	*/
	{
		noware::mach::cmd cli;
		//noware::mach::cpu::loader loader;
		
		assert (cli.init ());
		assert (cli.enable ());
		assert (cli.start ());
		
		
		/*
		assert (loader.init ());
		assert (loader.enable ());
		assert (loader.start ());
		
		noware::pause ("Press [Enter] to enqueue the instructions . . . ");
		
		//if (!m.enqueue (argv [1]))
		if (!loader.load_file (argv [1]))
		{
			std::cout << "'" << argv [0] << "': error: could not load the instructions file" << std::endl;
			
			return EXIT_FAILURE;
		}
		*/
		
		/*
		noware::pause ("Press [Enter] to start the thread . . . ");
		
		//if (!m.trd.start ())
		if (!m.cpu.enqueue (noware::mach::cpu::instr (m.cpu.get ("thread 1", "instr 1"))) || !m.cpu.set ("thread 1", "running", "1"))
		{
			std::cout << "'" << argv [0] << "': error: could not start the thread" << std::endl;
			
			return EXIT_FAILURE;
		}
		*/
		
		/*
		noware::pause ("Press [Enter] to view values (pre) . . . ");
		
		std::cout << " eax , [" << m.store.get (m.trd.group (), "eax") << ']' << std::endl;
		std::cout << " ebx , [" << m.store.get (m.trd.group (), "ebx") << ']' << std::endl;
		std::cout << " ecx , [" << m.store.get (m.trd.group (), "ecx") << ']' << std::endl;
		std::cout << " edx , [" << m.store.get (m.trd.group (), "edx") << ']' << std::endl;
		std::cout << "  dl , [" << m.store.get (m.trd.group (), "dl") << ']' << std::endl;
		*/
		
		//noware::pause ("Press [Enter] to start the CPU . . . ");
	//	noware::pause ("Press [Enter] to sleep . . . ");
		
		/*
		if (!m.cpu.start ())
		{
			std::cout << "'" << argv [0] << "': error: could not start the processor" << std::endl;
			
			return EXIT_FAILURE;
		}
		*/
		
		//std::cout << std::boolalpha;
		
		//boost::this_thread::sleep_for (boost::chrono::seconds (2));
		
	//	std::cout << "'" << argv [0] << "': running" << std::endl;
		
		//noware::pause ("Press [Enter] to view values (post) . . . ");
		
		//std::cout << "  store [user] = [" << m.store.get () << ']' << std::endl;
		
		//m.cpu.stop ();
		
		/*
		std::cout << " eax , [" << m.store.get ("", "eax") << ']' << std::endl;
		std::cout << " ebx , [" << m.store.get ("", "ebx") << ']' << std::endl;
		std::cout << " ecx , [" << m.store.get ("", "ecx") << ']' << std::endl;
		std::cout << " edx , [" << m.store.get ("", "edx") << ']' << std::endl;
		std::cout << "  dl , [" << m.store.get ("", "dl") << ']' << std::endl;
		*/
		
		/*
		std::cout << " eax , [" << m.store.get ("thread 1", "eax") << ']' << std::endl;
		std::cout << " ebx , [" << m.store.get ("thread 1", "ebx") << ']' << std::endl;
		std::cout << " ecx , [" << m.store.get ("thread 1", "ecx") << ']' << std::endl;
		std::cout << " edx , [" << m.store.get ("thread 1", "edx") << ']' << std::endl;
		std::cout << "  dl , [" << m.store.get ("thread 1", "dl") << ']' << std::endl;
		*/
		
		/*
		std::cout << " eax , [" << m.store.get (m.trd.group (), "eax") << ']' << std::endl;
		std::cout << " ebx , [" << m.store.get (m.trd.group (), "ebx") << ']' << std::endl;
		std::cout << " ecx , [" << m.store.get (m.trd.group (), "ecx") << ']' << std::endl;
		std::cout << " edx , [" << m.store.get (m.trd.group (), "edx") << ']' << std::endl;
		std::cout << "  dl , [" << m.store.get (m.trd.group (), "dl") << ']' << std::endl;
		*/
		
		//std::cout << "  store size = [" << m.store.size () << ']' << std::endl;
		noware::pause ("Press [Enter] to finalize the CLI . . . ");
	}
//	boost::this_thread::sleep_for (boost::chrono::seconds (7));
	noware::pause ("Press [Enter] to exit . . . ");
	
	//return EXIT_SUCCESS;
}
