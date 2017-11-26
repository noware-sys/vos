#pragma once

#include <noware/serial.hxx>

#include ".instr/.incl.hxx"
#include "opr.hxx"
#include "reg.hxx"

namespace noware
{
	namespace vmach
	{
		namespace cpu
		{
			namespace x86_64
			{
				class instr
					: virtual public noware::serial
				{
					public:
						#include ".instr/.hxx"
						
						instr (void);
						//virtual ~instr (void) = default;
						// ID of the thread
						// which this instruction
						// belongs to
						std::string thread_id;
						
						opr operation;
						//std::string operation;
						
						// number of arguments
						// which are in use
						unsigned short int args_nr;
						
						//noware::tree <> operand;
						arg arg1, arg2, arg3;
						
						bool const null (void) const;
						
						virtual std::string const serialize (void) const;
						virtual bool const deserialize (std::string const &/* serial*/);
					protected:
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive &, unsigned int const &/* version*/);
				};
				
				//#include "_instr/.hxx"
			}
		}
	}
}
