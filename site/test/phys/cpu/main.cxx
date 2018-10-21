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
#include <noware/mach>
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
	
	
	noware::var selection;
	std::string group, name, value;
	std::string element;
	noware::mach::cpu cpu;
	noware::mach::cpu::instr inst;
	
	inst.oprn = noware::mach::cpu::opr::add;
	
	do
	{
		std::cout << std::endl;
		std::cout << "CPU:" << std::endl;
		std::cout << std::endl;
		std::cout << " Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "   " << "0. Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "  Store Functionality:" << std::endl;
		std::cout << "   " << "1. Exist" << std::endl;
		std::cout << "   " << "2. Get" << std::endl;
		std::cout << "   " << "3. Set" << std::endl;
		std::cout << "   " << "4. Remove" << std::endl;
		std::cout << std::endl;
		std::cout << "  Queue Functionality:" << std::endl;
		std::cout << "   " << "5. Size" << std::endl;
		std::cout << "   " << "6. Enqueue" << std::endl;
		std::cout << "   " << "7. Dequeue" << std::endl;
		std::cout << "   " << "8. Next" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Selection: ";
		getline (std::cin, selection);
		//std::cout << std::endl;
		
		if (selection == noware::nr (0))
		{
			//return EXIT_SUCCESS;
			break;
		}
		else if (selection == noware::nr (1))
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Exists : [" << group << "][" << name << "] == " << (cpu.exist (group, name) ? "True" : "False") << std::endl;
			//std::cout << "  " << "Exists : [" << name << "] == " << (cpu.exist (name) ? "True" : "False") << std::endl;
		}
		else if (selection == noware::nr (2))
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Getting : [" << group << "][" << name << "] == [" << cpu.get (group, name) << ']' << std::endl;
			//std::cout << "  " << "Getting : [" << name << "] == [" << cpu.get (name) << ']' << std::endl;
		}
		else if (selection == noware::nr (3))
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Value: ";
			getline (std::cin, value);
			
			std::cout << "  " << "Setting : [" << group << "][" << name << "] = [" << value << "] ... " << (cpu.set (group, name, value) ? "Success" : "Failure") << std::endl;
			//std::cout << "  " << "Setting : [" << name << "] = [" << value << "] ... " << (cpu.set (name, value) ? "Success" : "Failure") << std::endl;
		}
		else if (selection == noware::nr (4))
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Removing : [" << group << "][" << name << "] ... " << (cpu.remove (group, name) ? "Success" : "Failure") << std::endl;
			//std::cout << "  " << "Removing : [" << name << "] ... " << (cpu.remove (name) ? "Success" : "Failure") << std::endl;
		}
		else if (selection == noware::nr (5))
		{
			std::cout << "  " << "Size == [" << cpu.size () << ']' << std::endl;
		}
		else if (selection == noware::nr (6))
		{
			//std::cout << "  " << "Group: ";
			//getline (std::cin, group);
			
			std::cout << "  " << "Operand 1: ";
			getline (std::cin, element);
			inst.oprnd [0] = element;
			
			std::cout << "  " << "Operand 2: ";
			getline (std::cin, element);
			inst.oprnd [1] = element;
			
			//std::cout << "  " << "Operation: ";
			//getline (std::cin, element);
			std::cout << "  " << "Operation is 'addition'";
			//inst.oprn = noware::mach::cpu::opr::addition;
			
			//std::cout << "  " << "Exists : [" << group << "][" << name << "] == " << (dam.exist (group, name) ? "True" : "False") << std::endl;
			std::cout << "  " << "Enqueue : " << (cpu.enqueue (inst) ? "True" : "False") << std::endl;
		}
		else if (selection == noware::nr (7))
		{
			//std::cout << "  " << "Group: ";
			//getline (std::cin, group);
			
			//std::cout << "  " << "Name: ";
			//getline (std::cin, name);
			
			//std::cout << "  " << "Getting : [" << group << "][" << name << "] == [" << dam.get (group, name) << ']' << std::endl;
			std::cout << "  " << "Dequeue : " << (cpu.dequeue () ? "True" : "False") << std::endl;
		}
		else if (selection == noware::nr (8))
		{
			//std::cout << "  " << "Group: ";
			//getline (std::cin, group);
			/*
			std::cout << "  " << "Name: ";
			getline (std::cin, name);
			
			std::cout << "  " << "Value: ";
			getline (std::cin, value);
			*/
			//std::cout << "  " << "Setting : [" << group << "][" << name << "] = [" << value << "] ... " << (dam.set (group, name, value) ? "Success" : "Failure") << std::endl;
			
			inst = cpu.next ();
			
			std::cout << "  " << "Next:" << std::endl;
			//std::cout << "    " << "inst.oprn: [" << inst.oprn << ']' << std::endl;
			std::cout << "    " << "inst.oprn: [" << "'addition'" << ']' << std::endl;
			std::cout << "    " << "inst.oprnd [0]: [" << inst.oprnd [0] << ']' << std::endl;
			std::cout << "    " << "inst.oprnd [1]: [" << inst.oprnd [1] << ']' << std::endl;
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
