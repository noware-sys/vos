#pragma once

#include <noware/serial.cxx>

#include ".instr/.incl.cxx"
#include ".instr/.cxx"
#include "opr.cxx"
#include "reg.cxx"

noware::vmach::cpu::x86_64::instr::instr (void)
{
	operation = opr::none;
	args_nr = 0;
}

template <typename archive>
void noware::vmach::cpu::x86_64::instr::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & thread_id;
		
		arch & operation;
		arch & args_nr;
		
		arch & arg1;
		arch & arg2;
		arch & arg3;
}

bool const noware::vmach::cpu::x86_64::instr::null (void) const
{
	return operation == opr::none;
}

std::string const noware::vmach::cpu::x86_64::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::vmach::cpu::x86_64::instr> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::vmach::cpu::x86_64::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::vmach::cpu::x86_64::instr> (*this, serial);
}
