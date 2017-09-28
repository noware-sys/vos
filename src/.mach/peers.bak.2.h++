#ifndef PEERS
#define PEERS

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
#include "../default.hpp"
#include "../mathematics.hpp"
#include "../containers/array.hpp"
#include "../containers/variable.hpp"
#include "../tools.hpp"
#include "memory.hpp"
#include "../serialization.hpp"

namespace LIB
{
	namespace cluster
	{
		class peers
		{
			public:
				class delays
				{
					public:
						delays (void);
						//~delays (void);
						
						LIB::mathematics::numbers::natural
							request,	// Time to delay between requests (in microseconds).
							response,	// Time to wait for a peer to respond to a probing request, before it is considered offline (in microseconds).
							discovery	// Time to delay between discovery probes.
						;
				};
				
				delays timeouts;
				
				peers (void);
				
			protected:
				LIB::NAME_A <peer/*, LIB::mathematics::numbers::natural*/> peers;
				
				void listen (const std::string &/* message*/);
				void request (void);
				void respond (void);
				void discover (void);
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
