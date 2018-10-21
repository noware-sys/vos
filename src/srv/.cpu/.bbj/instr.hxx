#pragma once

//#include ".instr/.incl.hxx"

class instr
	: virtual public noware::serial
{
	public:
		//#include ".instr/.hxx"
		
		instr (void);
		//virtual ~instr (void) = default;
		
		std::string const dump (void) const;
		// ID of the thread
		// which this instruction
		// belongs to
		//std::string thread_id;
		
		opnr _oprn;
		//std::string _operation;
		
		//// number of arguments which are in use
		//unsigned short int args_nr;
		
		//noware::tree <> operand;
		//arg arg1, arg2, arg3;
		//arg args [3];
		
		// device for source/dest
		std::string src_dev, dest_dev;
		
		std::string src, dest, next;
		
		// the location of the value
		//std::string src_dev;
		
		// is this a final instruction?:
		bool const null (void) const;
		
		virtual std::string const serialize (void) const;
		virtual bool const deserialize (std::string const &/* serial*/);
	protected:
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, unsigned int const &/* version*/);
};

//#include "_instr/.hxx"
