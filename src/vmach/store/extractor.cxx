#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <noware/misc/elf.cxx>

#include "extractor.hxx"

/*
noware::vmach::store::extractor::extractor (void)
{
	_loaded = false;
}
*/

bool const/* success*/ noware::vmach::store::extractor::load_file (std::string const & file_name)
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


bool const/* success*/ noware::vmach::store::extractor::write_file (std::string const & file_name, bool const & pad)
{
	std::ofstream file;
	
	
	file.open (file_name, std::ios::out | std::ios::trunc);
	
	if (!file.is_open ())
		return false;
	
	
	// Load all 'LOAD' program segments into memory
	unsigned long int phndx, phnum;
	unsigned long int j;
	unsigned long int vaddr;
	unsigned long int filesz, memsz;
	unsigned long int flag;
	
	phnum = noware::elf::integer (elf.hdr.phnum.data, true);
	for (phndx = 0; phndx < phnum; ++phndx)
	{
		// If this program segment is of the type 'LOAD', then load it
		if (noware::elf::integer (elf.prog [phndx].type.data, true) == 0x1/*PT_LOAD*/)
		{
			// Write the program segment into the output file
			filesz = noware::elf::integer (elf.prog [phndx].filesz.data, true);
			vaddr = noware::elf::integer (elf.prog [phndx].vaddr.data, true);
			flag = noware::elf::integer (elf.prog [phndx].flag.data, true);
			
			if (!(flag & 0x1/*eXecute*/))
			{
				for (j = 0; j < filesz; ++j, ++vaddr)
				{
					// 8 bits (1 byte) at a time
					
					//dam [vaddr] = file.prog [phndx].data.data.substr (j, 1/* 8 bits (1 byte) at a time*/);
					//dam [vaddr] = file.prog [phndx].data.data [j];
					
					// memory address
					file << vaddr << std::endl;
					
					// memory content at that address
					if (elf.prog [phndx].data.data [j] == 0xA)
						file << "\\n" << std::endl;
					else
						file << elf.prog [phndx].data.data [j] << std::endl;
				}
				
				if (pad)
				{
					// Pad the remaining space with zeroes
					memsz = noware::elf::integer (elf.prog [phndx].memsz.data, true);
					for (; j < memsz; ++j, ++vaddr)
					{
						//dam [vaddr] = (unsigned char) '0';
						
						// memory address
						file << vaddr << std::endl;
						
						// memory content at that address
						file << '0' << std::endl;
					}
				}
			}
		}
	}
	
	
	file.close ();
	
	return true;
}

bool const/* success*/ noware::vmach::store::extractor::clear (void)
{
	content.clear ();
	//_loaded = false;
	elf.clear ();
	
	return true;
}

bool const & noware::vmach::store::extractor::loaded (void) const
{
	return elf.loaded ();
}
