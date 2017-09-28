#ifndef MEMBER
#define MEMBER

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
#include "../default.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
#include "../containers/array.h++"
#include "../containers/variable.h++"
#include "../tools.h++"
//#include "memory.h++"
#include "resource.h++"
#include "resources.h++"

namespace LIB
{
	class cluster
	{
		public:
			class member
			{
				public:
					member (void);
					//member (const peer &);
					//~member (void);
				//protected:
					// std::string name;
					
					resources _resources;
			};
			/*
			class delays
			{
				public:
					delays (void);
					//~ delays (void);
				
					LIB::mathematics::numbers::natural
						request,	// Time to delay between requests (in microseconds).
						response,	// Time to wait for a peer to respond to a probing request, before it is considered offline (in microseconds).
						discovery	// Time to delay between discovery probes.
					;
			};
			*/
	};
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
