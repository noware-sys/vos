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

#include <noware/cmd/pause>
#include <noware/cmach/queue>
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
	
	std::cout << "  ";
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "  argc==[" << argc << ']' << std::endl;
	
	std::cout << std::boolalpha;
	
	
	std::string selection;
	std::string element;
	noware::cmach::queue q;
	
	assert (q.init ());
	assert (q.enable ());
	assert (q.start ());
	
	do
	{
		std::cout << std::endl;
		std::cout << "Queue:" << std::endl;
		std::cout << std::endl;
		std::cout << " Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "  " << "0. Exit" << std::endl;
		std::cout << "  " << "1. Size" << std::endl;
		std::cout << "  " << "2. Empty?" << std::endl;
		std::cout << "  " << "3. Dequeue" << std::endl;
		std::cout << "  " << "4. Next+Dequeue" << std::endl;
		std::cout << "  " << "5. Next" << std::endl;
		std::cout << "  " << "6. Enqueue..." << std::endl;
		std::cout << "  " << "7. Clear" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Selection: ";
		getline (std::cin, selection);
		//std::cout << std::endl;
		
		if (selection == "0")
		{
			//return EXIT_SUCCESS;
			break;
		}
		else if (selection == "1")
		{
			std::cout << "  " << "Size: [" << q.size () << ']' << std::endl;
			//std::cout << "  " << "Getting : [" << name << "] == [" << dam.get (name) << ']' << std::endl;
		}
		else if (selection == "2")
		{
			/*
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Exists : [" << group << "][" << name << "] == " << (dam.exist (group, name) ? "True" : "False") << std::endl;
			//std::cout << "  " << "Exists : [" << name << "] == " << (dam.exist (name) ? "True" : "False") << std::endl;
			*/
			std::cout << "  " << "Empty?() : " << (q.empty () ? "True" : "False") << std::endl;
		}
		else if (selection == "3")
		{
			std::cout << "  " << "Dequeue : [" << q.dequeue () << ']' << std::endl;
			//std::cout << "  " << "Getting : [" << name << "] == [" << dam.get (name) << ']' << std::endl;
		}
		else if (selection == "4")
		{
			std::cout << "  " << "Next+Dequeue : [" << q.next_dequeue () << ']' << std::endl;
		}
		else if (selection == "5")
		{
			std::cout << "  " << "Next : [" << q.next () << ']' << std::endl;
		}
		else if (selection == "6")
		{
			std::cout << "  " << "Element: ";
			getline (std::cin, element);
			
			std::cout << "  " << "Enqueue (\"" << element << "\") : [" << q.enqueue (element) << ']' << std::endl;
		}
		else if (selection == "7")
		{
			std::cout << "  " << "Clearing ... " << (q.clear () ? "Success" : "Failure") << std::endl;
		}
		else //if (selection != 0)
		{
			std::cout << "  " << "Unrecognized Selection" << std::endl;
		}
	}
	//while (selection != 0);
	while (true);
	
	//return EXIT_SUCCESS;
}
