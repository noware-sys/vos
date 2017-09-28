//#pragma once
//#ifndef _DEVICE_HPP
//#define _DEVICE_HPP

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
*/
// This class:

// #include "../default.h++"
//#include "resource/index-pre.h++"

/*#include "../mathematics.h++"
#include "../containers/array.h++"
#include "../containers/variable.h++"
#include "../tools.h++"
#include "memory.h++"
#include "../serialization.h++"
*/
//#include "../cluster/machine.h++"
/*
namespace LIB
{
	namespace machine
	{
		//namespace devices
		//{
*/			class device //: noware::misc::instance
			{
				public:
					//#include ".device/index.h++"
					#include ".device/*.hxx"
					//friend class LIB::cluster::machine;
					
					device (void);
					//device (const device &);
					virtual ~device (void);
					
					//virtual const device & operator = (const device &);
					
					/*
					enum location	// location, distance
					{
						literal,	// literal, local
						reference	// reference, remote
					};
					*/
					/*
					enum type
					{
						memory,		// memory, storage
						processor,	// processor, process, processing
						network,
						//io,
						input,			// in, detector, sensor
						output,
						other
					};
					*/
					//type t;
					//location loc;
					
					//const location & get_location (void) const;
					//const type & get_type (void) const;
					virtual const bool operator == (const device &/* other*/) const/* = 0*/;
					//virtual const bool run (const bool &/* active(_running)_state*/ = true)/* = 0*/;
					//virtual const bool active/*ning*/ (void) const;
					
					//static const noware::net::cluster cluster (void);
					
				protected:
					//type t;
					//location l;
					//noware::container::array <type/*, noware::math::numbers::natural*/> types;
					noware::container::array <> types;
					
					static unsigned short int instance_count;
					//static noware::misc::instance instance;
					
					static noware::net::cluster * cluster;
					
					
					// Main message receiver (delegator):
					//boost::function <void (const noware::container::set <> &/* message*/, const noware::container::set <> &/* remote_endpoint*/)> * handler;
					void receive (const noware::container::set <> &/* message*/, const noware::container::set <> &/* remote_endpoint*/) const;
					
					// Message receivers:
					//noware::container::array <boost::function <void (const noware::container::set <> &/* message*/, const noware::container::set <> &/* remote_endpoint*/)>, type> receivers;
					noware::container::array <boost::function <void (const noware::container::set <> &/* message*/, const noware::container::set <> &/* remote_endpoint*/)>> receivers;
					
					
					// Message transmitters:
					const bool transmit (const noware::container::set <> &/* message*/, const noware::container::array <noware::math::numbers::natural/*, noware::math::numbers::natural*/> &/* nodes*/) const;
					const bool broadcast (const noware::container::set <> &/* message*/) const;
					
					//bool _active;
					// LIB::cluster::machine * machine;	// Needed?
				//public:
				//	#include ".device/postinnerindex.h++"
			};
/*		//}
	}
}
*/
//#include "device.c++"
/*
#ifndef _DEVICE_CPP
#define _DEVICE_CPP

LIB::machine::device::device (void)
{
}

LIB::machine::device::device (const device & other)
{
	* this = other;
}

const LIB::machine::device & LIB::machine::device::operator = (const device & other)
{
	t = other.t;
	
	return * this;
}

#endif
*/

//#include "postindex.h++"

//#endif

