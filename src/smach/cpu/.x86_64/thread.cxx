#pragma once

//#include ".instr/.incl.cxx"
//#include ".instr/.cxx"
//#include "_instr/.cxx"

/*
noware::smach::cpu::x86_64::thread::thread (void)
{
	//thread_id = "";
	//_operation = "";
	operation = opr::_null;
}
*/

template <typename archive>
void noware::smach::cpu::x86_64::thread::serialize (archive & arch, unsigned int const &/* version*/)
{
	arch & id;
	arch & insn_ptr;
}

std::string const noware::smach::cpu::x86_64::thread::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::smach::cpu::x86_64::thread> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::smach::cpu::x86_64::thread::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::smach::cpu::x86_64::thread> (*this, serial);
}

