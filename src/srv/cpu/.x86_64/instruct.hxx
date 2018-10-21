#pragma once

//#include ".insn/.incl.hxx"

// an instruction
class instruct
	: virtual public noware::serial
{
	public:
		//#include ".instr/.hxx"
		
		instruct (void);
		instruct (instruct const &/* other*/);
		//virtual ~instr (void) = default;
		
		// is this an actual instruction?:
		virtual bool const is_valid (void) const;
		
		// is this a null instruction?:
		virtual bool const is_null (void) const;
		
		// convert asm -> bin
	//	static std::string const encode (void);
		// convert bin -> asm
	//	static instruct const decode (std::string const &);
		
		// determine if the provided part is the last one of the instruction,
		// while considering the code that there is so far
	//	static bool const code_is_fin (std::bitset <8> const &/* instruction part (8 bits)*/, std::string const &/* code so far*/ = "");
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
		
		/*
		// maximum number of operands which can be used
		static unsigned short int const _opd_max;
		
		// number of operands which are in use
		unsigned short int _opd_nr;
		
		//noware::tree <> operand;
		std::string _opd [4];
		
		// the operation
		opn _opn;
		*/
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
