#pragma once

template <typename archive>
void noware::mach::cpu::x86_64::instr::arg::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & ref;
		arch & terms_nr;
		
		arch & term1;
		arch & term2;
		arch & term3;
}
