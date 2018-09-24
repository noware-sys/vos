#pragma once

//#include ".insn/.incl.cxx"
//#include ".insn/.cxx"
//#include "_instr/.cxx"

noware::smach::cpu::x86_64::insn::insn (void)
{
	//thread_id = "";
	//_operation = "";
	_opn = opn::_null;
}

template <typename archive>
void noware::smach::cpu::x86_64::insn::serialize (archive & arch, unsigned int const &/* version*/)
{
	arch & _opn;
	arch & _arg_nr;
	
	arch & _arg [0];
	arch & _arg [1];
	arch & _arg [2];
}

bool const noware::smach::cpu::x86_64::insn::is_null (void) const
{
	return _opn == opn::_null;
}

std::string const noware::smach::cpu::x86_64::insn::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::smach::cpu::x86_64::insn> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::smach::cpu::x86_64::insn::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::smach::cpu::x86_64::insn> (*this, serial);
}

bool const noware::smach::cpu::x86_64::insn::decode (std::string const & code)
{
	return false;
}
