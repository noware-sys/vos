#ifndef PROCESSOR
#define PROCESSOR

// Standard:
#include <string>
#include <queue>
#include <stack>

// Boost:
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
#include <boost/date_time/posix_time/posix_time.hpp>

// This class:
#include "../../containers/array.h++"
#include "../../mathematics.h++"
#include "../../default.h++"
#include "../../containers/variable.h++"
#include "../../tools.h++"
#include "memory.h++"
#include "../../serialization.h++"

namespace LIB
{
	namespace cluster
	{
		//public:
			class processor
			{
				public:
					//class parser
					//{
					//	protected:
					//		// State handlers:
					//		void comment ();

					//		std::queue <LIB::cluster::processor::instruction> instructions;
					//	public:
					//		void parse (const std::string, std::queue <LIB::cluster::processor::instruction> &);
					//};
				
					enum class operation
					{
						none,
						// For controlling the flow of the execution:
						//and, intersection,
						//or, union,
						addition,
						substraction,
						multiplication,
						division,
						modulo,
						modulus,
						complement,
						exponentiation,
						assignment,
						output	// Or "echo".
					};
				
					class instruction
					{
						protected:
							friend class boost::serialization::access;
							// friend std::ostream & operator << (std::ostream &, const instruction &);
						
							template <typename Archive>
							void serialize (Archive &, const unsigned int &);
						public:
							instruction (void);
							instruction (const instruction &);
							instruction (const std::string &);
							/*
								ID: "1"
							*/
						
							operator std::string (void);
							// operator instruction (void);
						
							// Overwrite this instruction by the one parsed from the string.
							instruction operator = (std::string);
							instruction operator = (const instruction &);


							// bool active;	// If the instruction should be processed.
							// bool processing;	// If there is a processor processing the instruction.

							//std::string instructions [2];
							/*
								instructions [0] == Prerequisite instruction, if any.
								instructions [1] == Next instruction, if any.
							*/
							// std::string prerequisite_instruction;
							std::string next_instruction;
							// std::string id;

							//mathematics::numbers::real inputs [2];
							LIB::NAME_V inputs [2];
							//std::string inputs [2];
							//LIB::NAME_V output;
							std::string output;

							operation action;
						
							// std::string user;
							LIB::mathematics::numbers::natural user;	// The ID of the user who owns this instructions; who enqueued this instruction.
							//LIB::mathematics::numbers::natural processor;
					};

					class instructions
					{
						protected:
							friend class boost::serialization::access;
							// friend std::ostream & operator << (std::ostream &, const instruction &);

							template <typename Archive>
							void serialize (Archive &, const unsigned int &/* version*/);
						public:
							instructions (void);
							instructions (const instructions &);
							/*
								ID: "1"
							*/

							operator std::string (void);
							// operator instruction (void);

						
							// Overwrite this set of instructions by the one parsed from the string.
							instructions operator = (const std::string &);
							instructions operator = (const instructions &);

							// bool active;	// If the instruction should be processed.
							// bool processing;	// If there is a processor processing the instruction.

							//std::string instructions [2];
							/*
								instructions [0] == Prerequisite instruction, if any.
								instructions [1] == Next instruction, if any.
							*/
							// std::string prerequisite_instruction;
							//std::string next_instruction;
							//std::string id;

							////mathematics::numbers::real inputs [2];
							// LIB::NAME_A <LIB::cluster::processor::instruction, LIB::mathematics::numbers::natural> _instructions;
							std::queue <LIB::cluster::processor::instruction> instructions_;
							////std::string inputs [2];
							////LIB::NAME_V output;
							//std::string output;
							//operation _operation;

							// std::string user;
							////LIB::mathematics::numbers::natural processor;
					};
				
					//class queue
					//{
					//	protected:
					//		friend class boost::serialization::access;
					//		// friend std::ostream & operator << (std::ostream &, const instruction &);

					//		template <typename archive>
					//		void serialize (archive &, const unsigned int);
					//	public:
					//		queue (void);
					//		~queue (void);

					//		std::queue <LIB::cluster::processor::instructions> _queue;

					//		operator std::string (void) const;
					//		queue operator = (const std::string &);
					//};

					//class results
					//{
					//	protected:
					//		friend class boost::serialization::access;

					//		template <typename std::string>
					//		void serialize (std::string &/*, const unsigned int version*/);
					//};
				
					// Computational platform.
					class process
					{
						//protected:
							//bool ended;

						public:
							process (void /*const bool & = false*/);
							~ process (void);
						
							// Non-blocking:
							// To control the state.
							//void run (const bool = true);

							// Blocking:
							// To pause the target/worker thread until it is set to `run ([true])` again.
							//void pause (void);

							boost::thread * thread;
							// LIB::Pointer <boost::thread> thread;
							//LIB::NAME_A <LIB::cluster::processor::instruction, LIB::mathematics::numbers::natural> queue;
							std::queue <LIB::cluster::processor::instruction> queue;
					};

				protected:
					bool running, running_main;
					//std::string last_instruction;	// Name of the location of the last instruction which has been enqueued.
					std::string next_available_instruction_location (void);	// Get the next available name for an instruction.
				
					boost::mutex running_mutex;
					boost::condition_variable running_condition_variable;
				
					LIB::NAME_A <LIB::cluster::processor::process, boost::thread::id> threads;
					//LIB::NAME_A <LIB::cluster::processor::platform, mathematics::numbers::natural> threads;
					//LIB::mathematics::numbers::real _do (const LIB::cluster::processor::instruction) const;
					void perform (void);
					bool execute (LIB::cluster::processor::instruction);
					void pause (void);
					//LIB::NAME_A <LIB::mathematics::numbers::real, mathematics::numbers::natural> _results;

					// Get a next N'th random processor from the available ones.
					LIB::mathematics::numbers::natural random_processor (void);
					LIB::tools::randomizer processors;
					//void dummy (void);

					// LIB::mathematics::numbers::natural get_next_instruction (void);
					// void increment_next_instruction (void);
					//boost::asio::io_service io;
					//boost::asio::deadline_timer * timer;
				
					//LIB::mathematics::numbers::natural timeout;

					// LIB::cluster::processor::queue _queue;
					//LIB::cluster::processor::instructions _queue;

				public:
					LIB::cluster::processor::instruction dequeue (void);
					bool enqueue (LIB::cluster::processor::instruction);
					bool enqueue (LIB::cluster::processor::instructions);
				
					processor (const bool & /* Run. */ = false);
					~processor (void);
				
					//void operator () (void);
					void run (const bool & = true);
					//std::string execute (LIB::cluster::processor::instruction);
				
					// Queue instructions.
					//bool enqueue (LIB::cluster::processor::instructions);
					// bool enqueue (const LIB::cluster::processor::instruction &, LIB::mathematics::numbers::natural /* Processor index. */);
					//bool enqueue (const std::string & /* File name. */);
					// bool enqueue (const LIB::cluster::processor::instruction, LIB::cluster::memory &);
					//void initialize (std::string);
					//LIB::mathematics::numbers::real Do (const LIB::cluster::processor::instruction) const;
					//LIB::NAME_V Do (const LIB::cluster::processor::instruction) const;
					LIB::cluster::memory memory_;
					//bool parse (const std::string);
					// Results:
					//bool result_exists (const LIB::mathematics::numbers::natural);
					//mathematics::numbers::real get_result (const LIB::mathematics::numbers::natural);
					//mathematics::numbers::real delete_result (const LIB::mathematics::numbers::natural);
			};
	}
}

/*
LIB::Cluster::Platform::Platform (void)
{
	thread = NULL;
}

LIB::Cluster::Platform::Platform (void)
{
	delete thread;
}
*/

#endif
