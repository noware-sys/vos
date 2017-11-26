#pragma once

noware::vmach::cpu::x86_64::opr const noware::vmach::cpu::loader::operation_get (std::string const & operation) const
{
	std::cerr << "noware::vmach::cpu::loader::operation_get(operation=\"" << operation << "\")" << std::endl;
	
	if (operation == "int")
	{
		return noware::vmach::cpu::x86_64::opr::int_;
	}
	else if (operation == "mov")
	{
		return noware::vmach::cpu::x86_64::opr::mov;
	}
	else
	{
		return noware::vmach::cpu::x86_64::opr::none;
	}
}
