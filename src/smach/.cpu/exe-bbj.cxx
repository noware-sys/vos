#pragma once

bool const noware::smach::cpu::exe (/*vmach::cpu::*/bbj::instr const & instr, std::string const & thread_name)
{
	//std::string thread_name;
	//thread_name = std::string ("thread ") + thread_id;
	
	std::cerr << "noware::mach::cpu::exe()::instr.operation[" << instr.operation << "]" << std::endl;
	//switch (instr.operation)
	//{
	//	case /*vmach::cpu::*/bbj::opr::_bbj:
			std::cerr << "noware::smach::cpu::exe()::int" << std::endl;
			
			// the output value
			std::string val;
			
			// input:
			if (instr.src_dev == "1")	// reference to store
				val = get (thread_name, instr.src);
			else if (instr.src_dev == "4")	// reference to cmd
			{
				if (!cin (val))
					return false;
			}
			else if (instr.src_dev == "0")
				// literal
				val = instr.src;
			else
				return false;
			
			std::cerr << "noware::smach::cpu::exe()::bbj(thread_name=\"" << thread_name << "\", dest=\"" << instr.dest << "\", src=\"" << val << "\")" << std::endl;
			
			//output:
			if (instr.dest_dev == "1")	// store
				return set (thread_name, instr.dest, val);
			else if (instr.dest_dev == "4")	// cmd
				return cout (val);
			else
				return false;
			
			//return true;
		//default:
		//	std::cerr << "noware::smach::cpu::exe()::operation::other" << std::endl;
		//	return false;
	//}
	
	return false;
}
