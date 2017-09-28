//#include <vector>
#include <sstream>
//#include <fstream>
#include <sstream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "processor.hpp"

// Computational platform.

LIB::cluster::processor::instruction::instruction (void)
{
	active = true;
	processing = false;

	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";

	user = "Guest";	// The default user.
}

template <typename Archive>
void LIB::cluster::processor::instruction::serialize (Archive & archive, const unsigned int version)
{
	archive & processing;

	//destination & instructions [0];
	//destination & instructions [1];
	archive & next_instruction;

	archive & inputs;
	//archive & inputs [0];
	//archive & inputs [1];

	archive & output;
	
	archive & _operation;

	archive & user;
}

LIB::cluster::processor::instruction::operator std::string (void) const
{
	return LIB::serialize <LIB::cluster::processor::instruction> (*this);
}

LIB::cluster::processor::instruction LIB::cluster::processor::instruction::operator = (const std::string & serial)
{
	LIB::parse <LIB::cluster::processor::instruction> (serial, *this);

	return *this;
}

LIB::cluster::processor::queue::queue (void)
{

}

LIB::cluster::processor::queue::~queue (void)
{

}

template <typename Archive>
LIB::cluster::processor::queue::serialize (Archive & archive, const unsigned int version)
{
	archive & _queue;
}

LIB::cluster::processor::queue::operator std::string (void) const
{
	return LIB::serialize <LIB::cluster::processor::queue> (*this);
}

LIB::cluster::processor::queue LIB::cluster::processor::queue::operator = (const std::string & serial)
{
	LIB::parse <LIB::cluster::processor::queue> (serial, *this);

	return *this;
}

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

LIB::cluster::processor::processor (const bool & _run)
{
	// Initialize random seed:
	//srand ((unsigned) time (NULL));

	//timeout = 4;
	running_main = true;

	run (_run);

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

	if (! memory.search ("queue"))	// If "queue" does not exist.
		memory.set ("queue", _queue);

	//temp_platform.thread = NULL;

	LIB::cluster::processor::process temp_platform;
	mathematics::numbers::natural n = omp_get_num_procs ();
	//threads.begin ();	// Reset the iterator to the beginning (for *this.enqueue ()).

	for (mathematics::numbers::natural i = 0; i < n; ++ i/*, ++ threads*/)
	{
		temp_platform.thread = new boost::thread (boost::bind (& LIB::cluster::processor::perform, this));
		//temp_platform.thread = new boost::thread (*this);

		threads [temp_platform.thread -> get_id ()] = temp_platform;
	}

	// This is important, so that its destructor's body does not delete a needed thread.
	temp_platform.thread = NULL;

	processors.max (threads.size ());

}

LIB::cluster::processor::~processor (void)
{
	running_main = false;

	/*
		Complete any remaining instructions in the queue,
		so that the threads can be joined
		and so that they do not remain blocked, if they happen to be paused.
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

	boost::thread::id id = boost::this_thread::get_id ();	// Select a random processor from the avaiable ones.
	//std::cout << id << " Running once..." << std::endl;

	//LIB::mathematics::numbers::natural id = 1;
	LIB::cluster::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
	//std::cout << id;

	while (running_main)
	{
		pause ();

		while (!process -> queue.empty ())
		{
			if (!running_main)
				break;

			//process -> pause ();
			pause ();

			//std::cout << id << " Running..." << std::endl;

			//_do (process -> queue.current ());
			_do (process -> queue.front ());

			//process -> queue.dequeue ();
			process -> queue.pop ();
		}
	}
}

void LIB::cluster::processor::_do (LIB::cluster::processor::instruction _instruction)
{
	switch (_instruction._operation)
	{
		case LIB::cluster::processor::operation::add:
		case LIB::cluster::processor::operation::substract:
		case LIB::cluster::processor::operation::multiply:
		case LIB::cluster::processor::operation::divide:
		case LIB::cluster::processor::operation::modulo:
		case LIB::cluster::processor::operation::exponentiation:
			while (((std::string) _instruction.inputs [0]) [0] == '$')
			{
				_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
			}

			while (((std::string) _instruction.inputs [1]) [0] == '$')
			{
				_instruction.inputs [1] = memory.get (_instruction.inputs [1]);
			}

			switch (_instruction._operation)
			{
				case LIB::cluster::processor::operation::add:
					memory.set (_instruction.output, (LIB::NAME_V) _instruction.inputs [0] + _instruction.inputs [1]);
					
					break;

				case LIB::cluster::processor::operation::substract:
					memory.set (_instruction.output, _instruction.inputs [0] - _instruction.inputs [1]);
					
					break;

				case LIB::cluster::processor::operation::multiply:
					memory.set (_instruction.output, (LIB::NAME_V) _instruction.inputs [0] * (LIB::NAME_V) _instruction.inputs [1]);
					
					break;

				case LIB::cluster::processor::operation::divide:
					memory.set (_instruction.output, (LIB::NAME_V) _instruction.inputs [0] / _instruction.inputs [1]);
					
					break;

				case LIB::cluster::processor::operation::modulo:
					memory.set (_instruction.output, (LIB::NAME_V) _instruction.inputs [0] % _instruction.inputs [1]);
					
					break;
				case LIB::cluster::processor::operation::exponentiation:
					memory.set (_instruction.output, (LIB::NAME_V) (_instruction.inputs [0] ^ _instruction.inputs [1]));
					
					//break;
			}

			break;

		case LIB::cluster::processor::operation::output:
			if ((std::string) _instruction.inputs [0] == "endl")
			{
				std::cout << std::endl;
			}
			else if (((std::string) _instruction.inputs [0]) [0] == '$')
			{
				//while (((std::string) _instruction.inputs [0]) [0] == '$')
				//{
				//	_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
				//}

				std::cout << memory.get (_instruction.inputs [0]);
			}
			else
			{
				std::cout << _instruction.inputs [0];
			}

			break;

		case LIB::cluster::processor::operation::modulus:
			memory.set (_instruction.output, (LIB::NAME_V) LIB::modulus (_instruction.inputs [0]));
			
			break;

		case LIB::cluster::processor::operation::complement:
			memory.set (_instruction.output, (LIB::NAME_V) LIB::complement (_instruction.inputs [0]));
			
			break;

		case LIB::cluster::processor::operation::assign:
			while (((std::string) _instruction.inputs [0]) [0] == '$')
			{
				_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
			}

			memory.set (_instruction.output, _instruction.inputs [0]);
			
			//break;
		//default:
		//	return LIB::mathematics::numbers::default;
	}
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
