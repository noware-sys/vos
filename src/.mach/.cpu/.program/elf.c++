#include <cstdlib>
//#include <iostream>
#include <ifstream>
//#include <bitset>

#include "elf.h++"

LIB::machine::actions::elf::elf (void)
{
}

LIB::machine::actions::elf::elf (const std::string & file)
{
	enqueue (file);
}

LIB::machine::actions::elf::elf (const resources::processor::instructions & instructions, const bool & parallel = false)
{
	enqueue (instructions, parallel);
}

LIB::machine::actions::elf::~ elf (void)
{
}

const bool LIB::machine::actions::elf::enqueue (const std::string & name)
{
	std::ifstream file;
	
	file.open (name, std::ios::in | std::ios::binary);
	
	if (! file.is_open ())
		return false;
	
	
	
	file.close ();
	return true;
}

const bool LIB::machine::actions::elf::enqueue (const resources::processor::instructions & instructions, const bool & parallel)
{
}

const LIB::machine::resources::processor::instructions LIB::machine::actions::elf::dequeue (const methematics::numbers::natural & count)
{
	
}

const LIB::mathematics::numbers::natural LIB::machine::actions::elf::size (void) const
{
	return 0;
}

