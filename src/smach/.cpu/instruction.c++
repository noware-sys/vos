LIB::machine::device::processor::instruction::instruction (void)
{
	// inputs [0] = inputs [1] = (std::string) "";
	action = operation::none;
	//active = true;
	//processing = false;
	
	// next_instruction = "";
	
	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";
	output = "";

	//user = "Guest";	// The default user.
	// user = 0;	// No user.	// The default user, the administrator.
}

LIB::machine::device::processor::instruction::instruction (const instruction & other)
{
	//*this = other;
	
	input [0] = other.input [0];
	input [1] = other.input [1];
	
	output = other.output;
	
	action = other.action;
	//next_instruction = other.next_instruction;
	
	//user = other.user;
	
	//return *this;
}

LIB::machine::device::processor::instruction::instruction (const std::string & instr)
{
	*this = instr;
}

template <typename archive>
void LIB::machine::device::processor::instruction::serialize (archive & arch, const unsigned int & version)
{
	//try
	//{
		// archive & processing;

		//destination & instructions [0];
		//destination & instructions [1];
		//archive & next_instruction;

		//archive & inputs;
		arch & input [0];
		arch & input [1];

		arch & output;

		arch & action;

		//archive & user;
	//}
	//catch (...)
	//{
	//	//next_instruction = "";
	//	action = operation::none;
	//	output = "";
	//	//user = 0;
	//}
}

LIB::machine::device::processor::instruction::operator const std::string (void) const
{
	return LIB::serialize <LIB::machine::device::processor::instruction> (*this);
}

//LIB::machine::device::processor::instruction
LIB::machine::device::processor::instruction LIB::machine::device::processor::instruction::operator = (const std::string & serial)
{
	LIB::deserialize <LIB::machine::device::processor::instruction> (serial, *this);
	/*
	if (LIB::deserialize <LIB::machine::device::processor::instruction> (serial, *this))
	{
		//return *this;
		return serial;
	}
	else
	{
		return "";
	}
	*/
	return *this;
}

LIB::machine::device::processor::instruction LIB::machine::device::processor::instruction::operator = (const LIB::machine::device::processor::instruction & other)
{
	input [0] = other.input [0];
	input [1] = other.input [1];
	
	output = other.output;
	
	action = other.action;
	
	//next_instruction = other.next_instruction;
	
	//user = other.user;
	
	return *this;
}

