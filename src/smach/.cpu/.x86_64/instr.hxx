#pragma once

#include ".instr/.incl.hxx"

class instr
	: virtual public noware::serial
{
	public:
		#include ".instr/.hxx"
		
		//virtual ~instr (void) = default;
		// ID of the thread
		// which this instruction
		// belongs to
		std::string thread_id;
		
		opr operation;
		std::string _operation;
		
		// number of arguments which are in use
		unsigned short int args_nr;
		
		//noware::tree <> operand;
		arg arg1, arg2, arg3;
		//arg args [3];
		
		// is this a null (no-op) instruction?:
		bool const null (void) const;
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
