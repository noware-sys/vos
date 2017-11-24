//#include <Poco/any.h>
#include <string>
#include <iostream>
#include <iomanip>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
//#include <omp.h>
//#include <unordered_map>
//#include <typeinfo>
//#include <list>
#include <map>
//#include <string>
//#include <stack>
#include <assert.h>

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

//#include <noware/array>
//#include <noware/var>
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
#include <noware/unsigned_string>
#include <noware/misc/elf>
#include <noware/mach>

//#include <vector>
//struct My
//{
//	int x, y;
//};

/*
const unsigned int integer (const std::string & block, const bool & swap = false)
{
	unsigned int val;
	unsigned int size;
	std::stringstream ss;
	
	//val = 0;
	size = block.size ();
	ss << std::hex;
	
	if (swap)
	{
		for (signed int ndx = size; ndx >= 0; --ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	else
	{
		for (unsigned int ndx = 0; ndx < size; ++ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	
	ss >> val;
	
	return val;
}
*/

int main (int argc, char * argv [], char * env [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	std::cout << std::boolalpha;
	//std::cout << std::hex;
	//std::cout << std::showbase;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "#arg [" << argc << ']' << std::endl;
	
	if (argc < 2)
	{
		std::cerr << "'" << argv [0] << "'" << " '<store.key/val.txt>' '<cpu.instr.txt>'" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	noware::elf file;
	noware::unsigned_string content;
	// Direct-Access Memory for the program
	//std::map <unsigned long int, unsigned char> dam;
	noware::mach::store::loader loader_store;
	noware::mach::cpu::loader loader_cpu;
	
	
	
	content = file.read (argv [1]);
	
	if (content.empty ())
	{
		std::cerr << "'" << argv [0] << "'::error::could not read file '" << argv [1] << "'" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "'" << argv [0] << "'::success::read file '" << argv [1] << "'" << std::endl;
	
	if (!file.load (content))
	{
		std::cerr << "'" << argv [0] << "'::error::could not load file '" << argv [1] << "'" << std::endl;
		
		//std::cout << "the content was:" << std::endl;
		//std::cout << content << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "'" << argv [0] << "'::success::loaded file '" << argv [1] << "'" << std::endl;
	
	
	
	// Load all 'LOAD' program segments into memory
	unsigned long int phndx, phnum;
	unsigned long int j;
	unsigned long int vaddr;
	unsigned long int filesz, memsz;
	
	phnum = noware::elf::integer (file.hdr.phnum.data, true);
	for (phndx = 0; phndx < phnum; ++phndx)
	{
		// If this program segment is of the type 'LOAD', then load it
		if (noware::elf::integer (file.prog [phndx].type.data, true) == 0x1/*PT_LOAD*/)
		{
			// Copy the program segment into memory
			filesz = noware::elf::integer (file.prog [phndx].filesz.data, true);
			vaddr = noware::elf::integer (file.prog [phndx].vaddr.data, true);
			for (j = 0; j < filesz; ++j, ++vaddr)
			{
				// 8 bits (1 byte) at a time
				//dam [vaddr] = file.prog [phndx].data.data.substr (j, 1/* 8 bits (1 byte) at a time*/);
				dam [vaddr] = file.prog [phndx].data.data [j];
			}
			
			// Pad the remaining space with zeroes
			memsz = noware::elf::integer (file.prog [phndx].memsz.data, true);
			for (; j < memsz; ++j, ++vaddr)
			{
				dam [vaddr] = (unsigned char) '0';
			}
		}
	}
	
	
	// Commence the program
	unsigned long int entry;
	entry = noware::elf::integer (file.hdr.entry.data, true);
	assert (dam.count (entry) > 0);
	std::cout << std::hex;
	std::cout << std::showbase;
	std::cout << "entry[" << entry << "]==[";
	std::cout << noware::elf::integer (noware::unsigned_string (1, dam [entry]), true);
	std::cout << "]";
	std::cout << std::endl;
}
