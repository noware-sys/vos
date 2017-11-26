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
		arch & terms_nr;
		
		arch & term1;
		arch & term2;
		arch & term3;
}
