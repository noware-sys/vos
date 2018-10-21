#pragma once

class instr
	: virtual public noware::serial
{
	public:
		instr (void);
		instr (const std::string &/* other*/);
		virtual ~instr (void);
		
		virtual const instr & operator = (const instr &/* other*/);
		virtual const std::string & operator = (const std::string &/* other*/);
		virtual operator const std::string (void) const;
		
		//#include ".cpu/instr.x86_64.hxx"
		
		std::string thread_id;
		
		//opr oprn;	// Optional.
		//dev device;
		
		noware::nr result_ref;
		std::string result_dev;
		std::string result_key;
		noware::nr result_offset_prefetch_ref;
		std::string result_offset_prefetch_dev;
		std::string result_offset_prefetch_key;
		noware::nr result_offset_postfetch_ref;
		std::string result_offset_postfetch_dev;
		std::string result_offset_postfetch_key;
		
		// operation action
		std::string oprn;
		
		noware::nr dest_ref;
		std::string dest_dev;
		std::string dest_key;
		noware::nr dest_offset_prefetch_ref;
		std::string dest_offset_prefetch_dev;
		std::string dest_offset_prefetch_key;
		noware::nr dest_offset_postfetch_ref;
		std::string dest_offset_postfetch_dev;
		std::string dest_offset_postfetch_key;
		
		noware::nr src_ref;
		std::string src_dev;
		std::string src_key;
		noware::nr src_offset_prefetch_ref;
		std::string src_offset_prefetch_dev;
		std::string src_offset_prefetch_key;
		noware::nr src_offset_postfetch_ref;
		std::string src_offset_postfetch_dev;
		std::string src_offset_postfetch_key;
		
		
		/*
		
		// operand
		// Convention for the move instruction.
		// oprnd [0] == source (always (should be) (enqueued as) a literal)
		// oprnd [1] == destination, key
		// oprnd [2] == destination, group
		//noware::var operand1;
		//noware::var operand2;	// Optional.
		//std::string oprnd [2];
		noware::var oprnd [2];
		//std::string oprnd [3];
		bool _ref [2];
		bool _offset [2];
		noware::var offset [2];
		*/
		// Does the source operand
		// represent a reference?
		// (or a literal?)
		//bool oprnd_src_ref;
	//	std::map <std::string, std::string> arg;
	//	std::map <std::string, std::string> arg_type;
		
		//bool reg;
		//noware::nr reg_nr;
		//noware::nr ndx;
		
		//dependents;	// Not really needed.
		//dependencies;
		
		// evaluate value val
		//const bool operator== (const instruction &/* other*/) const;
	//	virtual const std::string /*e*/val/*uate*/ (void) const;
		
		
		friend class boost::serialization::access;
		
		template <typename archive>
		void serialize (archive &, const unsigned int &/* version*/);
	public:
		// TODO
		// 
		// also inherit
		// these two functions
		// from noware::serial
		// (do not reimplement)
		virtual const std::string serialize (void) const;
		virtual const bool deserialize (const std::string &/* serial*/);
		
		virtual void dump (void) const;
};
