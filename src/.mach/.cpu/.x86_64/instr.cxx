#include ".instr/.cxx"
//#include "_instr/.cxx"

template <typename archive>
void noware::mach::cpu::x86_64::instr::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & thread_id;
		
		arch & operation;
		arch & _operation;
		arch & args_nr;
		
		arch & arg1;
		arch & arg2;
		arch & arg3;
}

bool const noware::mach::cpu::x86_64::instr::null (void) const
{
	return false;
}


std::string const noware::mach::cpu::x86_64::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::mach::cpu::x86_64::instr> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::mach::cpu::x86_64::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::mach::cpu::x86_64::instr> (*this, serial);
}

