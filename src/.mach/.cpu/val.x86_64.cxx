#pragma once

bool const noware::mach::cpu::val (vmach::cpu::x86_64::instr const & instr)
{
	std::string thread_id = std::string ("thread ") + instr.thread_id;
	
	if (instr.operation == "mov")
	{
		std::cerr << "noware::mach::cpu::val()::mov(thread_id=\"" << thread_id << "\", dest=\"" << instr.arg1.term1.val << "\", src=\"" << instr.arg2.term1.val << "\")" << std::endl;
		return set (thread_id, instr.arg1.term1.val, instr.arg2.term1.val);
	}
	else if (instr.operation == "int")
	{
		std::cerr << "noware::mach::cpu::val()::int" << std::endl;
		
		if (instr.arg1.term1.val == "128")
		// a system call
		{
			std::cerr << "noware::mach::cpu::val()::int==128" << std::endl;
			
			if (get (thread_id, "eax") == "4")
			// to sys_write
			{
				std::cerr << "noware::mach::cpu::val()::eax==4" << std::endl;
				
				// with the file descriptor
				if (get (thread_id, "ebx") == "1")
				// being std output
				{
					std::cerr << "noware::mach::cpu::val()::ebx==1" << std::endl;
					
					// sys_call sys_write to std_output
					unsigned int max = noware::nr (get (thread_id, "edx")).operator unsigned int const ();
					std::cerr << "noware::mach::cpu::val()::max[" << max << "]" << std::endl;
					for (unsigned int ndx = noware::nr (get (thread_id, "ecx")).operator unsigned int const (); max > 0; --max, ++ndx)
					{
						std::cerr << "noware::mach::cpu::val()::ndx[" << ndx << "]" << std::endl;
						if (!cout (get (thread_id, noware::nr (ndx).operator std::string const ())))
						{
							std::cerr << "noware::mach::cpu::val()::cout[false]" << std::endl;
							//return false;
						}
						
						std::cerr << "noware::mach::cpu::val()::cout[true]" << std::endl;
						//return true;
					}
					
					/*
					// sys_call sys_write to std_output
					unsigned int max = noware::nr (get (thread_id, "edx")).operator unsigned int const ();
					std::cerr << "noware::mach::cpu::val()::max[" << max << "]" << std::endl;
					for (unsigned int ndx = noware::nr (get (thread_id, "ecx")).operator unsigned int const (); ndx < max; ++ndx)
					{
						std::cerr << "noware::mach::cpu::val()::ndx[" << ndx << "]" << std::endl;
						if (!cout (get (thread_id, noware::nr (ndx).operator std::string const ())))
						{
							std::cerr << "noware::mach::cpu::val()::cout[false]" << std::endl;
							return false;
						}
						
						std::cerr << "noware::mach::cpu::val()::cout[true]" << std::endl;
						return true;
					}
					*/
				}
				else
				{
					std::cerr << "noware::mach::cpu::val()::ebx!=1" << std::endl;
				}
			}
			else
			{
				std::cerr << "noware::mach::cpu::val()::eax!=4" << std::endl;
			}
		}
		else
		{
			std::cerr << "noware::mach::cpu::val()::int!=128" << std::endl;
		}
		
		return true;
	}
	else
	{
		std::cerr << "noware::mach::cpu::val()::operation::other" << std::endl;
		return false;
	}
}
