#pragma once

#include <noware/serial.cxx>

#include ".instr/.incl.cxx"
#include ".instr/.cxx"
#include "opr.cxx"
#include "reg.cxx"

noware::vmach::cpu::x86_64::instr::instr (void)
{
	operation = opr::none;
	arg_nr = 0;
}

template <typename archive>
void noware::vmach::cpu::x86_64::instr::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & thread_id;
		
		arch & operation;
		arch & arg_nr;
		
		arch & arg [0];
		arch & arg [1];
		arch & arg [2];
		arch & arg [3];
}

bool const noware::vmach::cpu::x86_64::instr::is_null (void) const
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
