#pragma once

#include <string>
#include <noware/elf.hxx>

namespace noware
{
	namespace mach
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
						virtual bool const write_file (std::string const &/* output_file_name*/, bool const &/* pad*/ = false);
						
						virtual bool const & loaded (void) const;
						virtual bool const/* success*/ clear (void);
					protected:
						//bool _loaded;
						noware::unsigned_string content;
						noware::elf elf;
				};
			}
		}
	}
}
