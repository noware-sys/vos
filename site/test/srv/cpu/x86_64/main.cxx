//#include <Poco/any.h>
//#include <string>
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

#include <noware/cmd/pause>
#include <noware/vos/srv/cpu/x86_64>
//#include <noware/array>
//#include <noware/machine>
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

int main (int argc, char * argv [], char * envp [])
{
	//using namespace boost::any_cast;
	//using namespace std;
	//using namespace boost;
	//using namespace noware;
	
	//std::cout << "  ";
	
	std::cout << "argc [" << argc << ']' << std::endl;
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	
	std::cout << std::boolalpha;
	
	
	{
		noware::vos::srv::cpu::x86_64 cpu;
		//noware::mach::cpu::loader loader;
		
		assert (cpu.init ());
		assert (cpu.enable ());
		assert (cpu.start ());
		
		noware::cmd::pause ("Press [Enter] to finalize the CPU ... ");
	}
//	boost::this_thread::sleep_for (boost::chrono::seconds (7));
	noware::cmd::pause ("Press [Enter] to exit ... ");
	
	//return EXIT_SUCCESS;
}
