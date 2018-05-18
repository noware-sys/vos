#pragma once

#include ".arg/.incl.cxx"
#include ".arg/.cxx"

template <typename archive>
void noware::smach::cpu::x86_64::instr::arg::serialize (archive & arch, unsigned int const &/* version*/)
{
		arch & ref;
		arch & terms_nr;
		
		arch & term1;
		arch & term2;
		arch & term3;
}
