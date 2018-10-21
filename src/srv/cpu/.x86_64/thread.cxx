#pragma once

//#include ".instr/.incl.cxx"
//#include ".instr/.cxx"
//#include "_instr/.cxx"

/*
noware::vos::srv::cpu::x86_64::thread::thread (void)
{
	//thread_id = "";
	//_operation = "";
	operation = opr::_null;
}
*/

template <typename archive>
void noware::vos::srv::cpu::x86_64::thread::serialize (archive & arch, unsigned int const &/* version*/)
{
	arch & id;
	arch & insn_ptr;
	
	arch & eax;
	arch & ebx;
	arch & ecx;
	arch & edx;
}

std::string const noware::vos::srv::cpu::x86_64::thread::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::vos::srv::cpu::x86_64::thread> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::vos::srv::cpu::x86_64::thread::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::vos::srv::cpu::x86_64::thread> (*this, serial);
}

