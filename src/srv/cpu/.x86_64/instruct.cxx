#pragma once

//#include ".insn/.incl.cxx"
//#include ".insn/.cxx"
//#include "_instr/.cxx"

unsigned short int const noware::vos::srv::cpu::x86_64::insn::_opd_max = 4;

noware::vos::srv::cpu::x86_64::insn::insn (void)
{
	_opd_nr = 0;
	_opn = opn::_nop;
}

noware::vos::srv::cpu::x86_64::insn::insn (insn const & other)
{
	_opd_nr = other._opd_nr;
	_opn = other._opn;
	
	_opd [0] = other._opd [0];
	_opd [1] = other._opd [1];
	_opd [2] = other._opd [2];
	_opd [4] = other._opd [4];
}

template <typename archive>
void noware::vos::srv::cpu::x86_64::insn::serialize (archive & arch, unsigned int const &/* version*/)
{
	arch & _opd_nr;
	arch & _opn;
	
	arch & _opd [0];
	arch & _opd [1];
	arch & _opd [2];
	arch & _opd [4];
}

bool const noware::vos::srv::cpu::x86_64::insn::is_valid (void) const
{
	return _opd_nr > 0;
}

bool const noware::vos::srv::cpu::x86_64::insn::is_nop (void) const
{
	return _opn == opn::_nop;
}

std::string const noware::vos::srv::cpu::x86_64::insn::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::vos::srv::cpu::x86_64::insn> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::vos::srv::cpu::x86_64::insn::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::vos::srv::cpu::x86_64::insn> (*this, serial);
}

bool const noware::vos::srv::cpu::x86_64::insn::code_is_fin (std::bitset <8> const & insn_part, std::string const & code)
{
	return true;
}

std::string const noware::vos::srv::cpu::x86_64::insn::encode (void)
{
	return "";
}

insn const noware::vos::srv::cpu::x86_64::insn::decode (std::string const & code)
{
	insn _insn;
	return _insn;
}
