#pragma once

#include <string>
#include <noware/misc/elf.hxx>

namespace noware
{
	namespace vmach
	{
		namespace cpu
		{
			class extractor
			{
				public:
					//extractor (void);
					
					virtual bool const load_file (std::string const &/* elf_file_name*/);
					
					// ! overwrites
					// creates if nonexistent
					virtual bool const extract (std::string const &/* input_file_name*/, std::string const &/* output_file_name*/);
					
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
