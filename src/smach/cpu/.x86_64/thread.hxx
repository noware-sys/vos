#pragma once

//#include ".thread/.incl.hxx"

class thread
	: virtual public noware::serial
{
	public:
		//#include ".thread/.hxx"
		
		//thread (void);
		//virtual ~thread (void);
		
		// Thread ID.
		// Effectively, the store group.
		std::string id;
		
		// Next instruction pointer.
		// Effectively, the store key.
		std::string insn_ptr;
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
