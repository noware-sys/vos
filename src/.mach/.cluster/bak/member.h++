#pragma once

#include <string>
#include <map>
//#include <list>
//#include <omp.h>

//#include <boost/any.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/system/error_code.hpp>
//#include <boost/system/system_error.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
#include <boost/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

#include "../default.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
//#include "machine.h++"
#include "paths.h++"
//#include "../machine/device.h++"
//#include "../machine/resource.h++"
//#include "../machine/resources.h++"
#include "../containers/array.h++"
//#include "../containers/variable.h++"
//#include "../containers/entity.h++"
//#include "../cluster.h++"

//#include "../communication/messaging.h++"
// #include "../network/mpi.h++"
#include "../network/ip.h++"

namespace LIB
{
	namespace cluster
	{
			class member
			{
				public:
					friend class boost::serialization::access;
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename archive>
					//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename archive>
					//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					member (void);
					member (const member &);
					~member (void);
					
					const member & operator = (const member &);
					const bool operator == (const member &) const;
					// Get the ID.
					//const LIB::mathemathics::numbers::natural & id (void) const;
					
					//LIB::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> addresses;
					LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> addresses;
					LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;
					//LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural> paths;
					//LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> paths;
					LIB::cluster::paths paths;
					//LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> network_paths;
					
					/*
						State of availability :
						true : available
						false : unresponsive, timing out
					*/
					//bool available;	// available availability state
					static const LIB::mathematics::numbers::natural default_keepalive;
					LIB::mathematics::numbers::natural keepalive;
					void function_timeout (LIB::containers::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> &, const LIB::mathemathics::numbers::natural &/* key*/, const LIB::mathemathics::numbers::natural &/* timeout (total)*/) const;
					//LIB::tools::randomizer randomizer;
				protected:
					boost::thread * thread_timeout;
					//LIB::mathematics::numbers::natural _id;
					
					// Generate unique ID.
					//const LIB::mathemathics::numbers::natural generate_id/*distinguish/uniquify*/ (void) const;
			};
	}
}

//#include "../cluster.h++"
//#include "machine.h++"
