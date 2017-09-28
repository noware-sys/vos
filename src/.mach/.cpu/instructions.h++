class instructions
{
	public:
	//protected:
		friend class boost::serialization::access;
		// friend std::ostream & operator << (std::ostream &, const instruction &);
		
		template <typename archive>
		void serialize (archive &, const unsigned int &/* version*/);
	public:
		instructions (void);
		instructions (const instructions &);
		instructions (const instruction &);
		/*
			ID: "1"
		*/
		
		operator const std::string (void) const;
		// operator instruction (void);
		
		
		// Overwrite this set of instructions by the one parsed from the string.
		const instructions operator = (const std::string &);
		const instructions operator = (const instructions &);
		const instruction operator = (const instruction &);
		
		// bool active;	// If the instruction should be processed.
		// bool processing;	// If there is a processor processing the instruction.
		
		//std::string instructions [2];
		/*
			instructions [0] : Prerequisite instruction, if any.
			instructions [1] : Next instruction, if any.
		*/
		// std::string prerequisite_instruction;
		//std::string next_instruction;
		//std::string id;
		
		////mathematics::numbers::real inputs [2];
		// LIB::NAME_A <LIB::machine::devices::processor::instruction, LIB::mathematics::numbers::natural> _instructions;
		std::queue <LIB::machine::device::processor::instruction> _instructions;
		////std::string inputs [2];
		////LIB::NAME_V output;
		//std::string output;
		//operation _operation;
		
		// std::string user;
		////LIB::mathematics::numbers::natural processor;
};

