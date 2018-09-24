#pragma once

//#include ".insn/.incl.hxx"

class insn
	: virtual public noware::serial
{
	public:
		//#include ".instr/.hxx"
		
		insn (void);
		//virtual ~instr (void) = default;
		
		// ID of the thread
		// which this instruction
		// belongs to
		//std::string thread_id;
		
		opn _opn;
		//std::string _operation;
		
		// number of arguments which are in use
		unsigned short int _arg_nr;
		
		//noware::tree <> operand;
		//arg arg1, arg2, arg3;
		std::string _arg [3];
		
		// is this a null (no-op) instruction?:
		bool const is_null (void) const;
		
		bool const decode (std::string const &);
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
