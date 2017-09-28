LIB::machine::device::processor::core::core (const bool & state)
{
	//thread = NULL;
	
	thread = new boost::thread (boost::bind (LIB::machine::device::processor::core::perform, this));
	
	//processor = NULL;
	
	//ended = false;
	
	//run (_run);
	run (state);
}

//LIB::machine::device::processor::core::~core (void)
//{
	//if (thread != NULL/* && !ended*/)
	
	/*
	if (thread != NULL)
	{
		//try
		//{
			
			
			// thread -> join ();

			delete thread;

			// thread = NULL;

			//ended = true;
		//}
		//catch (...)
		//{

		//}
	}
	*/
	//if (processor != NULL)
	//{
	//	processor = NULL;	// Prevent recursion, as the next line triggers this function.
	//	processor -> cores.unset (boost::this_thread::get_id ());
	//}
	
	//run (_run);
//}

const bool & LIB::machine::device::processor::core::active (void) const
{
	return running;
}

const bool LIB::machine::device::processor::core::run (const bool & state)
{
	if (processor != NULL && state && !_active)
	{
		thread = new boost::thread (boost::bind (LIB::machine::device::processor::perform, processor));
		
		_active = state;
		
		return _active;
	}
	else if (!state && _active)
	{
		delete thread;
		
		_active = state;
		
		return _active;
	}
	
	return true;
}


const LIB::machine::device::processor::core & LIB::machine::device::processor::core::operator = (const LIB::machine::device::processor::core & other)
{
	//processor = other.processor;
	thread = other.thread;
	
	return *this;
}

//void LIB::machine::device::processor::/*process::*/run (const bool & value)

{
	{
		boost::unique_lock <boost::mutex> lock (running_mutex);
		running = value;
	}
	
	running_condition_variable.notify_all ();
}

void LIB::machine::device::processor::pause (void) const
{
	//boost::unique_lock <boost::mutex> lock (running_mutex);
	std::unique_lock<std::mutex> lock (running_mutex);
	
	running_condition_variable.wait (lock, [] { return running; });
}

// Each processor/thread would be executing this for the duration of the this object, when there are instructions to be run.
void LIB::machine::device::processor::perform (void)
//void LIB::machine::device::processor::operator () (void)
{
	/*
		This is the concept:

		While there are instructions to be performed, perform them;
		otherwise, wait (preferably, without consuming any resource) for any instruction to come.
	*/
	
	while (true)
	{
		pause ();
		
		if (execute (beginning ()))
			dequeue ();
	}
}

const bool LIB::machine::device::processor::execute (const LIB::machine::device::processor::instruction & instr)
{
	switch (instr.action)
	{
		case LIB::machine::device::processor::operation::addition:
		case LIB::machine::device::processor::operation::substraction:
		case LIB::machine::device::processor::operation::multiplication:
		case LIB::machine::device::processor::operation::division:
		case LIB::machine::device::processor::operation::modulo:
		case LIB::machine::device::processor::operation::exponentiation:
			// For variable variables.
			while (((std::string) instr.input [0]) [0] == '$')
			{
				_instruction.input [0] = _memory.get (instr.input [0]);
			}
			
			while (((std::string) instr.input [1]) [0] == '$')
			{
				_instruction.input [1] = _memory.get (instr.input [1]);
			}
			
			switch (instr.action)
			{
				case LIB::machine::device::processor::operation::addition:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] + instr.input [1]);
					
					//break;

				case LIB::machine::device::processor::operation::substraction:
					return _memory.set (instr.output, instr.input [0] - instr.input [1]);
					
					//break;

				case LIB::machine::device::processor::operation::multiplication:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] * (LIB::NAME_V) instr.input [1]);
					
					//break;

				case LIB::machine::device::processor::operation::division:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] / instr.input [1]);
					
					//break;

				case LIB::machine::device::processor::operation::modulo:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] % instr.input [1]);
					
					//break;
				case LIB::machine::device::processor::operation::exponentiation:
					return _memory.set (instr.output, (LIB::NAME_V) (instr.input [0] ^ instr.input [1]));
					
					//break;
			}
			
			//break;
			
		case LIB::machine::device::processor::operation::output:
			if ((std::string) instr.input [0] == "endl")
			{
				std::cout << std::endl;
			}
			else if ((std::string) instr.input [0] == "tab")
			{
				std::cout << '\t';
			}
			else if (((std::string) instr.input [0]) [0] == '$')
			{
				//while (((std::string) _instruction.inputs [0]) [0] == '$')
				//{
				//	_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
				//}

				//std::string op = mem.get (_instruction.inputs [0]);
				//std::cout << op;
				std::cout << _memory.get (instr.input [0]);
			}
			else
			{
				//std::string str = _instruction.inputs [0];
				//std::cout << str;
				std::cout << instr.input [0];
			}
			
			//std::cout.flush ();
			
			return true;
			//break;

		case LIB::machine::device::processor::operation::modulus:
			return _memory.set (instr.output, (LIB::NAME_V) LIB::tools::modulus (instr.input [0]));
			
			//break;
			
		case LIB::machine::device::processor::operation::complement:
			return _memory.set (instr.output, (LIB::NAME_V) LIB::tools::complement (instr.input [0]));
			
			//break;
			
		case LIB::machine::device::processor::operation::assignment:
			while (((std::string) instr.input [0]) [0] == '$')
			{
				instr.input [0] = _memory.get (instr.input [0]);
			}
			
			return _memory.set (instr.output, instr.input [0]);
			
			//break;
		//default:
		//	return LIB::mathematics::numbers::default;
	}
	
	return true;
}

