#pragma once

template <typename archive>
void noware::smach::cpu::x86_64::instr::arg::term::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & factor;
		arch & ref;
		arch & val;
}
