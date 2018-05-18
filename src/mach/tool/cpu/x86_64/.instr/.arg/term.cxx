#pragma once

noware::vmach::cpu::x86_64::instr::arg::term::term (void)
{
	factor = 0;
	ref = 0;
}

template <typename archive>
void noware::vmach::cpu::x86_64::instr::arg::term::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & factor;
		arch & ref;
		arch & val;
}
