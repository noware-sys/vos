#ifndef PROCESSOR
#define PROCESSOR

// Boost:
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

// This class:
#include "default.hpp"
#include "mathematics.hpp"
#include "containers/array.hpp"
#include "containers/variable.hpp"
#include "pointer.hpp"

namespace LIB
{
	namespace cluster
	{
		class processor
		{
			public:
				enum operation
				{
					and,
					or,
					add,
					substract,
					multiply,
					divide,
					modulo,
					modulus
				};

				struct instruction
				{
					instruction (void);

					mathematics::numbers::real inputs [2];
					operation _operation;
				};

				// Computational platform.
				class platform
				{
					protected:
						bool running;
						boost::mutex running_mutex;
						boost::condition_variable running_condition_variable;

					public:
						platform (void);
						//~ platform (void);
						
						// Non-blocking:
						// To control the state.
						void run (const bool = true);

						// Blocking:
						// To pause the worker/target thread until it is set to `run (true)` again.
						void pause (void);

						boost::thread * thread;
						// LIB::Pointer <boost::thread> thread;
						//LIB::NAME_A <LIB::cluster::processor::instruction, LIB::mathematics::numbers::natural> queue;
				};

			protected:
				//LIB::NAME_A <LIB::cluster::processor::platform, boost::thread::id> threads;
				LIB::NAME_A <LIB::cluster::processor::platform, mathematics::numbers::natural> threads;
				LIB::mathematics::numbers::real _do (const LIB::cluster::processor::instruction) const;
				void pause (void);
				LIB::NAME_A <LIB::mathematics::numbers::real, mathematics::numbers::natural> _results;

			public:
				processor (void);
				~processor (void);

				void run (const bool = true);

				// Queue instructions.
				bool enqueue (const instruction);
				//void initialize (std::string);
				//LIB::mathematics::numbers::real Do (const LIB::cluster::processor::instruction) const;
				
				// Results:
				bool result_exists (const LIB::mathematics::numbers::natural);
				mathematics::numbers::real get_result (const LIB::mathematics::numbers::natural);
				mathematics::numbers::real delete_result (const LIB::mathematics::numbers::natural);
				//bool run; // initialise to false in constructor!

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

#endif PROCESSOR
