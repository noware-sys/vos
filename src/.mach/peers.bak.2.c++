//#include <vector>
#include <sstream>
//#include <fstream>
#include <sstream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
//#include <boost/thread/exceptions.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "processor.hpp"

// Computational platform.

LIB::cluster::processor::instruction::instruction (void)
{
	// inputs [0] = inputs [1] = (std::string) "";
	action = operation::none;
	//active = true;
	//processing = false;
	
	next_instruction = "";
	
	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";
	output = "";

	//user = "Guest";	// The default user.
	user = 0;	// No user.	// The default user, the administrator.
}

LIB::cluster::processor::instruction::instruction (const instruction & other)
{
	//*this = other;

	inputs [0] = other.inputs [0];
	inputs [1] = other.inputs [1];

	output = other.output;
	
	action = other.action;
	next_instruction = other.next_instruction;

	user = other.user;

	//return *this;
}

LIB::cluster::processor::instruction::instruction (const std::string & instr)
{
	*this = instr;
}

template <typename Archive>
void LIB::cluster::processor::instruction::serialize (Archive & archive, const unsigned int version)
{
	try
	{
		// archive & processing;

		//destination & instructions [0];
		//destination & instructions [1];
		archive & next_instruction;

		//archive & inputs;
		archive & inputs [0];
		archive & inputs [1];

		archive & output;

		archive & action;

		archive & user;
	}
	catch (...)
	{
		next_instruction = "";
		action = operation::none;
		output = "";
		user = 0;
	}
}

LIB::cluster::processor::instruction::operator std::string (void)
{
	return LIB::serialize <LIB::cluster::processor::instruction> (*this);
}

LIB::cluster::processor::instruction LIB::cluster::processor::instruction::operator = (std::string serial)
{
	LIB::parse <LIB::cluster::processor::instruction> (serial, *this);

	return *this;
}

LIB::cluster::processor::instruction LIB::cluster::processor::instruction::operator = (const LIB::cluster::processor::instruction & other)
{
	inputs [0] = other.inputs [0];
	inputs [1] = other.inputs [1];

	output = other.output;
	
	action = other.action;
	
	next_instruction = other.next_instruction;
	
	user = other.user;

	return *this;
}

LIB::cluster::processor::instructions::instructions (void)
{
	//active = true;
	//processing = false;

	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";

	//user = "Guest";	// The default user.
}

LIB::cluster::processor::instructions::instructions (const instructions & other)
{
	//operator= (other);
	instructions_ = other.instructions_;
}

template <typename Archive>
void LIB::cluster::processor::instructions::serialize (Archive & archive, const unsigned int version)
{
	//archive & _instructions;

	//archive & user;
}

LIB::cluster::processor::instructions::operator std::string (void)
{
	return LIB::serialize <LIB::cluster::processor::instructions> (*this);
}

LIB::cluster::processor::instructions LIB::cluster::processor::instructions::operator = (const std::string & serial)
{
	LIB::parse <LIB::cluster::processor::instructions> (serial, *this);

	return *this;
}

LIB::cluster::processor::instructions LIB::cluster::processor::instructions::operator = (const LIB::cluster::processor::instructions & other)
{
	instructions_ = other.instructions_;

	return *this;
}

//LIB::cluster::processor::queue::queue (void)
//{
//
//}
//
//LIB::cluster::processor::queue::~queue (void)
//{
//
//}
//
//template <typename Archive>
//LIB::cluster::processor::queue::serialize (Archive & archive, const unsigned int version)
//{
//	archive & _queue;
//}
//
//LIB::cluster::processor::queue::operator std::string (void) const
//{
//	return LIB::serialize <LIB::cluster::processor::queue> (*this);
//}
//
//LIB::cluster::processor::queue LIB::cluster::processor::queue::operator = (const std::string & serial)
//{
//	LIB::parse <LIB::cluster::processor::queue> (serial, *this);
//
//	return *this;
//}

LIB::cluster::processor::process::process (void /*const bool & _run*/)
{
	thread = NULL;
	
	//ended = false;
	
	//run (_run);
}

LIB::cluster::processor::process::~process (void)
{
	if (thread != NULL/* && !ended*/)
	{
		//try
		//{
			
			
			thread -> join ();

			delete thread;

			thread = NULL;

			//ended = true;
		//}
		//catch (...)
		//{

		//}
	}

	//run (_run);
}

void LIB::cluster::processor::/*process::*/run (const bool & value)
{
	{
		boost::unique_lock <boost::mutex> lock (running_mutex);
		running = value;
	}
	
	running_condition_variable.notify_all ();
}

void LIB::cluster::processor::/*process::*/pause (void)
{
	boost::unique_lock <boost::mutex> lock (running_mutex);

	while (!running)
	{
		running_condition_variable.wait (lock);
	}
}

// Processor.

LIB::cluster::processor::processor (const bool & run_)
{
	// Initialize random seed:
	//srand ((unsigned) time (NULL));

	//timeout = 4;
	running_main = true;

	run (run_);
	
	//last_instruction = "";

	// Create the threads.

	//boost::thread * thread = new boost::thread (boost::bind (LIB::cluster::processor::initialize, this));

	//threads [thread -> get_id ()].thread = thread;
	//threads [boost::this_thread::get_id ()].queue
	//threads.enqueue ();
	
	//LIB::cluster::processor::process temp_platform;
	//threads.begin ();	// Reset the iterator to the beginning (for *this.enqueue ()).

	//#pragma omp parallel for private (temp_platform)
	//{
	//	mathematics::numbers::natural n = omp_get_thread_num ();

	//	for (mathematics::numbers::natural i = 0; i < n; ++ i/*, ++ threads*/)
	//	{
	//		temp_platform.thread = new boost::thread (boost::bind (& LIB::cluster::processor::perform, this));
	//		//temp_platform.thread = new boost::thread (*this);

	//		threads [temp_platform.thread -> get_id ()] = temp_platform;
	//	}
	//}

	//if (! memory.search ("queue"))	// If "queue" does not exist.
	//	memory.set ("queue", _queue);

	//temp_platform.thread = NULL;

	LIB::cluster::processor::process temp_platform;
	mathematics::numbers::natural n;
	n = 
			//omp_get_num_procs ()
			//boost::thread::hardware_concurrency ()
			1
		;
	//threads.begin ();	// Reset the iterator to the beginning (for *this.enqueue ()).

	for (mathematics::numbers::natural i = 0; i < n; ++ i/*, ++ threads*/)
	{
		temp_platform.thread = new boost::thread (boost::bind (& LIB::cluster::processor::perform, this));
		//temp_platform.thread = new boost::thread (*this);
		
		//temp_platform.thread -> detach ();
		threads [temp_platform.thread -> get_id ()] = temp_platform;
	}
	
	// This is important, so that its destructor's body does not delete a needed thread.
	temp_platform.thread = NULL;
	
	processors.max (threads.size ());
	
	//std::cout << "Created threads." << std::endl;
}

LIB::cluster::processor::~processor (void)
{
	running_main = false;

	/*
		Complete any remaining instructions in the queue,
		so that the threads can be joined
		and so that they do not remain blocked, if they are paused.
	*/
	run (true);

	// Wait for other threads to finish?
	//io.reset ();

	//timer -> expires_from_now (boost::posix_time::seconds (timeout));
	//timer -> async_wait (boost::bind (& LIB::cluster::processor::dummy, this));
	
	//io.run ();

	//if (timer != NULL)
	//{
	//	delete timer;
	//	timer = NULL;
	//}
}


//void LIB::cluster::processor::run (const bool value)
//{
//	LIB::mathematics::numbers::natural n = threads.size ();
//
//	for (LIB::mathematics::numbers::natural i = 0; i < n; ++ i, ++ threads)
//	{
//		threads.current ().run (value);
//	}
//}

//bool LIB::cluster::processor::enqueue (LIB::cluster::processor::instructions _instructions)
//{
//	////return enqueue (_instruction, LIB::random (threads.size (), 1));
//
//	//std::string k, v;
//	////std::stringstream ss;
//	////std::vector <std::string> strings;
//
//	////strings = boost::split (strings, _instruction.next_instruction, boost::is_any_of (":"));
//
//	////std::ofstream ofs("archive.txt");
//	////boost::archive::text_oarchive oa (ofs);
//
//	////k = strings.operator[] (0);
//	//k = _instruction.id;
//	////ss << _instruction;
//	////ss >> v;
//	//v = _instruction;
//	////_instruction.parse (v);
//
//	//memory.set (k, v);
//
//	//return true;
//	//return enqueue (_instruction, random_processor ());	// Original.
//	///
//
//	LIB::mathematics::numbers::natural n, i, index;
//
//	index = random_processor ();
//
//	/*
//		Assign the instruction to a random processor;
//		this means to add it to the random processor's instruction queue.
//	*/
//
//	//threads.begin ();
//	//boost::thread::id * id = & threads.current ().thread -> get_id ();	//boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//boost::thread::id id = boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//++ threads;
//
//	//LIB::cluster::processor::process * process = & threads.current ();//& threads [* id];	// Prevent searching through the array again; this may increase performance.
//	//LIB::cluster::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
//	LIB::cluster::processor::process * thread = & threads.get_value (index);	// Prevent searching through the array again; this may increase performance.
//
//	//return process -> queue.enqueue (_instruction);
//	//return threads.current ().queue.enqueue (_instruction);
//	
//	//return threads.get_value (index).queue.enqueue (_instruction);
//	for (_instructions._instructions.begin (), n = _instructions._instructions.size (), i = 0; i < n; ++ _instructions._instructions, ++ i)
//	{
//		//threads.get_value (index).queue.push (_instructions._instructions.current ());
//		thread -> queue.push (_instructions._instructions.current ());
//	}
//
//	return true;
//
//	//if (process -> queue.enqueue (_instruction))
//	//{
//	//	//process -> run (true);
//
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//	//return true;
//}

//bool LIB::cluster::processor::enqueue (const LIB::cluster::processor::instruction & _instruction, LIB::mathematics::numbers::natural index)
//{
//	/*
//		Assign the instruction to a random processor;
//		this means to add it to the random processor's instruction queue.
//	*/
//
//	//threads.begin ();
//	//boost::thread::id * id = & threads.current ().thread -> get_id ();	//boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//boost::thread::id id = boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//++ threads;
//
//	//LIB::cluster::processor::process * process = & threads.current ();//& threads [* id];	// Prevent searching through the array again; this may increase performance.
//	//LIB::cluster::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
//
//	//return process -> queue.enqueue (_instruction);
//	//return threads.current ().queue.enqueue (_instruction);
//	
//	//return threads.get_value (index).queue.enqueue (_instruction);
//
//	//// Indexing starts at 
//	//if (index == 0)
//	//	index = 1;
//
//	while (index > threads.size ())
//		index = index - threads.size ();
//
//	threads.get_value (index).queue.push (_instruction);
//	
//	return true;
//
//	//if (process -> queue.enqueue (_instruction))
//	//{
//	//	//process -> run (true);
//
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//	//return true;
//}

//bool LIB::cluster::processor::enqueue (const std::string & file_name)
//{
//	//if (!parse (instructions))
//	//	return false;
//
//	std::ifstream infile;
//	std::string token;
//	//char cc; // Current character.
//
//	infile.open (file_name);
//
//	if (!infile.is_open ())
//		return false;
//
//	//LIB::cluster::processor::parser _parser;
//	//std::queue <std::string> parentheses;
//	LIB::NAME_A <std::string, LIB::mathematics::numbers::natural> parentheses;
//	std::queue <LIB::cluster::processor::instruction> instructions;
//	//LIB::NAME_A <LIB::cluster::processor::instruction, LIB::mathematics::numbers::natural> instructions;
//	LIB::cluster::processor::instruction instruction;
//	std::string next_instruction = (LIB::NAME_V) get_next_instruction ();	// Next available instruction ID.
//	LIB::mathematics::numbers::natural next_subinstruction = 0;
//	LIB::mathematics::numbers::natural processor = random_processor ();
//	//static enum tokens {};
//	//static std::map <std::string, tokens> tokens_map;
//	//static char sz [255];
//	//char token_c;
//	bool serialize = false;
//	//bool c = true;	// Continue the main loop.
//	bool commenting = false;	// For multi-line comments.
//
//	while (infile >> token)
//	{
//		if (token == "*/" && commenting)
//		{
//			commenting = false;
//		}
//		else if (commenting)
//		{
//			continue;	// Skip string/token if commenting.
//		}
//		else if (token == "/*")
//		{
//			// Skip until the token "*/" is encountered. If it is not encountered, assume that the comment spans until the end of the file.
//			//token_c = infile.peek ();
//			commenting = true;
//		}
//		//else if (token == "*/")
//		//{
//		//	commenting = false;
//		//}
//		else if (token == "//")
//		{
//			// Skip the whole current line.
//			std::getline (infile, token, '\n');
//		}
//		else if (token == "#include")
//		{
//
//		}
//		else if (token == "#serialize")
//		{
//			serialize = true;
//		}
//		else if (token == "{")
//		{
//			//parentheses.push (token);
//		}
//		else if (token == "}")
//		{
//			if (serialize)
//				serialize = false;
//
//			//parentheses.pop ();
//		}
//		else if (token == "global")
//		{
//
//		}
//		//else if (token == "shared")
//		//{
//
//		//}
//		else if (token == "cout")
//		{
//			do
//			{
//				if (!(infile >> token))
//					break;
//
//				if (token == "endl")
//				{
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::cluster::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					//instruction.id = next_instruction + ":" + (next_subinstruction == 0 ? 0 : next_subinstruction);
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				else if (token [0] == '$')
//				{
//					//instruction.inputs [0] = token.substr (1);
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::cluster::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				else if (token != "<<" && token != ";")
//				{
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::cluster::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				//else if (token == ";" && !serialize)
//				//{
//				//	processor = random_processor ();
//				//}
//			}
//			while (token != ";");
//		}
//		else if (token [0] == '$')
//		{
//			//std::string destination = token.substr (1);
//			std::string destination = token;
//
//			do
//			{
//				if (!(infile >> token))
//					break;
//
//				if (token == "=")
//				{
//					// Set the output.
//					instruction.output = destination;
//
//					// Get the first operand:
//					if (!(infile >> token))
//						break;
//
//					//instruction.inputs [0] = token [0] == '$' ? token.substr (1) : token;
//					instruction.inputs [0] = token;
//
//					// Get the operation:
//					if (!(infile >> token) || token.length () != 1)
//						break;
//
//					switch (token [0])
//					{
//						case '+':
//							instruction._operation = LIB::cluster::processor::operation::add;
//							
//							break;
//
//						case '-':
//							instruction._operation = LIB::cluster::processor::operation::substract;
//							
//							break;
//
//						case '*':
//							instruction._operation = LIB::cluster::processor::operation::multiply;
//							
//							break;
//						case '/':
//							instruction._operation = LIB::cluster::processor::operation::divide;
//							
//							break;
//
//						case '%':
//							instruction._operation = LIB::cluster::processor::operation::modulo;
//							
//							break;
//
//						case ';':
//							instruction._operation = LIB::cluster::processor::operation::assign;
//							
//							//break;
//
//						//default:
//						//	break;
//					}
//
//					// Get the next token:
//					//if (!(infile >> token))
//					//	break;
//
//					if (token == ";")
//					{
//						instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//						instruction.processor = processor;
//
//						//instructions.enqueue (instruction);
//						instructions.push (instruction);
//
//						break;
//					}
//					else
//					{
//						// Get the second operand, if applicable:
//						if (!(infile >> token))
//							break;
//
//						//instruction.inputs [1] = token [0] == '$' ? token.substr (1) : token;
//						instruction.inputs [1] = token;
//
//
//						//if (!serialize)
//						//	processor = random_processor ();
//
//						instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//						instruction.processor = processor;
//
//						//instructions.enqueue (instruction);
//						instructions.push (instruction);
//
//						if (!(infile >> token))	// Expect the ';' character.
//							break;
//					}
//				}
//				//else if (token == ";" && !serialize)
//				//{
//				//	processor = random_processor ();
//				//}
//				else
//					break;
//			}
//			while (token != ";");
//		}
//		
//		if (serialize)
//		{
//			++ next_subinstruction;
//		}
//		else
//		{
//			processor = random_processor ();
//
//			next_instruction = (LIB::NAME_V) get_next_instruction ();
//			increment_next_instruction ();
//			//memory.set ("next instruction", (LIB::NAME_V) (++ ((LIB::NAME_V) memory.get ("next instruction"))));	// Update the ID.
//
//			if (next_subinstruction != 0)
//				next_subinstruction = 0;	// Reset the next subinstruction.
//		}
//	}
//
///*
//	while (c && infile >> cc)
//	{
//		if (comment && cc == '*')
//		{
//			if (!(infile >> cc))
//				break;
//
//			if (cc == '/')
//				comment = false;
//		}
//
//		if (comment)
//			continue;
//
//		switch (cc)
//		{
//			case '/':
//				if (!(infile >> cc))
//				{
//					c = false;
//
//					break;
//				}
//
//				switch (cc)
//				{
//					case '/':
//						// Skip the whole current line.
//						std::getline (infile, token);
//
//						break;
//
//					case '*':
//						comment = true;
//				}
//
//				break;
//
//			case '*':
//		}
//
//		if (!serialize)
//			processor = random_processor ();
//	}
//	
//*/
////	_parser.parse (file_name, instructions);
//	infile.close ();
//	threads.begin ();
//
//	while (! instructions.empty ())
//	{
//		//instructions.begin ();	// Update the "current".
//
//		//enqueue (instructions.current (), instructions.current ().processor);
//		//enqueue (instructions.front (), instructions.front ().processor);
//		enqueue (instructions.front ());
//		//instructions.dequeue ();
//		instructions.pop ();
//	}
//	
//	return true;
//}

//LIB::mathematics::numbers::natural LIB::cluster::processor::get_next_instruction (void)
//{
//	return 1;
//}
//
//void LIB::cluster::processor::increment_next_instruction (void)
//{
//	
//}

// Each processor/thread would be executing this for the duration of the this object, when there are instructions to be run.
void LIB::cluster::processor::perform (void)
//void LIB::cluster::processor::operator () (void)
{
	/*
		This is the concept:

		While there are instructions to be performed, perform them;
		otherwise, wait (preferably, without consuming any resources) for any instruction to come.
	*/
	
	//threads.begin ();
	//++ threads;
	//boost::thread::id id = threads.current_key ();
	
	std::string next_instruction;
	
	// boost::thread::id id = boost::this_thread::get_id ();	// Select a random processor from the avaiable ones.
	//std::cout << id << " Running once..." << std::endl;

	//LIB::mathematics::numbers::natural id = 1;
	// LIB::cluster::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
	//std::cout << id;

	//LIB::cluster::processor::instructions instructions_temp;
	// LIB::cluster::processor::instructions current_instructions;
	// LIB::mathematics::numbers::natural index, size;

	while (running_main)
	{
		// Wait if we are paused;
		pause ();
		
		//LIB::parse <LIB::cluster::processor::instructions> (memory.get ("queue"), instructions_temp);
		//current_instruction = pop ();

		//current_instructions._instructions.begin ();
		//for (index = 0, size = current_instructions._instructions.size (); index < size; ++ index, ++ current_instructions._instructions)
		//{
		//	if (!running_main)
		//		break;

		//	//process -> pause ();
		//	pause ();

		//	_do (current_instructions._instructions.current ());
		//}
		//if (memory_.search ("0_0"))
		next_instruction = memory_.get ("NI");
		if (! next_instruction.empty ())
		{
			instruction instruction_;
			
			instruction_ = dequeue ();
			
			// If execution succeeded.
			if (instruction_.action != operation::none && execute (instruction_))
			{
				// To be done: if this instruction has already been processed by another processor, and if it has possibly already been advanced...
				// If this instruction has not already been dequeued by another processor, and if it has not already been advanced.
				if (next_instruction == memory_.get ("NI"))
				{
					// Set the Next Instruction to point to the next instruction.
					memory_.set ("NI", instruction_.next_instruction);

					// Remove the instruction from the queue.
					memory_.unset (next_instruction /* The instruction that has just been processed. */);

					// If this is the last instruction, reset the queue to be empty.
					if (instruction_.next_instruction.empty ())
					{
						memory_.set ("LI", "");
						//memory_.set ("NI", "");
					}
				}
			}
		}
		//while (! instructions_temp._instructions.empty ())
		//{
		//	if (!running_main)
		//		break;

		//	//process -> pause ();
		//	pause ();

		//	//std::cout << id << " Running..." << std::endl;

		//	//_do (process -> queue.current ());
		//	_do (instructions_temp._instructions.front ());

		//	//process -> queue.dequeue ();
		//	 instructions_temp._instructions.pop ();
		//}
	}
}

bool LIB::cluster::processor::execute (LIB::cluster::processor::instruction instruction_)
{
	switch (instruction_.action)
	{
		case LIB::cluster::processor::operation::addition:
		case LIB::cluster::processor::operation::substraction:
		case LIB::cluster::processor::operation::multiplication:
		case LIB::cluster::processor::operation::division:
		case LIB::cluster::processor::operation::modulo:
		case LIB::cluster::processor::operation::exponentiation:
			// For variable variables.
			while (((std::string) instruction_.inputs [0]) [0] == '$')
			{
				instruction_.inputs [0] = memory_.get (instruction_.inputs [0]);
			}
			
			while (((std::string) instruction_.inputs [1]) [0] == '$')
			{
				instruction_.inputs [1] = memory_.get (instruction_.inputs [1]);
			}
			
			switch (instruction_.action)
			{
				case LIB::cluster::processor::operation::addition:
					return memory_.set (instruction_.output, (LIB::NAME_V) instruction_.inputs [0] + instruction_.inputs [1]);
					
					//break;

				case LIB::cluster::processor::operation::substraction:
					return memory_.set (instruction_.output, instruction_.inputs [0] - instruction_.inputs [1]);
					
					//break;

				case LIB::cluster::processor::operation::multiplication:
					return memory_.set (instruction_.output, (LIB::NAME_V) instruction_.inputs [0] * (LIB::NAME_V) instruction_.inputs [1]);
					
					//break;

				case LIB::cluster::processor::operation::division:
					return memory_.set (instruction_.output, (LIB::NAME_V) instruction_.inputs [0] / instruction_.inputs [1]);
					
					//break;

				case LIB::cluster::processor::operation::modulo:
					return memory_.set (instruction_.output, (LIB::NAME_V) instruction_.inputs [0] % instruction_.inputs [1]);
					
					//break;
				case LIB::cluster::processor::operation::exponentiation:
					return memory_.set (instruction_.output, (LIB::NAME_V) (instruction_.inputs [0] ^ instruction_.inputs [1]));
					
					//break;
			}

			//break;

		case LIB::cluster::processor::operation::output:
			if ((std::string) instruction_.inputs [0] == "endl")
			{
				std::cout << std::endl;
			}
			else if ((std::string) instruction_.inputs [0] == "tab")
			{
				std::cout << '\t';
			}
			else if (((std::string) instruction_.inputs [0]) [0] == '$')
			{
				//while (((std::string) _instruction.inputs [0]) [0] == '$')
				//{
				//	_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
				//}

				std::string op = memory_.get (instruction_.inputs [0]);
				std::cout << op;
			}
			else
			{
				std::cout << instruction_.inputs [0];
			}
			
			return true;
			//break;

		case LIB::cluster::processor::operation::modulus:
			return memory_.set (instruction_.output, (LIB::NAME_V) LIB::tools::modulus (instruction_.inputs [0]));
			
			//break;

		case LIB::cluster::processor::operation::complement:
			return memory_.set (instruction_.output, (LIB::NAME_V) LIB::tools::complement (instruction_.inputs [0]));
			
			//break;

		case LIB::cluster::processor::operation::assignment:
			while (((std::string) instruction_.inputs [0]) [0] == '$')
			{
				instruction_.inputs [0] = memory_.get (instruction_.inputs [0]);
			}

			return memory_.set (instruction_.output, instruction_.inputs [0]);
			
			//break;
		//default:
		//	return LIB::mathematics::numbers::default;
	}
	
	return true;
}

/*
bool LIB::cluster::processor::enqueue (const LIB::cluster::processor::instruction _instruction, LIB::cluster::memory & _memory)
{

}
*/
LIB::mathematics::numbers::natural LIB::cluster::processor::random_processor ()
{
	//LIB::mathematics::numbers::natural size = threads.size ();

	//return size >= 2 ? LIB::random (size, 1) : 1;
	return processors.generate ();
}

LIB::cluster::processor::instruction LIB::cluster::processor::dequeue (void)
{
	//instruction instruction_;	// Fallback variable.
	
/*
	std::string next_instr;
	
	// Get the next instruction:
	next_instr = memory_.get ("NI");
	
	// If there is an instruction available.
	//if (instruction_.action != operation::none)
	if (! next_instr.empty ())
	{
		instruction_ = memory_.get (next_instr);
		
		// If the instruction is valid.
		//if (instruction_.action != operation::none)
		//{
			//// Set the Next Instruction to point to the next instruction.
			//memory_.set ("NI", instruction_.next_instruction);
			
			//// If this is the last instruction, reset the queue to be empty.
			//if (instruction_.next_instruction.empty ())
			//{
			//	memory_.set ("LI", "");
			//	memory_.set ("NI", "");
			//}
		//}
	}
*/
	return (instruction) memory_.get (memory_.get ("NI"));
	
	//return instruction_ = memory_.get (memory_.get ("NI"));
	
	//instruction_ = memory_.get (memory_.get ("NI"));
	//return instruction_;
/*	
	LIB::cluster::processor::instruction instruction_;	// Fallback variable.
	LIB::NAME_V instruction_key, instruction_subkey;
	
	instruction_key = instruction_subkey = 0;
	
	if (memory_.search ("instruction_queue_vacant"))
	{
		while (memory_.get ("instruction_queue_vacant") != "true")
		{
			// Wait.
		}
	}

	if (! memory_.set ("instruction_queue_vacant", "false"))
		return instruction_;

	//std::cout << ((std::string) instruction_key + "_" + ((std::string) instruction_subkey)) << std::endl;

	if (memory_.search (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey)))
	{
		instruction_ = memory_.get (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey));

		assert (memory_.unset (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey)));

		//while (_instructions._instructions.size () > 0)
		//{
		//	memory.set ((std::string) instruction_key + "_" + (std::string) instruction_subkey, _instructions._instructions.front ());

		//	_instructions._instructions.pop ();
		//}

		do
		{
			//assert (mem.rename (instruction_key, instruction_key - 1));

			instruction_subkey = 0;

			while (memory_.search (((std::string) instruction_key) + "_" + ((std::string) (++ instruction_subkey))))
			{
				assert (memory_.rename (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey), ((std::string) instruction_key) + "_" + ((std::string) (instruction_subkey - 1))));
			}

			++ instruction_key;
		}
		while (memory_.search (((std::string) instruction_key) + "_0"));

		//++ instruction_key;
		//instruction_subkey = 1;
	}
	else
	{
		return instruction_;
	}
*/
/*	
	if (mem.search ((std::string) instruction_key + "_" + instruction_subkey))
	{
		assert (mem.rename ((std::string) instruction_key + "_" + instruction_subkey, instruction_key));

		//_instruction = memory.get (instruction_key);

		while (mem.search ((std::string) instruction_key + "_" + (++ instruction_subkey)))
		{
			assert (mem.rename ((std::string) instruction_key + "_" + instruction_subkey, (std::string) instruction_key + "_" + (instruction_subkey - 1)));
		}
	}
	else
	{
		while (mem.search (instruction_key))
		{
			assert (mem.rename (instruction_key, instruction_key - 1));

			instruction_subkey = 1;

			while (mem.search ((std::string) instruction_key + "_" + instruction_subkey))
			{
				assert (mem.rename ((std::string) instruction_key + "_" + instruction_subkey, (std::string) (instruction_key - 1) + "_" + instruction_subkey));

				++ instruction_subkey;
			}

			++ instruction_key;
		}
	}
*/
/*
	memory_.set ("instruction_queue_vacant", "true");	// Release the lock.

	return instruction_;
*/
}

bool LIB::cluster::processor::enqueue (LIB::cluster::processor::instructions instructions_)
{
	//unsigned long long int c = instructions_.instructions_.size ();
	//for (unsigned long long int i = 0; i < c; ++ i)
	while (! instructions_.instructions_.empty ())
	{
		if (! enqueue (instructions_.instructions_.front ()))
		{
			return false;
		}
		
		instructions_.instructions_.pop ();
	}
	
	return true;
/*	
	LIB::NAME_V instruction_key, instruction_subkey;
	instruction_key = instruction_subkey = 0;
	//std::string val;
	
	if (memory_.search ("instruction_queue_vacant"))
	{
		while (memory_.get ("instruction_queue_vacant") != "true")
		{
			// Wait.
		}
	}
	
	if (!memory_.set ("instruction_queue_vacant", "false"))
		return false;
	
	// Find the key:
	while (memory_.search (((std::string) instruction_key) + "_0"))
	{
		++ instruction_key;
	}
	
	//// Find the sub-key:
	//while (memory.search ((std::string) instruction_key + "_" + (std::string) instruction_subkey))
	//{
	//	++ instruction_subkey;
	//}
	
	//// Enque the first instruction:
	//if (! mem.set (instruction_key, _instructions._instructions.front ()))
	//	return false;
	
	//_instructions._instructions.pop ();
	
	// Enqueue the rest of the instructions:
	while (instructions_.instructions_.size () > 0)
	{
		assert (memory_.set (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey), instructions_.instructions_.front ()));

		instructions_.instructions_.pop ();
		++ instruction_subkey;
	}
	
	assert (memory_.set ("instruction_queue_vacant", "true"));
	
	return true;
*/ 
}

bool LIB::cluster::processor::enqueue (LIB::cluster::processor::instruction instruction_)
{
	instruction instr;
	std::string last_instr, next_instr;
	
	retry:
	
	last_instr = memory_.get ("LI");
	//next_instr = next_available_instruction_location ();	// The next available instruction should be obtained as late as possible, just before it would be used.
	
	// If the queue has not been empty, set the last queued instruction's "next_instruction" to refer to this one.
	//if (! last_instr.empty ())
	//{
		//// "last_instruction" is a reference.
		//last_instr = memory_.get (last_instruction);
		
		if (! last_instr.empty ())
		{
			// Hope that the instruction is not dequeued while we are here, by another processor.
			
			//memory_.set (last_instr, "ABC");
			instr = memory_.get (last_instr);
			
			// If this is a valid instruction.
			if (instr.action != operation::none)
			{
				next_instr = next_available_instruction_location ();
				instr.next_instruction = next_instr;
				// To be fixed: if this instruction has already been dequeued, in the meantime, by another process, still set the following?
				if (last_instr == memory_.get ("LI"))	// In case another process changed/set this.
				{
					memory_.set (last_instr, instr);
					//memory_.set ("NI", "0");
				}
				else
				{
					goto retry;
				}
			}
		}
		else
		// The queue has been empty. Set the Next Instruction to this one.
		{
			next_instr = next_available_instruction_location ();
			
			if (! memory_.set ("NI", next_instr))
			{
				return false;
			}
		}
	//}
	
	// Set the Last Instruction which was enqueued to this one.
	//last_instruction = next_instr;
	if (! memory_.set ("LI", next_instr))
	{
		return false;
	}
	
	return memory_.set (next_instr, instruction_);
	
	
/*
	LIB::NAME_V instruction_key, instruction_subkey;
	instruction_key = instruction_subkey = 0;
	
	if (memory_.search ("instruction_queue_vacant"))
	{
		while (memory_.get ("instruction_queue_vacant") != "true")
		{
			// Wait.
		}
	}
	
	if (memory_.set ("instruction_queue_vacant", "false"))
		return false;
	
	while (memory_.search (((std::string) instruction_key) + "_0"))
	{
		++ instruction_key;
	}
	
	memory_.set (((std::string) instruction_key) + "_0", instruction_);
	
	return memory_.set ("instruction_queue_vacant", "true");
*/
}

std::string LIB::cluster::processor::next_available_instruction_location (void)
{
	LIB::NAME_V next_instr;
	
	if (memory_.get ("LI").empty ())
	{
		next_instr = "0";
	}
	else
	{
		next_instr = 0;
		
		while (memory_.search (next_instr))
		{
			++ next_instr;
		}
	}
	
	return next_instr;
}
