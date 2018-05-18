#pragma once

#include ".instr/.incl.cxx"
#include ".instr/.cxx"
//#include "_instr/.cxx"

noware::smach::cpu::x86_64::instr::instr (void)
{
	//thread_id = "";
	//_operation = "";
	operation = opr::_null;
}

template <typename archive>
void noware::smach::cpu::x86_64::instr::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & thread_id;
		
		arch & operation;
		arch & _operation;
		arch & args_nr;
		
		arch & arg1;
		arch & arg2;
		arch & arg3;
}

bool const noware::smach::cpu::x86_64::instr::null (void) const
{
	return operation == opr::_null;
}

std::string const noware::smach::cpu::x86_64::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::smach::cpu::x86_64::instr> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::smach::cpu::x86_64::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::smach::cpu::x86_64::instr> (*this, serial);
}

