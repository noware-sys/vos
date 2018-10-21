#pragma once

#include ".arg/.cxx"

noware::vmach::cpu::x86_64::instr::arg::arg (void)
{
	ref = 0;
	terms_nr = 0;
}

template <typename archive>
void noware::vmach::cpu::x86_64::instr::arg::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & ref;
		arch & term_nr;
		
		arch & term [0];
		arch & term [1];
		arch & term [2];
		arch & term [3];
}
