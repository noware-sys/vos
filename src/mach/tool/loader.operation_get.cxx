#pragma once

noware::smach::cpu::x86_64::opr const noware::mach::tool::loader::operation_get (std::string const & operation) const
{
	std::cerr << "noware::mach::tool::loader::operation_get(operation=\"" << operation << "\")" << std::endl;
	
	if (operation == "int")
	{
		return noware::smach::cpu::x86_64::opr::_int;
	}
	else if (operation == "mov")
	{
		return noware::smach::cpu::x86_64::opr::_mov;
	}
	else
	{
		return noware::smach::cpu::x86_64::opr::_none;
	}
}
