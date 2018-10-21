#pragma once

#include <string>
#include <noware/elf.hxx>

namespace noware
{
	namespace vos
	{
		namespace tool
		{
			namespace store
			{
				class extractor
				{
					public:
						//extractor (void);
						
						virtual bool const load_file (std::string const &/* elf_file_name*/);
						
						// ! overwrites
						// creates if nonexistent
						//virtual bool const write_file (std::string const &/* output_file_name*/, bool const &/* pad*/ = false, char const &/* delim_inner*/ = delim_inner_dft, char const &/* delim_outer*/ = delim_outer_dft, unsigned short int const &/* addressable bits*/);
						virtual bool const write_file (std::string const &/* output_file_name*/, bool const &/* pad*/ = false);
						
						virtual bool const & loaded (void) const;
						virtual bool const/* success*/ clear (void);
						
						//static char const delim_inner_dft;
						//static char const delim_outer_dft;
					protected:
						//bool _loaded;
						noware::str_nsigned content;
						noware::elf elf;
				};
			}
		}
	}
}
