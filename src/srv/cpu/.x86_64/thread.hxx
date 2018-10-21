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
		store_grp_t id;
		
		// Next instruction pointer.
		// Effectively, the key in the store.
		store_key_t insn_ptr;
		
		
		// For saving the CPU state between de/serializations.
		// CPU registers
		uint64_t eax;
		uint64_t ebx;
		uint64_t ecx;
		uint64_t edx;
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
