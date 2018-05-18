#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <noware/elf.cxx>

#include "extractor.hxx"

/*
noware::vmach::store::extractor::extractor (void)
{
	_loaded = false;
}
*/

bool const/* success*/ noware::mach::tool::cpu::extractor::load_file (std::string const & file_name)
{
	//noware::elf elf;
	
	
	content = elf.read (file_name);
	
	if (content.empty ())
		return false;
	
	
	elf.load (content);
	
	if (!elf.loaded ())
		return false;
	
	
	//_loaded = true;
	
	return true;
}


bool const/* success*/ noware::mach::tool::cpu::extractor::extract (std::string const & input_file_name, std::string const & output_file_name)
{
	/*
	std::ofstream file;
	
	
	file.open (file_name_input, ios::out | ios::trunc);
	
	if (!file.is_open ())
		return false;
	*/
	
	
	// Load all 'LOAD' program segments into memory
	unsigned long int entry;
	unsigned long int phndx, phnum;
	unsigned long int j;
	unsigned long int vaddr;
	unsigned long int filesz, memsz;
	unsigned long int flag;
	
	// Offset in the file where the LAOD program segment begins
	unsigned long int offset;
	// Difference: entry - vaddr
	unsigned long int diff;
	// Location where to start reading from
	unsigned long int start;
	// Quantity to be read from the file
	unsigned long int size;
	// Whether the elf is 32 or 64 bits
	unsigned short int elf_bits;
	// error returned by system(cmd)
	signed int error;
	std::stringstream cmd;
	
	cmd << std::hex;
	cmd << std::showbase;
	
	entry = noware::elf::integer (elf.hdr.entry.data, true);
	elf_bits = noware::elf::integer (elf.hdr.id_class.data, true) == 0x1/*32 bits == 0x1; 64-bits == 0x2*/ ? 32 : 64;
	
	phnum = noware::elf::integer (elf.hdr.phnum.data, true);
	for (phndx = 0; phndx < phnum; ++phndx)
	{
		// If this program segment is of the type 'LOAD', then load it
		if (noware::elf::integer (elf.prog [phndx].type.data, true) == 0x1/*PT_LOAD*/)
		{
			// This is the executable LOAD program segment which contains the instructions
			// Write the program segment into the output file
			filesz = noware::elf::integer (elf.prog [phndx].filesz.data, true);
			vaddr = noware::elf::integer (elf.prog [phndx].vaddr.data, true);
			offset = noware::elf::integer (elf.prog [phndx].offset.data, true);
			flag = noware::elf::integer (elf.prog [phndx].flag.data, true);
			if ((flag & 0x5/*Read + eXecute*/) && entry >= vaddr)
			{
				diff = entry - vaddr;
				start = diff + offset;
				size = filesz - diff;
				
				cmd << "dd skip=$((" << start << ")) bs=1 count=$((" << size << ")) if='" << input_file_name << "' 2> /dev/null | ndisasm -b $((" << elf_bits << ")) -p intel - 1> '" << output_file_name << "'";
				
				error = system (cmd.str ().c_str ());
				break;
			}
		}
	}
	
	//file.close ();
	return error == 0;
}

bool const/* success*/ noware::mach::tool::cpu::extractor::clear (void)
{
	content.clear ();
	//_loaded = false;
	elf.clear ();
	
	return true;
}

bool const & noware::mach::tool::cpu::extractor::loaded (void) const
{
	return elf.loaded ();
}
