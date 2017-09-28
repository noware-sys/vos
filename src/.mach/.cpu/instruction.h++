class instruction
{
	public:
	//protected:
		friend class boost::serialization::access;
		// friend std::ostream & operator << (std::ostream &, const instruction &);
		
		template <typename archive>
		void serialize (archive &, const unsigned int &/* version*/);
	//public:
		instruction (void);
		instruction (const instruction &/* other*/);
		instruction (const std::string &/* serial representation; text archive*/);
		/*
			ID: "1"
		*/
		
		operator const std::string (void) const;
		// operator instruction (void);
		
		// Overwrite this instruction by the one parsed from the string.
		const std::string operator = (const std::string &/* serial*/);
		const instruction operator = (const instruction &/* other*/);
		
		
		// bool active;	// If the instruction should be processed.
		// bool processing;	// If there is a processor processing the instruction.
		
		//std::string instructions [2];
		/*
			instructions [0] == Prerequisite instruction, if any.
			instructions [1] == Next instruction, if any.
		*/
		// std::string prerequisite_instruction;
		// std::string next;
		// std::string id;
		//std::string next_sequence;
		
		//mathematics::numbers::real inputs [2];
		LIB::container::NAME_V input [2];
		//std::string inputs [2];
		//LIB::NAME_V output;
		std::string output;
		
		operation action;
		
		// std::string user;
		// LIB::mathematics::numbers::natural user;	// The ID of the user who owns this instructions; who enqueued this instruction.
		//LIB::mathematics::numbers::natural processor;
};

