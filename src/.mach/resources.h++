#ifndef __RESOURCES
#define __RESOURCES

/*
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
#include "../containers/variable.h++"
#include "../tools.h++"
#include "memory.h++"
#include "../serialization.h++"
*/
#include "../containers/array.h++"
#include "../mathematics.h++"
#include "device.h++"

namespace LIB
{
	namespace machine
	{
		class resources
		{
			public:
				class resource //: public LIB::machine::devices::device
				{
					public:
						//virtual std::string get (const std::string &/* name*/) = 0;
						//virtual bool set (const std::string &/* name*/, const std::string &/* data*/) = 0;
						
						resource (void);
						resource (const resource &);
						//resource (const devices::device &);
						~resource (void);
						
						device * dev;
						// More things?
						//machine?
						enum type
						{
							memory,
							processor,
							input, //sensor,
							output,
							other
						};

						type t;
				};
				
				//resources ();
				LIB::NAME_A <resource> rscs;
				//LIB::NAME_A <resource *> rscs;
				
				//mpi;
		};
	}
}

#endif
