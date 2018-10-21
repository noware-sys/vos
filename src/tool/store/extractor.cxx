#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <noware/elf.cxx>

#include "extractor.hxx"

//char const noware::mach::tool::store::extractor::delim_inner_dft = ' ';
//char const noware::mach::tool::store::extractor::delim_outer_dft = ';';

/*
noware::mach::tool::store::extractor::extractor (void)
{
	_loaded = false;
}
*/

bool const/* success*/ noware::vos::tool::store::extractor::load_file (std::string const & file_name)
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


bool const/* success*/ noware::vos::tool::store::extractor::write_file (std::string const & file_name, bool const & pad/*, char const & delim_inner, char const & delim_outer*//*, unsigned short int const & bit_addr*/)
{
	std::cerr << std::boolalpha;
	
	std::ofstream file;
	
	
	file.open (file_name, std::ios::out | std::ios::trunc);
	
	if (!file.is_open ())
		return false;
	
	unsigned short int const addr_bit = 8;
	
	// Whether the elf is for 32 or 64 bits architecture
	unsigned short int elf_bit;
	
	// Load all 'LOAD' program segments into memory
	unsigned long int phndx, phnum;
	unsigned long int j;
	uint64_t vaddr;
	unsigned long int filesz, memsz;
	unsigned long int flag;
	
	elf_bit = noware::elf::integer (elf.hdr.id_class.data, true) == 0x1/*32-bit == 0x1; 64-bit == 0x2*/ ? 32 : 64;
	phnum = noware::elf::integer (elf.hdr.phnum.data, true);
	for (phndx = 0; phndx < phnum; ++phndx)
	{
		// If this program segment is of the type 'LOAD', then load it
		if (noware::elf::integer (elf.prog [phndx].type.data, true) == 0x1/*PT_LOAD*/)
		{
			std::cerr << "noware::vos::tool::store::extractor::write_file(\"" << file_name << "\"," << pad << ')' << ":phndx[" << phndx << ']' << std::endl;
			
			// Write the program segment into the output file
			filesz = noware::elf::integer (elf.prog [phndx].filesz.data, true);
			vaddr = noware::elf::integer (elf.prog [phndx].vaddr.data, true);
			flag = noware::elf::integer (elf.prog [phndx].flag.data, true);
			
			//if (!(flag & 0x1/*eXecute*/))
			//{
				for (j = 0; j < filesz; ++j, ++vaddr)
				{
					// 8 bits (1 byte) at a time
					
					//dam [vaddr] = file.prog [phndx].data.data.substr (j, 1/* 8 bits (1 byte) at a time*/);
					//dam [vaddr] = file.prog [phndx].data.data [j];
					
					// memory address
					file << vaddr;
				//	file << std::bitset <elf_bit> (vaddr);
				//	file << std::endl;
					
					//file << delim_inner;
					
					// delimiter
					file << ' ';
					
					// memory content at that address
					//if (elf.prog [phndx].data.data [j] == 0xA)
					//	file << ((unsigned long int) ('\n')) << std::endl;
					//else
				//		file << std::bitset <addr_bit> ((unsigned long int) (elf.prog [phndx].data.data [j]));
					file << (int short unsigned) (elf.prog [phndx].data.data [j]);
					
					//file << delim_outer;
					file << std::endl;
				}
				
				if (pad)
				{
					// Pad the remaining space with zeroes
					memsz = noware::elf::integer (elf.prog [phndx].memsz.data, true);
					for (; j < memsz; ++j, ++vaddr)
					{
						//dam [vaddr] = (unsigned char) '0';
						
						// memory address
					//	file << std::bitset <elf_bit> (vaddr);
						file << vaddr;
						file << std::endl;
						
						// delimter
						//file << delim_inner;
						file << ' ';
						
						// memory content at that address
					//	file << std::bitset <addr_bit> ((unsigned long int) '0');
						file << (int short unsigned) 0;
						
						//file << delim_outer;
						file << std::endl;
					}
				}
			//}
		}
	}
	
	
	file.close ();
	
	return true;
}

bool const/* success*/ noware::vos::tool::store::extractor::clear (void)
{
	content.clear ();
	//_loaded = false;
	elf.clear ();
	
	return true;
}

bool const & noware::vos::tool::store::extractor::loaded (void) const
{
	return elf.loaded ();
}
